library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity data_memory is 
port ( i_clk : in std_logic; 
		 i_addr : in std_logic_vector(7 downto 0);
		 i_rd : in std_logic;
		 i_wr : in std_logic;
		 i_w_data : in std_logic_vector(15 downto 0);
		 o_r_data : out std_logic_vector(15 downto 0));
end data_memory;

architecture rtl of data_memory is

	type memory_dt is array(255 downto 0) of std_logic_vector(15 downto 0);

	-- Declare the RAM signal.	
	signal ram : memory_dt;
	signal addr_reg : natural range 0 to 255;

begin

	process(i_clk)
	begin
	if(rising_edge(i_clk)) then
		if(i_wr = '1') then
			ram(to_integer(unsigned(i_addr))) <= i_w_data;
		end if;

		addr_reg <= (to_integer(unsigned(i_addr)));
	end if;
	end process;

	o_r_data <= ram(addr_reg) when (i_rd = '1') else "0000000000000000";

end rtl;
