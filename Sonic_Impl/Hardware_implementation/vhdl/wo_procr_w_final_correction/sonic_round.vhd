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
        SIZE   : integer := SIZE
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
    
    t_y <= (x_in(5 to 127) & x_in(0 to 4)) xor y_in xor (x_in and (x_in(1 to 127) & x_in(0))); -- τ5(x) ^ y ^ (x ∧ τ(x))
    t_x <= (x_in xor (x_in(7 to 127) & x_in(0 to 6))) xor ((x_in(32 to 127) & x_in(0 to 31)) xor rc_i); -- x ^ τ7(x) ^ τ32(x) ^ c
    
    pi_i : for i in 0 to SIZE/2-1 generate
        x_out(i) <= t_y((15*i) mod (SIZE/2));
        y_out(i) <= t_x((15*i) mod (SIZE/2));
    end generate;
    
    round_o  <= x_out & y_out;
    
end rtl;
