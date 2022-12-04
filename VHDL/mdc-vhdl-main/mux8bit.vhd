library IEEE;
use IEEE.std_logic_1164.all;

entity mux8bit is
port ( i_mux_a : in std_logic_vector(7 downto 0);
		 i_mux_b : in std_logic_vector(7 downto 0);
		 i_mux_sel : in std_logic;
		 o_mux_q : out std_logic_vector(7 downto 0));	
end mux8bit;
	
architecture arch_1 of mux8bit is
begin		
				o_mux_q <= i_mux_a when i_mux_sel = '0' else i_mux_b;
end arch_1;