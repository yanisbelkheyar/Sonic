--------------------------------------------------------------------------------
--! @file       simon_round.vhd
--! @brief      The simon-like round function
--!
--! @author     
--------------------------------------------------------------------------------

library work;
    use work.simon_pkg.all;
    
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity simon_round is
    generic ( 
        SIZE   : integer := 256
    );
    port (
        round_i : in  std_logic_vector(0 to SIZE-1);
        rc_i    : in  std_logic_vector(0 to SIZE/2-1);
        round_o : out std_logic_vector(0 to SIZE-1)
    );
    
end simon_round;


architecture rtl of simon_round is

    ----------------------------------------------------------------------------
    -- Internal signal declarations
    ----------------------------------------------------------------------------

    signal x_in, y_in   : std_logic_vector(0 to SIZE/2-1);
    signal t_x, t_y     : std_logic_vector(0 to SIZE/2-1);
    signal x_out, y_out : std_logic_vector(0 to SIZE/2-1);

    ----------------------------------------------------------------------------
    -- Begin
    ----------------------------------------------------------------------------

begin  -- rtl
    
    x_in <= round_i(0 to SIZE/2-1);
    y_in <= round_i(SIZE/2 to SIZE-1);
    
    -- y ^ (τ-1(x) ∧ τ-8(x)) ^ τ-2(x) ^ c
    t_y <= y_in xor ( (x_in(SIZE/2-1) & x_in(0 to SIZE/2-2)) and (x_in(SIZE/2-8 to SIZE/2-1) & x_in(0 to SIZE/2-9)) )  -- y ^ (τ-1(x) ∧ τ-8(x))
                xor (x_in(SIZE/2-2 to SIZE/2-1) & x_in(0 to SIZE/2-3))                                                 --   ^ τ-2(x) 
                xor rc_i;                                                                                              --   ^ c
    
    round_o  <= t_y & x_in;
    
end rtl;
