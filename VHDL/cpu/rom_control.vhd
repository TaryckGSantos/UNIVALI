library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity rom_control is
	generic 
	( TAM : natural := 16);
	port 
	(  i_rom_clk  : in std_logic;
		i_rom_rd   : in std_logic;
		i_rom_addr : in natural range 0 to 2**TAM - 1;
		o_rom_data : out std_logic_vector((TAM -1) downto 0));
end rom_control;

architecture arc_rom of rom_control is

	type memoria is array(2**TAM-1 downto 0) of std_logic_vector((TAM-1) downto 0);

	function init_rom
		return memoria is 
		variable tmp : memoria := (others => (others => '0'));
	begin 
		for addr_pos in 0 to 2**TAM - 1 loop
					tmp(addr_pos) := std_logic_vector(to_unsigned(addr_pos, TAM));
		end loop;
		return tmp;
	end init_rom;	 
	
	signal rom : memoria := init_rom;

begin

	process(i_rom_clk)
	begin
		if(rising_edge(i_rom_clk) and i_rom_rd = '1') then
		o_rom_data <= rom(i_rom_addr);
		end if;
	end process;

end arc_rom;
