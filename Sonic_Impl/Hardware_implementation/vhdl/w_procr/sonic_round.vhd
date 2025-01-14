--------------------------------------------------------------------------------
--! @file       sonic_round.vhd
--! @brief      The sonic round function
--!
--! @author     
--------------------------------------------------------------------------------

library work;
    use work.sonic_pkg.all;
    
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity sonic_round is
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
    
end sonic_round;


architecture rtl of sonic_round is

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
    
    t_y <= (x_in(pi_5 to SIZE/2-1) & x_in(0 to pi_5-1)) xor y_in xor (x_in and (x_in(pi_1 to SIZE/2-1) & x_in(0 to pi_1-1))); -- τ5(x) ^ y ^ (x ∧ τ(x))
    t_x <= (x_in xor (x_in(pi_7 to SIZE/2-1) & x_in(0 to pi_7-1))) xor ((x_in(pi_32 to SIZE/2-1) & x_in(0 to pi_32-1)) xor rc_i); -- x ^ τ7(x) ^ τ32(x) ^ c
    
    -- pi_i : for i in 0 to SIZE/2-1 generate
    --     x_out(i) <= t_y((15*i) mod (SIZE/2));
    --     y_out(i) <= t_x((15*i) mod (SIZE/2));
    -- end generate;
    
    -- round_o  <= x_out & y_out;
    
    round_o  <= t_y & t_x;
    
end rtl;
