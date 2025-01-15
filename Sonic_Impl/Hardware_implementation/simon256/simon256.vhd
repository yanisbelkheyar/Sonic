--------------------------------------------------------------------------------
--! @file       simon.vhd
--! @brief      The simon-like permutation.
--!
--! @author     
--------------------------------------------------------------------------------

library work;
    use work.simon_pkg.all;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity simon256 is
    generic(
        SIZE    : integer := 256;
        nrRounds : integer  := 20
    );
    port (
        message_i       : in  std_logic_vector(0 to SIZE-1);
        message_o       : out std_logic_vector(0 to SIZE-1);
        clk_i           : in std_logic
    );
end simon256;

architecture rtl of simon256 is

    ----------------------------------------------------------------------------
    -- Components
    ----------------------------------------------------------------------------

    component simon_round is
        generic ( 
            SIZE   : integer := 256
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
        
        round_I : simon_round
            generic map (
                SIZE   => SIZE
            )
            port map(
                round_i => round_in_s(I),
                rc_i    => round_constants(nrRounds-1-I),
                round_o => round_out_s(I)
            );
    
    end generate; -- end ROUNDS
    
    message_o <= round_out_s(nrRounds-1);
    
end rtl;
