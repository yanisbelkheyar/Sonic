--------------------------------------------------------------------------------
--! @file       tb_soniK.vhd
--! @brief      Testbench for the sonicBoom cipher.
--!
--! @author     
--------------------------------------------------------------------------------

library work;
    use work.sonic_pkg.all;
    
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_soniK is
    generic(
        PERIOD : time := 10 ns
    );
end tb_soniK;

architecture behavioral of tb_soniK is

    ----------------------------------------------------------------------------
    -- DUT
    ----------------------------------------------------------------------------

    component soniK is
        generic(
            SIZE     : integer := SIZE;
            nrRounds : integer  := nrRounds
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
    end component;

    ----------------------------------------------------------------------------
    -- Internal signal declarations
    ----------------------------------------------------------------------------
    
    -- input
    signal test_data_i       : std_logic_vector(0 to 223);
    signal test_key_i        : std_logic_vector(0 to 255);
    signal test_init_i       : std_logic;
    signal test_sqz_i        : std_logic;

    signal rst_s : std_logic := '0';
    signal clk_s : std_logic := '0';

    -- output
    signal test_data_o       : std_logic_vector(0 to 255);

    -- expected output
    signal real_data_o       : std_logic_vector(0 to 255);
    
    -- auxiliary
    signal test_error : std_logic := '0';
    signal test_bench_finish : boolean := false;
    
    ----------------------------------------------------------------------------
    -- Begin
    ----------------------------------------------------------------------------

begin

    -- dut instantiation
    u_soniK : soniK
        generic map( 
            SIZE => SIZE,
            nrRounds => nrRounds
        )
        port map(
            rst_i      => rst_s,
            clk_i      => clk_s,
            init_i     => test_init_i,
            sqz_i      => test_sqz_i,
            key_i      => test_key_i,
            data_i     => test_data_i,
            data_o     => test_data_o
        );
  
    -- clock process
    clock : process
        begin
            while (not test_bench_finish ) loop
                clk_s <= not clk_s;
                wait for PERIOD/2;
            end loop;
            wait;
        end process;
    
    -- main process
    main: process
        begin
        
            -- reset
            rst_s        <= '0';
            test_data_i  <= (others => '0');
            test_key_i   <= (others => '0');
            test_init_i  <= '0';
            test_sqz_i   <= '0';
            test_error   <= '0';
            wait for PERIOD;
			rst_s        <= '1';
            wait for PERIOD;

            -- expected output
            real_data_o      <= x"bdd130b032ef6bf479a40454ce72a07ff28f5dc89d5f2a997868bf88859107cf";
            
            -- init
            test_key_i <= x"08edbdab75a2a8d44353d0cd79838cb2189a769b0b03e0c671f3245454e49eb4";
            test_init_i <= '1';
            wait for PERIOD;
            
            -- data blocks
            test_init_i <= '0';
            test_data_i <= x"7cc254f81be8e78d765a2e63339fc99a66320db73158a35a255d0517";
            wait for PERIOD;
           
           -- last data blocks
            test_sqz_i <= '1';
            test_data_i <= x"58e95e00000000000000000000000000000000000000000000000000";
            wait for PERIOD;
           
            -- check result
            test_sqz_i <= '0';
            if (real_data_o = test_data_o) then
                test_error <= '0';
                report "Computed value matches expected one" severity note;
            else
                test_error <= '1';
                report "Computed value do not match expected one" severity note;
            end if;
            wait for PERIOD;
            
            
            test_bench_finish <= true;
            wait;
    
        end process;

end behavioral;