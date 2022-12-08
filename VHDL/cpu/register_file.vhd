library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity register_file is
	port (  i_clk  : in std_logic;
			  i_RF_data  : in std_logic_vector(15 downto 0);
			  i_W_addr  :  in std_logic_vector(3 downto 0);
			  i_Rp_addr  : in std_logic_vector(3 downto 0);
			  i_Rq_addr  : in std_logic_vector(3 downto 0);
			  i_W_wr : in std_logic;
			  i_Rp_rd : in std_logic;
			  i_Rq_rd : in std_logic;
			  o_Rp_data : out std_logic_vector(15 downto 0);
			  o_Rq_data : out std_logic_vector(15 downto 0));
end register_file;

architecture arc_rf of register_file is
	
		type arquivo_reg is array(0 to 15) of std_logic_vector(15 downto 0);
		
		signal array_reg : arquivo_reg;
		begin 
			process(i_clk)
			begin
			if(rising_edge(i_clk)) then 
				o_Rp_data <= array_reg(to_integer(unsigned(i_Rp_addr)));
				o_Rq_data <= array_reg(to_integer(unsigned(i_Rq_addr))); 
			if(i_W_wr = '1') then
				array_reg(to_integer(unsigned(i_W_addr))) <= i_RF_data;
			end if;
		end if;
  end process;
end arc_rf;
