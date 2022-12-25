library ieee;
use ieee.std_logic_1164.all;

entity mux_3x1_16bits is
port ( i_R2 : in std_logic_vector(15 downto 0);
		 i_R1 : in std_logic_vector(15 downto 0);
		 i_R0 : in std_logic_vector(15 downto 0);
		 i_S1 : in std_logic;
		 i_S0 : in std_logic;
		 o_Q : out std_logic_vector(15 downto 0));
end mux_3x1_16bits;
	
architecture arch_1 of mux_3x1_16bits is 
signal w_distribuidor : std_logic_vector(1 downto 0);
begin
		
		w_distribuidor(1) <= i_S1;
		w_distribuidor(0) <= i_S0;
		
		with w_distribuidor select 
				o_Q <= i_R2 when "00",
						 i_R1 when "01",
						 i_R0 when "10",
						 "0000000000000000" when others;
end arch_1;