library IEEE;
use IEEE.std_logic_1164.all;

entity fsm_gray is
port(	i_CLR : in std_logic; -- clear/reset
		i_CLK : in std_logic; -- clock
        i_GCNT : in std_logic;
        o_X : out std_logic;
        o_Y : out std_logic;
        o_Z : out std_logic);
end fsm_gray;

architecture arch_1 of fsm_gray is
	type t_STATE is (s_0, s_1,s_2,s_3,s_4,s_5,s_6,s_7); -- new FSM type
	signal r_STATE : t_STATE; -- state register
	signal w_NEXT : t_STATE; -- next state
    
begin

	-- state register
	p_STATE: process (i_CLR, i_CLK)
    begin
    	if (i_CLR = '1') then
        	r_STATE <= s_0; --inicial state
            elsif (rising_edge(i_CLK)) then
            	r_STATE <= w_NEXT; -- next state
            end if;
    end process;
    
	 --next state
    p_NEXT: process (r_STATE, i_GCNT)
    begin
    	case (r_STATE) is
        	when s_0 => if (i_GCNT = '1') then
            				w_NEXT <= s_1;
                        else
                        	w_NEXT <= s_0;
                        end if;                        
        	when s_1 => if (i_GCNT = '1') then
            				w_NEXT <= s_2;
                        else
                        	w_NEXT <= s_1;
                        end if;  
        	when s_2 => if (i_GCNT = '1') then
            				w_NEXT <= s_3;
                        else
                        	w_NEXT <= s_2;
                        end if;          
        	when s_3 => if (i_GCNT = '1') then
            				w_NEXT <= s_4;
                        else
                        	w_NEXT <= s_3;
                        end if;          
        	when s_4 => if (i_GCNT = '1') then
            				w_NEXT <= s_5;
                        else
                        	w_NEXT <= s_4;
                        end if; 
        	when s_5 => if (i_GCNT = '1') then
            				w_NEXT <= s_6;
                        else
                        	w_NEXT <= s_5;
                        end if;
        	when s_6 => if (i_GCNT = '1') then
            				w_NEXT <= s_7;
                        else
                        	w_NEXT <= s_6;
                        end if;    
			when others => w_NEXT <= s_0; 
		end case;
	end process;		
	 -- output
    o_X <= '1' when (r_STATE = s_4 or r_STATE = s_5 or r_STATE = s_6 or r_STATE = s_7) else '0';
	 o_Y <= '1' when (r_STATE = s_1 or r_STATE = s_2 or r_STATE = s_5 or r_STATE = s_6) else '0';
	 o_Z <= '1' when (r_STATE = s_2 or r_STATE = s_3 or r_STATE = s_4 or r_STATE = s_5) else '0';
	
end arch_1;
