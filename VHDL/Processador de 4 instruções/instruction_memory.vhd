library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_signed.all;
use ieee.numeric_std.all;

entity instruction_memory is
port ( i_clk	: in std_logic;
	    i_rd	: in std_logic;
		 i_addr	: in std_logic_vector(15 downto 0);
		 o_q		: out std_logic_vector(15 downto 0));
end instruction_memory;

architecture arq_im of instruction_memory is

	type memory_inst is array(0 to 15) of std_logic_vector(15 downto 0);	 
	
	signal instrucao : memory_inst := ( "0011010000000100", -- R4 recebe a constante 4
												   "0001010000000000", -- D0 recebe R4 (primeira operacao)
												   "0011001000000010", -- R2 recebe a constante 2
												   "0000000100000001", -- R1 recebe D1
												   "0000000000000000", -- R0 recebe D0
												   "0010000100000010", -- R1 recebe a soma entre R0 e R2
												   "0001000100000001", -- D1 recebe R1 (segunda operação)
												   "0010000000000001", -- R0 recebe a soma entre R1 e R0
												   "0001000100000000", -- D0 recebe R0
												   "0000000000000000",
												   "0000000000000000",
													"0000000000000000",
												   "0000000000000000",
												   "0000000000000000",
												   "0000000000000000",
												   "0000000000000000");
	begin 
	
	process(i_clk)
	begin
			if(rising_edge(i_clk)) then
					if(i_rd = '1') then
							o_q <= instrucao(conv_integer(i_addr));
					end if;
			end if;
	end process;
end arq_im;