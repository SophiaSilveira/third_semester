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
  signal a, b, cin : std_logic; -- inputs
  signal cout, sum : std_logic;  -- outputs: calculated sum and carry by half_adder
  signal cout_actual, aum_actual : std_logic; -- golden reference

  -- buffer for storing the text from input and for output files
  file input_buf : text;  -- text is keyword
  file output_buf : text;  -- text is keyword

begin

    DUT: entity work.half_adder
        port map(a => a, b => b, cin => cin, cout => cout, sum,sum);

    process
        variable read_col_from_input_buf : line; -- read lines one by one from input_buf
        variable write_col_to_output_buf : line; -- write lines one by one to output_buf

        variable buf_data_from_file : line;  -- buffer for storind the data from input read-file
        variable val_a, val_b : std_logic; 
        variable val_cout, val_sum: std_logic;
        variable val_comma : character;  -- for commas between data in file

        variable good_num : boolean;
    begin
