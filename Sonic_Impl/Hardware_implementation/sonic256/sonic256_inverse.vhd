--------------------------------------------------------------------------------
--! @file       sonic256_inverse.vhd
--! @brief      The inverse of the sonic256 permutation.
--!
--! @author     
--------------------------------------------------------------------------------

library work;
    use work.sonic256_pkg.all;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity sonic256_inverse is
    generic(
        SIZE    : integer := 256;
        nrRounds : integer  := 20
    );
    port (
        message_i       : in  std_logic_vector(0 to SIZE-1);
        message_o       : out std_logic_vector(0 to SIZE-1);
        clk_i           : in std_logic
    );
end sonic256_inverse;

architecture rtl of sonic256_inverse is

    ----------------------------------------------------------------------------
    -- Components
    ----------------------------------------------------------------------------

    component sonic_round_inverse is
        generic ( 
            SIZE   : integer := 256;
            pi_1   : integer := 1;
            pi_5   : integer := 5;
            pi_7   : integer := 7;
            pi_32  : integer := 32;
            pi_14  : integer := 14;
            pi_64  : integer := 64;
            pi_100 : integer := 100
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
        
        round_I : sonic_round_inverse
            generic map (
                SIZE   => SIZE,
                pi_1   => pi_1_offsets(I),
                pi_5   => pi_5_offsets(I),
                pi_7   => pi_7_offsets(I),
                pi_32  => pi_32_offsets(I),
                pi_14  => pi_14_offsets(I),
                pi_64  => pi_64_offsets(I),
                pi_100 => pi_100_offsets(I)
                
            )
            port map(
                round_i => round_in_s(I),
                rc_i    => round_constants(I),
                round_o => round_out_s(I)
            );
    
    end generate; -- end ROUNDS
    
    message_o <= round_out_s(nrRounds-1);
    
end rtl;
