library IEEE;
use IEEE.std_logic_1164.all;

entity anot is
port (i_A : in std_logic_vector(3 downto 0);
      o_S : out std_logic_vector(3 downto 0));
end anot;

architecture comp of anot is
begin
    o_S(0)<= not i_A(0);
    o_S(1)<= not i_A(1);
    o_S(2)<= not i_A(2);
    o_S(3)<= not i_A(3);
end comp;
