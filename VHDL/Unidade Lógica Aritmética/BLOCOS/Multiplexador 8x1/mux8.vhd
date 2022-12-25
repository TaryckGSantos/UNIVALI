library ieee;
use ieee.std_logic_1164.all;

entity mux8 is
port ( i_R7 : in std_logic_vector(3 downto 0);
	i_R6 : in std_logic_vector(3 downto 0);
	i_R5 : in std_logic_vector(3 downto 0);
	i_R4 : in std_logic_vector(3 downto 0);
	i_R3 : in std_logic_vector(3 downto 0);
	i_R2 : in std_logic_vector(3 downto 0);
	i_R1 : in std_logic_vector(3 downto 0);
	i_R0 : in std_logic_vector(3 downto 0);
	i_XYZ : in std_logic_vector(2 downto 0);
	o_Q : out std_logic_vector(3 downto 0));
end mux8;
	
architecture arch_1 of mux8 is
begin
with i_XYZ select
o_Q <= i_R0 when "000",
i_R1 when "001",
i_R2 when "010",
i_R3 when "011",
i_R4 when "100",
i_R5 when "101",
i_R6 when "110",
i_R7 when others;
end arch_1;
