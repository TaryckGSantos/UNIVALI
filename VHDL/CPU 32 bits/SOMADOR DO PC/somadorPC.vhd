library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;

entity somadorPC is
port (	i_A : in std_logic_vector (31 downto 0);
			o_S : out std_logic_vector (31 downto 0));
end somadorPC;
	
architecture design of somadorPC is
component somador
port (  i_A : in std_logic;
		  i_B : in std_logic;
		  i_CIN : in std_logic;
		  o_COUT : out std_logic;
		  o_S : out std_logic);
end component;
	
signal w_co0, w_co1, w_co2, w_co3, w_co4, w_co5, w_co6, w_co7, 
w_co8, w_co9, w_co10, w_co11, w_co12, w_co13, w_co14, w_co15, 
w_co16, w_co17, w_co18, w_co19, w_co20, w_co21, w_co22, w_co23, 
w_co24, w_co25, w_co26, w_co27, w_co28, w_co29, w_co30 : std_logic;



begin
		
		o_S <= i_A + 4;
	
end design;
