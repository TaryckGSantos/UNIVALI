library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.STD_LOGIC_signed.all; 

entity program_counter is
port ( i_clk : in std_logic;
		 i_pc_clr : in std_logic;
		 i_pc_inc : in std_logic;
		 o_pc_Q : out std_logic_vector(15 downto 0));
end program_counter;
	
architecture arq_pc of program_counter is

signal w_pc_Q : std_logic_vector(15 downto 0);
begin
		process(i_clk, i_pc_clr)
		begin
				if rising_edge(i_clk) then
						if i_pc_clr = '1' then 
								w_pc_Q <= "0000000000000000";
						else 
								if i_pc_inc = '1' then 
										w_pc_Q <= w_pc_Q + 1;
								end if;
						end if;
				end if;
		end process;
		o_pc_Q <= w_pc_Q;		
end arq_pc;