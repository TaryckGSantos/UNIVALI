library IEEE;
use IEEE.std_logic_1164.all;

entity comparador is
port (  i_comp_X : in std_logic;
		  i_comp_Y : in std_logic;
		  i_gt     : in std_logic;
		  i_eq     : in std_logic;
		  i_lt     : in std_logic;
		  o_gt     : out std_logic;
		  o_eq     : out std_logic;
		  o_lt     : out std_logic);
end comparador;
	
architecture comp of comparador is
begin
	
o_gt <= i_gt or (i_eq and i_comp_X and not i_comp_Y);
o_lt <= i_lt or (i_eq and not i_comp_X and i_comp_Y);
o_eq <= i_eq and (i_comp_X XNOR i_comp_Y);

end comp;