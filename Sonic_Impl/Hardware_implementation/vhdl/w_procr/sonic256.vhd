--------------------------------------------------------------------------------
--! @file       sonic.vhd
--! @brief      The sonic permutation.
--!
--! @author     
--------------------------------------------------------------------------------

library work;
    use work.sonic_pkg.all;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity sonic is
    generic(
        SIZE    : integer := 256;
        nrRounds : integer  := 20
    );
    port (
        message_i       : in  std_logic_vector(0 to SIZE-1);
        message_o       : out std_logic_vector(0 to SIZE-1);
        clk_i           : in std_logic
    );
end sonic;

architecture rtl of sonic is

    ----------------------------------------------------------------------------
    -- Components
    ----------------------------------------------------------------------------

    component sonic_round is
        generic ( 
            SIZE   : integer := 256;
            pi_1   : integer := 1;
            pi_5   : integer := 5;
            pi_7   : integer := 7;
            pi_32  : integer := 32
        );
        port (
            round_i : in  std_logic_vector(0 to SIZE-1);
            rc_i    : in  std_logic_vector(0 to SIZE/2-1);
            round_o : out std_logic_vector(0 to SIZE-1)
        );
    end component;

    ----------------------------------------------------------------------------
    -- Internal signal declarations
    ----------------------------------------------------------------------------

    -- datapath
    signal round_in_s, round_out_s : state;
    signal left_in, right_in, left_out, right_out : std_logic_vector(0 to SIZE/2-1);

    ----------------------------------------------------------------------------
    -- Begin
    ----------------------------------------------------------------------------

begin  -- rtl

    -- input
    round_in_s(0) <= message_i;
    
    -- rounds    
    ROUNDS : for I in 0 to nrRounds-1 generate

        INPUT_STATE_FROM_PREVIOUS : if I > 0 generate
            round_in_s(I) <= round_out_s(I - 1);
        end generate; -- end INPUT_STATE_FROM_PREVIOUS
        
        round_I : sonic_round
            generic map (
                SIZE   => SIZE,
                pi_1   => pi_1_offsets(nrRounds-1-I),
                pi_5   => pi_5_offsets(nrRounds-1-I),
                pi_7   => pi_7_offsets(nrRounds-1-I),
                pi_32  => pi_32_offsets(nrRounds-1-I)
                
            )
            port map(
                round_i => round_in_s(I),
                rc_i    => round_constants(nrRounds-1-I),
                round_o => round_out_s(I)
            );
    
    end generate; -- end ROUNDS
    
    -- correction
    -- left_in <= round_out_s(nrRounds-1)(0 to SIZE/2-1);
    -- right_in <= round_out_s(nrRounds-1)(SIZE/2 to SIZE-1);
    
    -- pi_i : for i in 0 to SIZE/2-1 generate
    --     left_out(i) <= left_in((65*i) mod (SIZE/2));
    --     right_out(i) <= right_in((65*i) mod (SIZE/2));
    -- end generate;
    
    -- output
    -- message_o <= left_out & right_out;
    message_o <= round_out_s(nrRounds-1);
    
end rtl;
