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
  signal cout_actual, sum_actual : std_logic; -- golden reference

  -- buffer for storing the text from input and for output files
  file input_buf : text;  -- text is keyword
  file output_buf : text;  -- text is keyword

begin

    DUT: entity work.full_adder
        port map(a => a, b => b, cin => cin, cout => cout, sum => sum);

    process
        variable read_col_from_input_buf : line; -- read lines one by one from input_buf
        variable write_col_to_output_buf : line; -- write lines one by one to output_buf

        variable buf_data_from_file : line;  -- buffer for storind the data from input read-file
        variable val_a, val_b, val_cin : std_logic; 
        variable val_cout, val_sum: std_logic;
        variable val_comma : character;  -- for commas between data in file

        variable good_num : boolean;
    begin
        file_open(input_buf, "full_adder_input.csv",  read_mode); 
        file_open(output_buf, "full_adder_output.csv",  write_mode); 

        write(write_col_to_output_buf, 
        string'("#a;b;cin;cout_actual;cout;sum_actual;sum;cout_test_results;sum_test_results"));
      writeline(output_buf, write_col_to_output_buf);
  
      while not endfile(input_buf) loop
        readline(input_buf, read_col_from_input_buf);
        read(read_col_from_input_buf, val_a, good_num);
        next when not good_num;  -- i.e. skip the header lines
  
        read(read_col_from_input_buf, val_comma);           -- read in the space character
        read(read_col_from_input_buf, val_b, good_num);  
        assert good_num report "bad value assigned to val_b";

        read(read_col_from_input_buf, val_comma);           -- read in the space character
        read(read_col_from_input_buf, val_cin, good_num);  
        assert good_num report "bad value assigned to val_cin";
  
        read(read_col_from_input_buf, val_comma);           -- read in the space character
        read(read_col_from_input_buf, val_cout);
        read(read_col_from_input_buf, val_comma);           -- read in the space character
        read(read_col_from_input_buf, val_sum);
  
        -- Pass the variable to a signal to allow the ripple-carry to use it
        a <= val_a;
        b <= val_b;
        cin <=val_cin;
        cout_actual <= val_cin;
        sum_actual <= val_sum;
  
        wait for 10 ns;  --  to display results for 10 ns
  
        write(write_col_to_output_buf, a);
        write(write_col_to_output_buf, string'(";"));
        write(write_col_to_output_buf, b);
        write(write_col_to_output_buf, string'(";"));
        write(write_col_to_output_buf, cin);
        write(write_col_to_output_buf, string'(";"));
        write(write_col_to_output_buf, cout_actual);
        write(write_col_to_output_buf, string'(";"));
        write(write_col_to_output_buf, cout);
        write(write_col_to_output_buf, string'(";"));
        write(write_col_to_output_buf, sum_actual);
        write(write_col_to_output_buf, string'(";"));
        write(write_col_to_output_buf, sum);
        write(write_col_to_output_buf, string'(";"));
          
        -- Display Error or OK if results are wrong
        if (cout_actual /= cout) then
          write(write_col_to_output_buf, string'("Error;"));
        else
          write(write_col_to_output_buf, string'("OK;"));  -- write nothing
        end if;
  
        -- Display Error or OK based on comparison
        if (sum_actual /= sum) then
          write(write_col_to_output_buf, string'("Error;"));
        else
          write(write_col_to_output_buf, string'("OK;"));
        end if;
  
        -- Write(write_col_to_output_buf, a, b, sum_actual, sum, carry_actual, carry);
        writeline(output_buf, write_col_to_output_buf);
      end loop;
  
      file_close(input_buf);
      file_close(output_buf);
      wait;
    end process;
  end architecture;