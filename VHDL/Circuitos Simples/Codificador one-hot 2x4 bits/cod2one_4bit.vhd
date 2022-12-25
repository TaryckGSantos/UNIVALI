library IEEE;
use IEEE.std_logic_1164.all;

entity cod2one_4bit is
port(  i_A : in std_logic;
       i_B : in std_logic;
       o_S : out std_logic_vector(3 downto 0));
end cod2one_4bit;

architecture arch_1 of cod2one_4bit is
begin
    	o_S(0) <= (not i_A and not i_B);
    	o_S(1) <= (not i_A and i_B);
    	o_S(2) <= (i_A and not i_B);
    	o_S(3) <= (i_A and i_B);
end arch_1;
