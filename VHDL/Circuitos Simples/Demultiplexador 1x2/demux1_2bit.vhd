library ieee;
use ieee.std_logic_1164.all;

entity demux1_2bit is
port ( i_SEL : in std_logic; -- Seletor de entradas a ser usada
	   i_S : in std_logic; -- Entrada
	   o_A : out std_logic; -- Saída A
       o_B : out std_logic); -- Saída B
end demux1_2bit;

architecture arch_1 of demux1_2bit is
begin
      	process(i_SEL, i_S)
      	begin
				o_A <= (i_S and not i_SEL);
				o_B <= (i_S and i_SEL);
		end process;
end arch_1;
