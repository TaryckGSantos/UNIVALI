library ieee;
use ieee.std_logic_1164.all;

entity decodificador is
port ( i_entrada : in std_logic_vector(15 downto 0);
		 o_instrucao : out std_logic_vector(3 downto 0);
		 o_Ra :  out std_logic_vector(3 downto 0);
		 o_Rb :  out std_logic_vector(3 downto 0);
		 o_Rc : out std_logic_vector(3 downto 0);
		 o_D : out std_logic_vector(7 downto 0));
end decodificador;
	
architecture arch_1 of decodificador is
begin
		o_instrucao <= i_entrada(15 downto 12);
		o_D <= i_entrada(7 downto 0);
		o_Ra <= i_entrada(11 downto 8);
		o_Rb <= i_entrada(7 downto 4);
		o_Rc <= i_entrada(3 downto 0);
		
end arch_1;