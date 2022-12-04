library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity mdc_datapath is
port (  i_CLK : in std_logic;
		  i_CLR : in std_logic;
		  i_XSEL : in std_logic;
		  i_YSEL : in std_logic;
		  i_XLD : in std_logic; 
		  i_YLD : in std_logic;
		  i_SLD : in std_logic;
		  i_X : in std_logic_vector(7 downto 0);
		  i_Y : in std_logic_vector(7 downto 0);
		  o_IGUAL : out std_logic;
		  o_MENOR : out std_logic;  
		  o_Q : out std_logic_vector(7 downto 0));
end mdc_datapath;
	
architecture arch_1 of mdc_datapath is
component mux8bit
port ( i_mux_a : in std_logic_vector(7 downto 0);
		 i_mux_b : in std_logic_vector(7 downto 0);
		 i_mux_sel : in std_logic;
		 o_mux_q : out std_logic_vector(7 downto 0));
end component;	 

component registrador
port ( i_r : in std_logic_vector(7 downto 0);
		 i_r_clock : in std_logic;
		 i_r_clr : in std_logic;
		 o_r_q : out std_logic_vector(7 downto 0));
end component;

signal w_x, w_y, w_x_aux, w_y_aux, w_xmy, w_ymx: std_logic_vector(7 downto 0);
begin 
		w_xmy <= w_x - w_y;
		w_ymx <= w_y - w_x;
		
		u_bloco_igualdade: process (w_x, w_y)
		begin
				if w_x = w_y then
						o_IGUAL <= '1';
				else
						o_IGUAL <= '0';
				end if;
		end process u_bloco_igualdade;
		
		u_bloco_menor: process (w_x, w_y)
		begin
				if i_X < i_Y then
						o_MENOR <= '1';
				else
						o_MENOR <= '0';
				end if;
		end process u_bloco_menor;
		
		u_mux1 : mux8bit
		port map (
				i_mux_a => w_xmy, i_mux_b => i_X, i_mux_sel => i_XSEL, o_mux_q => w_x_aux	
				
		);
		
		u_mux2 : mux8bit
		port map (
				i_mux_a => w_ymx, i_mux_b => i_Y, i_mux_sel => i_YSEL, o_mux_q => w_y_aux	
		);
		
		u_x_registrador : registrador
		port map (
				i_r => w_x_aux, i_r_clock => i_CLK, i_r_clr => i_CLR, o_r_q => w_x
		);
		
		u_y_registrador : registrador
		port map (
				i_r => w_y_aux, i_r_clock => i_CLK, i_r_clr => i_CLR, o_r_q => w_y
		);
		
		u_q_registrador : registrador
		port map (
				i_r => w_x, i_r_clock => i_CLK, i_r_clr => i_CLR, o_r_q => o_Q
		);	
end arch_1;