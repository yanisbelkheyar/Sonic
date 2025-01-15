--------------------------------------------------------------------------------
--! @file       tb_sonic256.vhd
--! @brief      Testbench for the sonic256 permutation.
--!
--! @author     
--------------------------------------------------------------------------------

library work;
    use work.sonic256_pkg.all;
    
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_sonic256 is
    generic(
        PERIOD : time := 10 ns
    );
end tb_sonic256;

architecture behavioral of tb_sonic256 is

    ----------------------------------------------------------------------------
    -- DUT
    ----------------------------------------------------------------------------

    component sonic256 is
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
    u_sonic : sonic256
        generic map( 
            SIZE => SIZE,
            nrRounds => nrRounds
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
            test_message_i <= x"0000000000000000000000000000000000000000000000000000000000000000";
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
            real_message_o      <= x"9e5658c4ffde1b5fa9391c1aded2eb46cb0eb42dc4692c0bb12aff450382e391";
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
            test_message_i <= x"46e87ccd238e1f29507ed7ab3d1b58ba41b71efb2eb141f27545e14679e2a9e3";
            real_message_o      <= x"9ec7536bf53af8146171182ef556410711cb062e4b1f520b3b9c13811f3e2012";
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
            test_message_i <= x"5bd062c2515f007c4db127f8122008541f16e9e80216231b66ef438d1190cde7";
            real_message_o      <= x"38c3c7b43329c3d436327d76ca0fd12f89b022d7b058f938402d4da122fa06fb";
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