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
  signal a, b : std_logic;
  signal c : std_logic_vector(1 downto 0);
  -- buffer for storing the text from input read-file
  file input_buf : text;  -- text is keyword
begin

  process
    variable read_col_from_input_buf : line; -- read lines one by one from input_buf

    variable val_col1, val_col2 : std_logic; -- to save col1 and col2 values of 1 bit
    variable val_col3 : std_logic_vector(1 downto 0); -- to save col3 value of 2 bit
    variable val_SPACE : character;  -- for spaces between data in file

  begin

    ----------------------------------
    -- Reading data
  	----------------------------------
    -- if modelsim-project is created, then provide the relative path of the
    -- file (i.e., read_file_ex.txt) with respect to main project folder, else
    -- provide the complete path for the file (e.g., "E:/FSD/read_file_ex.txt")
    file_open(input_buf, "read_file_ex.txt",  read_mode); 

    while not endfile(input_buf) loop
      readline(input_buf, read_col_from_input_buf);
      read(read_col_from_input_buf, val_col1);
      read(read_col_from_input_buf, val_SPACE);  -- read in the space character
      read(read_col_from_input_buf, val_col2);
      read(read_col_from_input_buf, val_SPACE);  -- read in the space character
      read(read_col_from_input_buf, val_col3);

      -- Pass the read values to signals
      a <= val_col1;
      b <= val_col2;
      c <= val_col3;

      wait for 10 ns; --  to display results for 10 ns
    end loop;

    file_close(input_buf);             
    wait; -- indefinitely suspend process
  end process;
end architecture;