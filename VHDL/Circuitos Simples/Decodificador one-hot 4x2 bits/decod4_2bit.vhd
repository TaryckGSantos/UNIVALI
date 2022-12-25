library IEEE;
use IEEE.std_logic_1164.all;

entity decod4_2bit is
port(  i_A : in std_logic_vector(3 downto 0);
       o_R : out std_logic;
       o_S : out std_logic);
end decod4_2bit;

architecture arch_1 of decod4_2bit is
begin
  
		o_S <= (not i_A(0) and i_A(1) and not i_A(2) and not i_A(3)) or (not i_A(0) and not i_A(1) and not i_A(2) and i_A(3));
	
		o_R <= (not i_A(0) and not i_A(1) and i_A(2) and not i_A(3)) or (not i_A(0) and not i_A(1) and not i_A(2) and i_A(3));
  
end arch_1;
