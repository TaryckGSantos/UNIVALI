library IEEE;
use IEEE.std_logic_1164.all;

entity mux_demux_TMR is
port (i_SEL  :  in std_logic;
      i_SW0  :  in std_logic;
      i_SW1  :  in std_logic;
      i_BUT1 :  in std_logic;
      i_BUT2 :  in std_logic;
      i_BUT3 :  in std_logic;
      o_LED0 :  out std_logic;
      o_LED1 :  out std_logic);
end mux_demux_TMR;

architecture arch_1 of mux_demux_TMR is
begin

	process(i_SEL,i_SW0,i_SW1,i_BUT1,i_BUT2,i_BUT3)
    begin
    
	o_LED0 <= ((((((not i_SEL and i_SW0) or (i_SW1 and i_SEL))xor i_BUT1)and(((not i_SEL and i_SW0) or (i_SW1 and i_SEL))xor i_BUT2)) or ((((not i_SEL and i_SW0) or (i_SW1 and i_SEL))xor i_BUT1)and(((not i_SEL and i_SW0) or (i_SW1 and i_SEL))xor i_BUT3)) or ((((not i_SEL and i_SW0) or (i_SW1 and i_SEL))xor i_BUT2)and(((not i_SEL and i_SW0) or (i_SW1 and i_SEL))xor i_BUT3)))and not i_SEL);
	o_LED1 <= ((((((not i_SEL and i_SW0) or (i_SW1 and i_SEL))xor i_BUT1)and(((not i_SEL and i_SW0) or (i_SW1 and i_SEL))xor i_BUT2)) or ((((not i_SEL and i_SW0) or (i_SW1 and i_SEL))xor i_BUT1)and(((not i_SEL and i_SW0) or (i_SW1 and i_SEL))xor i_BUT3)) or ((((not i_SEL and i_SW0) or (i_SW1 and i_SEL))xor i_BUT2)and(((not i_SEL and i_SW0) or (i_SW1 and i_SEL))xor i_BUT3)))and i_SEL);
	end process;
end arch_1;
