library ieee;
use ieee.std_logic_1164.all;

entity registrador is
port (  i_R : in std_logic_vector(3 downto 0);
	i_CLK : in std_logic;
	i_EN : in std_logic;
	o_Q : out std_logic_vector(3 downto 0));
end registrador;
	
architecture arch_1 of registrador is
begin
	process
	begin
		wait until i_CLK' event and i_CLK = '1';
		if i_EN = '1' then
			o_Q <= i_R;
		end if;
	end process;
end arch_1;
