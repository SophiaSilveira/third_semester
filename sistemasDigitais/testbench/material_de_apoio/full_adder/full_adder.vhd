--------------------------------------
-- Biblioteca
--------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

--------------------------------------
-- Entidade
--------------------------------------
entity full_adder is
  port (a, b, cin: in std_logic;
	    cout, sum: out std_logic);
end entity;

--------------------------------------
-- Arquitetura
--------------------------------------
architecture full_adder of full_adder is
begin
  cout <= (a and b) or ((a xor b) and cin);
  sum <= a xor b xor cin;
end architecture;