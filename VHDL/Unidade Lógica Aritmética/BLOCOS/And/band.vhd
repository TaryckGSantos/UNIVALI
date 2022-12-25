library IEEE;
use IEEE.std_logic_1164.all;

entity band is
port (  i_A : in std_logic_vector(3 downto 0);
	i_B : in std_logic_vector(3 downto 0);
	o_S : out std_logic_vector(3 downto 0));
end band;
	
architecture comp of band is
begin
	o_S(0)<=(i_A(0) and i_B(0));
	o_S(1)<=(i_A(1) and i_B(1));
	o_S(2)<=(i_A(2) and i_B(2));
	o_S(3)<=(i_A(3) and i_B(3));
end comp;
