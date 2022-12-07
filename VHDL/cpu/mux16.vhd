library ieee;
use ieee.std_logic_1164.all;

entity mux16 is
port ( i_R2 : in std_logic_vector(15 downto 0);
		 i_R1 : in std_logic_vector(15 downto 0);
		 i_R0 : in std_logic_vector(15 downto 0);
		 i_S : in std_logic_vector(1 downto 0);
		 o_Q : out std_logic_vector(15 downto 0));
end mux16;
	
architecture arch_1 of mux16 is
begin
with i_S select
		o_Q <= i_R2 when "00",
		i_R1 when "01",
		i_R0 when "10",
		"0000000000000000" when others;
end arch_1;