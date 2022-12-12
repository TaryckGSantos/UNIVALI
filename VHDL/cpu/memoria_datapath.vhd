-- Falta a logica de escrever/ler, mas de resto está pronto

library ieee;
use ieee.std_logic_1164.all;

entity memoria_datapath is
	port 
	(
		i_D_addr : in natural range 0 to 255;
		i_D_data : in std_logic_vector(15 downto 0);
		i_D_rd   : in std_logic;
		i_D_wr   : in std_logic;
		i_clk    : in std_logic;
		o_D_data : out std_logic_Vector(15 downto 0));
end memoria_datapath;

architecture arch_mem of memoria_datapath is
	
	type mem_data is array(255 downto 0) of std_logic_vector(15 downto 0);
	
	signal w_ram : mem_data;

	signal w_addr_reg : natural range 0 to 255;

begin

	process(i_clk)
	begin
	if(rising_edge(i_clk)) then
		if(i_D_wr = '1') then
			w_ram(i_D_addr) <= i_D_data;
		end if;
		w_addr_reg <= i_D_addr;
	end if;
	end process;

	o_D_data <= w_ram(w_addr_reg);

end arch_mem;
