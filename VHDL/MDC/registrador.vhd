library ieee;
use ieee.std_logic_1164.all;

entity registrador is
port (  i_r_load : in std_logic;
		  i_r : in std_logic_vector(7 downto 0);
		  i_r_clock : in std_logic;
		  i_r_clr : in std_logic;
		  o_r_q : out std_logic_vector(7 downto 0));
end registrador;
	
architecture arch_1 of registrador is
begin
		process(i_r_clock, i_r_clr)
		begin
				if (i_r_clr ='0') then
						o_r_q <= "00000000";
				elsif (i_r_clock'event and i_r_clock = '1') then	
						if (i_r_load = '1') then
								o_r_q <= i_r;
						end if;
				end if;
		end process;
end arch_1;
