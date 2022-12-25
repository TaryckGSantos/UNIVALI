library IEEE;
use IEEE.std_logic_1164.all;

entity incrementador is
port (  i_A : in std_logic_vector(3 downto 0);
	o_S : out std_logic_vector(3 downto 0));
end incrementador;
	
architecture comp of incrementador is
begin
    o_S(3) <= ((not i_a(3) and i_a(2) and i_a(1) and i_a(0)) or (i_a(3) and not i_a(2)) or (i_a(3) and not i_a(1)) or (i_a(3) and not i_a(0)));

    o_S(2) <= ((not i_a(2) and i_a(1) and i_a(0)) or (i_a(2) and not i_a(1)) or (i_a(2) and not i_a(0)));

    o_S(1) <= ((not i_a(1) and i_a(0)) or (i_a(1) and not i_a(0)));

    o_S(0) <= (not i_a(0));

end comp;
