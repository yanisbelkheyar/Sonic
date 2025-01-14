--------------------------------------------------------------------------------
--! @file       simon256_pkg.vhd
--! @brief      Package for the simon-like permutation.
--!
--! @author     
--------------------------------------------------------------------------------

library IEEE;
    use IEEE.std_logic_1164.all;

library work;

package simon_pkg is
    
	-- reset
	constant active_rst : std_logic := '0';
	
    -- size
    constant SIZE         : integer := 256;
    -- number of rounds
    constant nrRounds     : integer := 20;
    
    --types
    type rc_state is array(integer range 0 to (nrRounds - 1)) of std_logic_vector(0 to SIZE/2-1);
    type state is array(integer range 0 to (nrRounds - 1)) of std_logic_vector(0 to SIZE-1);
    type offsets is array(integer range 0 to (nrRounds - 1)) of integer;
    
    constant round_constants : rc_state := (x"80008000800080008000800000000000",  -- f9
                                            x"80008000800000000000000080000000",  -- 47
                                            x"80008000800080000000800000008000",  -- eb
                                            x"80008000800000008000800000000000",  -- 37
                                            x"80000000800080000000800000000000",  -- 69
                                            x"80008000000080008000800000000000",  -- 3b
                                            x"80000000800000000000800000000000",  -- 49
                                            x"00008000000080008000800000000000",  -- 3a
                                            x"00008000000080008000000000000000",  -- b0
                                            x"80000000800080008000800080000000",  -- 7d
                                            x"80000000800000008000800000008000",  -- 5b
                                            x"00008000000080000000000080000000",  -- 4a
                                            x"00000000000080008000000000008000",  -- 32
                                            x"80000000000000008000800080000000",  -- 71
                                            x"80000000800080008000800000008000",  -- 7b
                                            x"80008000000080000000000080000000",  -- 4b
                                            x"80008000800000000000800000008000",  -- cb
                                            x"00008000800000008000800000000000",  -- 36
                                            x"00008000000000008000000000000000",  -- 90
                                            x"00000000800080008000800080000000"); -- 7c

end package;

