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

  -- inputs
  -- 00 at 0 ns
  -- 01 at 10 ns
  -- 10 at 20 ns
  -- 11 at 30 ns
  a <= '0', '1' after 10 ns, '0' after 20 ns, '1' after 30 ns;	
  b <= '0', '1' after 20 ns;

end architecture;