--------------------------------------
-- Biblioteca
--------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

--------------------------------------
-- Entidade
--------------------------------------
entity tb is
end entity;

--------------------------------------
-- Arquitetura
--------------------------------------
architecture tb of tb is
  signal a, b : std_logic; -- inputs
  signal sum, carry: std_logic; -- outputs
begin

  DUT: entity work.half_adder
    port map(a => a, b => b, sum => sum, carry => carry);

  process
    constant period: time := 10 ns;
  begin
    a <= '0';
    b <= '0';
    wait for period;
    assert ((sum = '0') and (carry = '0'))  -- expected output
    -- error will be reported if sum or carry is not 0
    report "test failed for input combination 00" severity error;

    a <= '0';
    b <= '1';
    wait for period;
    assert ((sum = '1') and (carry = '0'))
    report "test failed for input combination 01" severity error;

    a <= '1';
    b <= '0';
    wait for period;
    assert ((sum = '1') and (carry = '0'))
    report "test failed for input combination 10" severity error;

    a <= '1';
    b <= '1';
    wait for period;
    assert ((sum = '0') and (carry = '1'))
    report "test failed for input combination 11" severity error;

    -- Fail test
    a <= '0';
    b <= '1';
    wait for period;
    assert ((sum = '0') and (carry = '1'))
    report "test failed for input combination 01 (fail test)" severity error;

    wait; -- indefinitely suspend process
  end process;
end architecture;