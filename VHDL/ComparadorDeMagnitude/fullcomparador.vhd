library IEEE;
use IEEE.std_logic_1164.all;

entity fullcomparador is
port (  i_comp_X : in std_logic_vector(7 downto 0);
		  i_comp_Y : in std_logic_vector(7 downto 0);
		  i_Lgt     : in std_logic;
		  i_Leq     : in std_logic;
		  i_Llt     : in std_logic;
		  o_gt     : out std_logic;
		  o_eq     : out std_logic;
		  o_lt     : out std_logic);
end fullcomparador;
	
architecture comp of fullcomparador is
component comparador is
port (  i_comp_X : in std_logic;
		  i_comp_Y : in std_logic;
		  i_gt     : in std_logic;
		  i_eq     : in std_logic;
		  i_lt     : in std_logic;
		  o_gt     : out std_logic;
		  o_eq     : out std_logic;
		  o_lt     : out std_logic);
end component;

signal w_maior_0, w_maior_1, w_maior_2, w_maior_3, w_maior_4, w_maior_5, w_maior_6, w_maior_7 : std_logic;
signal w_igual_0, w_igual_1, w_igual_2, w_igual_3, w_igual_4, w_igual_5, w_igual_6, w_igual_7 : std_logic;
signal w_menor_0, w_menor_1, w_menor_2, w_menor_3, w_menor_4, w_menor_5, w_menor_6, w_menor_7 : std_logic;
begin
	
		u_bloco_7 : comparador
		port map ( i_comp_X => i_comp_X(7),
					  i_comp_Y => i_comp_Y(7),
					  i_gt => i_Lgt,
					  i_eq => i_Leq,
					  i_lt => i_Llt,
					  o_gt => w_maior_7,
					  o_eq => w_igual_7,
					  o_lt => w_menor_7);
					  
		u_bloco_6 : comparador
		port map ( i_comp_X => i_comp_X(6),
					  i_comp_Y => i_comp_Y(6),
					  i_gt => w_maior_7,
					  i_eq => w_igual_7,
					  i_lt => w_menor_7,
					  o_gt => w_maior_6,
					  o_eq => w_igual_6,
					  o_lt => w_menor_6);
					  
		u_bloco_5 : comparador
		port map ( i_comp_X => i_comp_X(5),
					  i_comp_Y => i_comp_Y(5),
					  i_gt => w_maior_6,
					  i_eq => w_igual_6,
					  i_lt => w_menor_6,
					  o_gt => w_maior_5,
					  o_eq => w_igual_5,
					  o_lt => w_menor_5);
		
		u_bloco_4 : comparador
		port map ( i_comp_X => i_comp_X(4),
					  i_comp_Y => i_comp_Y(4),
					  i_gt => w_maior_5,
					  i_eq => w_igual_5,
					  i_lt => w_menor_5,
					  o_gt => w_maior_4,
					  o_eq => w_igual_4,
					  o_lt => w_menor_4);
					  
		u_bloco_3 : comparador
		port map ( i_comp_X => i_comp_X(3),
					  i_comp_Y => i_comp_Y(3),
					  i_gt => w_maior_4,
					  i_eq => w_igual_4,
					  i_lt => w_menor_4,
					  o_gt => w_maior_3,
					  o_eq => w_igual_3,
					  o_lt => w_menor_3);
					  
		u_bloco_2 : comparador
		port map ( i_comp_X => i_comp_X(2),
					  i_comp_Y => i_comp_Y(2),
					  i_gt => w_maior_3,
					  i_eq => w_igual_3,
					  i_lt => w_menor_3,
					  o_gt => w_maior_2,
					  o_eq => w_igual_2,
					  o_lt => w_menor_2);
					  
		u_bloco_1 : comparador
		port map ( i_comp_X => i_comp_X(1),
					  i_comp_Y => i_comp_Y(1),
					  i_gt => w_maior_2,
					  i_eq => w_igual_2,
					  i_lt => w_menor_2,
					  o_gt => w_maior_1,
					  o_eq => w_igual_1,
					  o_lt => w_menor_1);
					  
		u_bloco_0 : comparador
		port map ( i_comp_X => i_comp_X(0),
					  i_comp_Y => i_comp_Y(0),
					  i_gt => w_maior_1,
					  i_eq => w_igual_1,
					  i_lt => w_menor_1,
					  o_gt => o_gt,
					  o_eq => o_eq,
					  o_lt => o_lt);
end comp;