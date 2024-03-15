library ieee;
use ieee.std_logic_1164.all;

entity padLock is
	port (
        --descrever portas
    );
end entity;

architecture a1 of padLock is
	--descrever estados type state is (S0, S1, S2, S3);
	signal EA, PE: state;
begin

     seq: process(clk, rst)
     begin
       if rst= '1' then
           EA <= S0;
       elsif rising_edge(clk) then
           EA <= PE;
       end if;
     end process;
     comb: process(EA, Ta, Tb)
     begin
        case EA is
            when S0 => if Ta = '0' then   PE <= S1;
                                   else   PE <= S0;
                        end if;
        end case;
     end process;

	--La <= "01" when EA = S0 else
	      --"10" when EA = S1 else
	      --"00";

end architecture;