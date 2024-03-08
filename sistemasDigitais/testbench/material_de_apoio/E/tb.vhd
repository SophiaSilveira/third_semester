--------------------------------------
-- Biblioteca
--------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;
use std.textio.all;
use IEEE.std_logic_textio.all; -- require for writing/reading std_logic etc.

--------------------------------------
-- Entidade
--------------------------------------
entity tb is
end entity;

--------------------------------------
-- Arquitetura
--------------------------------------
architecture tb of tb is
  signal a : std_logic;
  file output_buf : text;  -- text is keyword
begin

  process
    variable write_col_to_output_buf : line; -- line is keyword
    variable b : integer := 40;
  begin
    a <= '1';  -- assign value to a
    wait for 10 ns; 

    ----------------------------------
    -- Writing data
	----------------------------------
    -- if modelsim-project is created, then provide the relative path of the
    -- file (i.e., read_file_ex.txt) with respect to main project folder, else
    -- provide the complete path for the file (e.g., "E:/FSD/read_file_ex.txt")
    file_open(output_buf, "write_file_ex.txt",  write_mode); 

    write(write_col_to_output_buf, string'("Printing values"));
    writeline(output_buf, write_col_to_output_buf);  -- write in line 1

    write(write_col_to_output_buf, string'("a = "));
    write(write_col_to_output_buf, a);
    write(write_col_to_output_buf, string'(", b = "));
    write(write_col_to_output_buf, b);
    writeline(output_buf, write_col_to_output_buf);    -- write in new line 2

    write(write_col_to_output_buf, string'("Thank you"));
    writeline(output_buf, write_col_to_output_buf);   -- write in new line 3

    file_close(output_buf);
    wait; -- indefinitely suspend process
  end process;
end architecture;