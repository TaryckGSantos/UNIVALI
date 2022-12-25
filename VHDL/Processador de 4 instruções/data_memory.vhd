library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

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
	
	signal ram : memory_dt;
	signal addr_reg : natural range 0 to 255;

begin

	process(i_clk)
	begin
	
	if(rising_edge(i_clk)) then
			if(i_rd = '1') then
					o_r_data <= ram(conv_integer(unsigned(i_addr)));
			elsif(i_wr = '1') then
					ram(conv_integer(unsigned(i_addr))) <= i_w_data;
			end if;
	end if;
	end process;

end rtl;