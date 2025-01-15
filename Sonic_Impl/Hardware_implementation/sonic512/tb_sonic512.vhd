--------------------------------------------------------------------------------
--! @file       tb_sonic512.vhd
--! @brief      Testbench for the sonic512[16] permutation.
--!
--! @author     
--------------------------------------------------------------------------------

library work;
    use work.sonic512_pkg.all;
    
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_sonic512 is
    generic(
        PERIOD : time := 10 ns
    );
end tb_sonic512;

architecture behavioral of tb_sonic512 is

    ----------------------------------------------------------------------------
    -- DUT
    ----------------------------------------------------------------------------

    component sonic512 is
        generic(
            SIZE    : integer := 512;
            nrRounds : integer  := 16
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
    
    -- input
    signal test_message_i       : std_logic_vector(0 to SIZE-1);
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
    u_sonic : sonic512
        generic map( 
            SIZE => 512,
            nrRounds => 16
        )
        port map(
            clk_i          => clk_s,
            message_i      => test_message_i,
            message_o      => test_message_o
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
            test_error          <= '0';
            
            wait for PERIOD;
            -- test data
            test_message_i <= x"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
            real_message_o <= x"dbc489e92a128ac4d3c43bbeec9ff6ca6aa0d82f4ade691e50a2fba14a38eeedcb6af3f98f3c80aef6def19f3b1060cd9233e85608edcfae34be9826af69c567";
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
            test_message_i <= x"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001";
            real_message_o <= x"127a1ab1786c4d2824e2226e3dab66fca63ad3ca817575ef3c57d749136493cb04cb0c910b34b58b787f0a207ab41d5a4ba028aa26101a8c5bde908f21e526bc";
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
            test_message_i <= x"327b23c66b8b456766334873643c986919495cff74b0dc51625558ec2ae8944a46e87ccd238e1f29507ed7ab3d1b58ba41b71efb2eb141f27545e14679e2a9e3";
            real_message_o <= x"8cf9b979a73a36b825cf985050231347b402cbe89565d5cc000210a612536d29c6756ed1b9d6447792dafed0bf1d6fbbd119f7d8eec286e6decd61dd75d884ea";
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