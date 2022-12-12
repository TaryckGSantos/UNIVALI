library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

entity program_counter is
port ( i_pc_clk : in std_logic;
		 i_pc_clr : in std_logic;
		 i_pc_inc : in std_logic;
		 i_pc_D : in std_logic_vector(15 downto 0);
		 o_pc_Q : out std_logic_vector(15 downto 0));
end program_counter;
	
architecture arq_pc of program_counter is
signal w_pc_Q : std_logic_vector(15 downto 0);
begin
		process(i_pc_clk, i_pc_clr)
		begin
				if i_pc_clr = '1' then 
						w_pc_Q <= "0000000000000000";
				elsif rising_edge(i_pc_clk) then	
						if i_pc_inc = '1' then 
								w_pc_Q <= w_pc_Q + 1;
						end if;
				end if;
		end process;
		o_pc_Q <= w_pc_Q;		
end arq_pc;
