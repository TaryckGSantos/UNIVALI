library IEEE;
use IEEE.std_logic_1164.all;

entity bor is
port (  i_A : in std_logic_vector(3 downto 0);
	      i_B : in std_logic_vector(3 downto 0);
	      o_S : out std_logic_vector(3 downto 0));
end bor;
	
architecture comp of bor is
begin
    o_S(0)<=(i_A(0) or i_B(0));
    o_S(1)<=(i_A(1) or i_B(1));
    o_S(2)<=(i_A(2) or i_B(2));
    o_S(3)<=(i_A(3) or i_B(3));
end comp;
