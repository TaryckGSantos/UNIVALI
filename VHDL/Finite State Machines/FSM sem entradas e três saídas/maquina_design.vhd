library ieee;
use ieee.std_logic_1164.all;

entity maquina_design is
port ( i_CLR : in std_logic; 
       i_CLK   : in std_logic; 
       o_QX     : out std_logic;
       o_QY     : out std_logic;
       o_QZ     : out std_logic); 
end maquina_design;

architecture arch_1 of maquina_design is
  type t_STATE is (q_0, q_1, q_2, q_3); 
  signal r_STATE : t_STATE; 
  signal w_NEXT : t_STATE; 

begin
    
    p_STATE: process(i_CLR, i_CLK)
    begin
      if (i_CLR = '1') then
        r_STATE <= q_0;   
      elsif (rising_edge(i_CLK)) then
        r_STATE <= w_NEXT;  
      end if;
    end process;
  p_NEXT: process(r_STATE)
  begin
    case (r_STATE) is
      when q_0 => w_NEXT <= q_1; 

      when q_1 => w_NEXT <= q_2;

      when q_2 => w_NEXT <= q_3;

      when others => w_NEXT <= q_0;
    end case;
 
      if(r_STATE = q_3) then
          o_QX <= '1';
      else 
          o_QX <= '0';
      end if; 
        
      if(r_STATE = q_2) then
          o_QY <= '1';
      else
          o_QY <= '0';
      end if;
        
      if(r_STATE = q_1) then
          o_QZ <= '1';
      else
          o_QZ <= '0';
      end if;
      
 end process;
end arch_1;
