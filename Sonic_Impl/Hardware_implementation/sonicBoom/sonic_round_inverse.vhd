--------------------------------------------------------------------------------
--! @file       sonic_round_inverse.vhd
--! @brief      The inverse of sonic round function
--!
--! @author     
--------------------------------------------------------------------------------

library work;
    use work.sonic256_pkg.all;
    
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity sonic_round_inverse is
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
    
end sonic_round_inverse;


architecture rtl of sonic_round_inverse is

    ----------------------------------------------------------------------------
    -- Internal signal declarations
    ----------------------------------------------------------------------------

    signal x_in, y_in               : std_logic_vector(0 to SIZE/2-1);
    signal t_x_1, t_x_2, t_x_3, t_y : std_logic_vector(0 to SIZE/2-1);

    ----------------------------------------------------------------------------
    -- Begin
    ----------------------------------------------------------------------------

begin  -- rtl
    
    x_in <= round_i(SIZE/2 to SIZE-1) xor rc_i;
    y_in <= round_i(0 to SIZE/2-1);
    
    -- θ^−1 = (1+X^7 +X^32)(1+X^14 +X^64)X^100
    
    t_x_1 <= x_in xor (x_in(pi_7 to SIZE/2-1) & x_in(0 to pi_7-1)) xor (x_in(pi_32 to SIZE/2-1) & x_in(0 to pi_32-1)); -- (1+X^7 +X^32)
    t_x_2 <= t_x_1 xor (t_x_1(pi_64 to SIZE/2-1) & t_x_1(0 to pi_64-1)) xor (t_x_1(pi_14 to SIZE/2-1) & t_x_1(0 to pi_14-1)); -- (1+X^14 +X^64)
    t_x_3 <= (t_x_2(pi_100 to SIZE/2-1) & t_x_2(0 to pi_100-1)); -- X^100
    
    t_y <= ((t_x_3(pi_1 to SIZE/2-1) & t_x_3(0 to pi_1-1)) and t_x_3) xor (t_x_3(pi_5 to SIZE/2-1) & t_x_3(0 to pi_5-1)) xor y_in; -- τ5(x) ^ y ^ (x ∧ τ(x))
    
    round_o  <= t_x_3 & t_y;
    
end rtl;
