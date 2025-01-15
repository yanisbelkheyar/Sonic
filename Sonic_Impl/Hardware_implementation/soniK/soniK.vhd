--------------------------------------------------------------------------------
--! @file       soniK.vhd
--! @brief      The SoniK PRF.
--!
--! @author     
--------------------------------------------------------------------------------

library work;
    use work.sonic256_pkg.all;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;


entity soniK is
    generic(
        SIZE     : integer := 256;
        nrRounds : integer  := 20
    );
    port (
        rst_i       : in std_logic;
        clk_i       : in std_logic;
        init_i      : in std_logic;
        sqz_i       : in std_logic;
        key_i       : in  std_logic_vector(0 to 255);
        data_i      : in  std_logic_vector(0 to 223);
        data_o      : out std_logic_vector(0 to 255)
    );
end soniK;

architecture rtl of soniK is

    ----------------------------------------------------------------------------
    -- Components
    ----------------------------------------------------------------------------

    component sonic256 is
        generic(
            SIZE    : integer := 256;
            nrRounds : integer  := 20
        );
        port (
            message_i       : in  std_logic_vector(0 to SIZE-1);
            message_o       : out std_logic_vector(0 to SIZE-1);
            clk_i           : in std_logic
        );
    end component;
    
    ----------------------------------------------------------------------------
    -- Internal signal declarations
    ----------------------------------------------------------------------------

    -- datapath
    signal state_reg_s : std_logic_vector(0 to 255);
    -- inputs
    signal init_s, sqz_s : std_logic;
    signal key_s : std_logic_vector(0 to 255);
    signal data_in_s : std_logic_vector(0 to 223);
    -- outputs
    signal data_out_s : std_logic_vector(0 to 255);
    -- internal
    signal perm_in_s, perm_out_s : std_logic_vector(0 to 255);
    signal after_feedfwd_s : std_logic_vector(0 to 255);
    signal expanded_block_s : std_logic_vector(0 to 255);
    ----------------------------------------------------------------------------
    -- Begin
    ----------------------------------------------------------------------------

begin  -- rtl

    -- connections 
    init_s    <= init_i;
    sqz_s     <= sqz_i;
    key_s     <= key_i;
    data_in_s <= data_i;
    data_o    <= data_out_s;

    -- instances
    sonic_i : sonic256
        generic map (
            SIZE   => 256,
            nrRounds => 20
        )
        port map(
            message_i => perm_in_s,
            message_o => perm_out_s,
            clk_i => clk_i
        );
    
    -- computations
    
    -- register value
    main: process( rst_i, clk_i )
    begin
        if (rst_i = active_rst) then
            state_reg_s <= (others => '0');
        elsif rising_edge( clk_i ) then
            if sqz_s = '0' then
                state_reg_s <= after_feedfwd_s;
            else
                state_reg_s <= state_reg_s;
            end if;
        end if;
    end process;
        
    -- input of permutation
    perm_in_s <= key_s when init_s = '1' else 
                 state_reg_s xor expanded_block_s; 
    
    -- apply PrefixFree as in Algorithm 2
    expanded_block_s <= (data_in_s & x"00000000") when sqz_s = '0' else 
                        (data_in_s & x"00000001"); 
    
    -- feed forward
    after_feedfwd_s <= perm_in_s xor perm_out_s;
    
    -- output 
    data_out_s <= after_feedfwd_s when sqz_s = '1' else 
                  (others => '0'); 
    
end rtl;
