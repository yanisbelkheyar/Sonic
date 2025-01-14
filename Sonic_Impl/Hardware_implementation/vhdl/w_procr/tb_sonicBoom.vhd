--------------------------------------------------------------------------------
--! @file       tb_sonicBoom.vhd
--! @brief      Testbench for the sonicBoom cipher.
--!
--! @author     
--------------------------------------------------------------------------------

library work;
    use work.sonic_pkg.all;
    
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_sonicBoom is
    generic(
        PERIOD : time := 10 ns
    );
end tb_sonicBoom;

architecture behavioral of tb_sonicBoom is

    ----------------------------------------------------------------------------
    -- DUT
    ----------------------------------------------------------------------------

    component sonicBoom is
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
    end component;

    ----------------------------------------------------------------------------
    -- Internal signal declarations
    ----------------------------------------------------------------------------
    
    -- input
    signal test_message_i       : std_logic_vector(0 to SIZE-1);
	signal test_key_i           : std_logic_vector(0 to SIZE-1);
    -- output
    signal test_message_o       : std_logic_vector(0 to SIZE-1);

    -- expected output
    signal real_message_o       : std_logic_vector(0 to SIZE-1);
    
    -- auxiliary
    signal test_error : std_logic := '0';
    signal test_bench_finish : boolean := false;
    
    signal clk_s : std_logic := '0';

    ----------------------------------------------------------------------------
    -- Begin
    ----------------------------------------------------------------------------

begin

    -- dut instantiation
    u_sonicBoom : sonicBoom
        generic map( 
            SIZE => SIZE,
            nrRounds => nrRounds
        )
        port map(
			key_i          => test_key_i,
            message_i      => test_message_i,
            message_o      => test_message_o,
            clk_i          => clk_s
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
            test_message_i      <= (others => '0');
			test_key_i      <= (others => '0');
            test_error          <= '0';
            
            wait for PERIOD;
            -- test data
            test_message_i <= x"0000000000000000000000000000000000000000000000000000000000000000";
			test_key_i <= x"0000000000000000000000000000000000000000000000000000000000000000";
            real_message_o      <= x"f24671dbd325467c2c7754cb945564af640b351978d01a6cfa10ea8b725a0c59";
            wait for PERIOD;
            -- check result
            if (real_message_o = test_message_o) then
                test_error <= '0';
                report "Computed value matches expected one" severity note;
            else
                test_error <= '1';
                report "Computed value do not match expected one" severity note;
            end if;
            wait for PERIOD;
            
            wait for PERIOD;
            -- test data
            test_message_i <= x"327b23c66b8b456766334873643c986919495cff74b0dc51625558ec2ae8944a";
            test_key_i <= x"9ec7536bf53af8146171182ef556410711cb062e4b1f520b3b9c13811f3e2012";real_message_o      <= x"1e6bbee29f4e157cf14a648b75c7200d040e8354606e34f783f8af156adaa6e9";
            wait for PERIOD;
            -- check result
            if (real_message_o = test_message_o) then
                test_error <= '0';
                report "Computed value matches expected one" severity note;
            else
                test_error <= '1';
                report "Computed value do not match expected one" severity note;
            end if;
            wait for PERIOD;
            
            wait for PERIOD;
            -- test data
            test_message_i <= x"327b23c66b8b456766334873643c986919495cff74b0dc51625558ec2ae8944a";
            test_key_i <= x"46e87ccd238e1f29507ed7ab3d1b58ba41b71efb2eb141f27545e14679e2a9e3";
			real_message_o      <= x"a9dbb55f2fe232bbf8f31d053e8ed1e2ef5595d984dfbfd769b9c88d17933366";
            wait for PERIOD;
            -- check result
            if (real_message_o = test_message_o) then
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