--------------------------------------------------------------------------------
--! @file       sonicBoom_inverse.vhd
--! @brief      The inverse of sonicBoom block cipher (Even-Mansour+sonic256).
--!
--! @author
--------------------------------------------------------------------------------

library work;
    use work.sonic256_pkg.all;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity sonicBoom_inverse is
    generic(
        SIZE    : integer := 256;
        nrRounds : integer  := 20
    );
    port (
        key_i           : in  std_logic_vector(0 to SIZE-1);
        message_i       : in  std_logic_vector(0 to SIZE-1);
        message_o       : out std_logic_vector(0 to SIZE-1);
        clk_i           : in std_logic
    );
end sonicBoom_inverse;

architecture rtl of sonicBoom_inverse is

    ----------------------------------------------------------------------------
    -- Components
    ----------------------------------------------------------------------------

    component sonic256_inverse is
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
    signal key_s, message_in_s, message_out_s : std_logic_vector(0 to SIZE-1);
    
    ----------------------------------------------------------------------------
    -- Begin
    ----------------------------------------------------------------------------

begin  -- rtl

    -- input
    message_in_s <= message_i xor key_i;
    key_s     <= key_i;

    -- sonic
    sonic_i : sonic256_inverse
        generic map (
            SIZE   => 256,
            nrRounds => 20
        )
        port map(
            message_i => message_in_s,
            message_o => message_out_s,
            clk_i => clk_i
        );

    -- output
    message_o <= message_out_s xor key_s;

end rtl;
