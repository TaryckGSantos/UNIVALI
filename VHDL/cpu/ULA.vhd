library ieee;
use ieee.std_logic_1164.all;

entity ula is
port ( i_CLK : in std_logic;
		 i_A : in std_logic_vector (15 downto 0);
       i_B : in std_logic_vector (15 downto 0);
       i_S0 : in std_logic;
       o_Q : out std_logic_vector(15 downto 0));
end ula;

architecture arch_ula of ula is

component fullsomador
port ( i_A : in std_logic_vector (3 downto 0);
	    i_B : in std_logic_vector (3 downto 0);
       i_CIN : in std_logic;
       o_COUT : out std_logic;
       o_S : out std_logic_vector (3 downto 0));
end component;

component fullsubtractor
port ( i_A : in std_logic_vector (3 downto 0);
	    i_B : in std_logic_vector (3 downto 0);
       i_WIN : in std_logic;
       o_WOUT : out std_logic;
       o_S : out std_logic_vector (3 downto 0));
end component;

component incrementador
port ( i_A : in std_logic_vector(3 downto 0);
       o_S : out std_logic_vector(3 downto 0));
end component;

component band	
port (i_A : in std_logic_vector(3 downto 0);
		i_B : in std_logic_vector(3 downto 0);
		o_S : out std_logic_vector(3 downto 0));
end component;	

component bor	
port (i_A : in std_logic_vector(3 downto 0);
		i_B : in std_logic_vector(3 downto 0);
		o_S : out std_logic_vector(3 downto 0));
end component;	

component bxor	
port (i_A : in std_logic_vector(3 downto 0);
		i_B : in std_logic_vector(3 downto 0);
		o_S : out std_logic_vector(3 downto 0));
end component;

component anot	
port (i_A : in std_logic_vector(3 downto 0);
		o_S : out std_logic_vector(3 downto 0));
end component;

component mux8 
port ( i_R7  : in std_logic_vector(3 downto 0);
		 i_R6  : in std_logic_vector(3 downto 0);
		 i_R5  : in std_logic_vector(3 downto 0);
		 i_R4  : in std_logic_vector(3 downto 0);
		 i_R3  : in std_logic_vector(3 downto 0);
		 i_R2  : in std_logic_vector(3 downto 0);
		 i_R1  : in std_logic_vector(3 downto 0);
		 i_R0  : in std_logic_vector(3 downto 0);
       i_XYZ : in std_logic_vector(2 downto 0);
       o_Q : out std_logic_vector(3 downto 0));
end component;

component registrador 
port ( i_CLK  : in std_logic;
       i_EN   : in std_logic;
		 i_R    : in std_logic_vector(3 downto 0);
       o_Q    : out std_logic_vector(3 downto 0)); 
end component;

signal w_fullsomador, w_fullsubtractor, w_incrementador, w_band, w_bor, w_bxor, w_anot, w_MUX_REGISTER: std_logic_vector (3 downto 0); 
signal w_CIN, w_COUT, w_WIN, w_WOUT: std_logic;

begin 

u_soma: fullsomador port map(i_A, i_B, w_CIN, w_COUT, w_fullsomador);

u_subtracao: fullsubtractor port map(i_A, i_B, w_WIN, w_WOUT, w_fullsubtractor);

u_incrementador: incrementador port map(i_A, w_incrementador);

u_band: band port map(i_A, i_B, w_band);

u_bor: bor port map(i_A, i_B, w_bor);

u_bxor: bxor port map(i_A, i_B, w_bxor);

u_anot: anot port map(i_A, w_anot);

u_mux8: mux8 port map(w_fullsomador, w_fullsubtractor, w_incrementador, i_A, w_band, w_bor, w_bxor, w_anot, i_XYZ, w_MUX_REGISTER);

u_registrador: registrador port map (i_CLK, i_EN, w_MUX_REGISTER, o_Q);

end arch_ula;
