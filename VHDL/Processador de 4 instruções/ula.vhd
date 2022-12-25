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
port ( i_A : in std_logic_vector (15 downto 0);
	    i_B : in std_logic_vector (15 downto 0);
       i_CIN : in std_logic;
       o_COUT : out std_logic;
       o_S : out std_logic_vector (15 downto 0));
end component;

component mux_2x1_16bits
port ( i_R1 : in std_logic_vector(15 downto 0);
		 i_R0 : in std_logic_vector(15 downto 0);
		 i_S0 : in std_logic;
		 o_Q : out std_logic_vector(15 downto 0));
end component;

component registrador_ula
port ( i_R    : in std_logic_vector(15 downto 0);
		 i_CLK  : in std_logic;
       o_Q    : out std_logic_vector(15 downto 0)); 
end component;

signal w_fullsomador, w_MUX_REGISTER: std_logic_vector (15 downto 0); 
signal w_CIN, w_COUT, w_WIN, w_WOUT: std_logic;

begin 

				u_soma: fullsomador port map(i_A, i_B, w_CIN, w_COUT, w_fullsomador);

				u_mux: mux_2x1_16bits port map(i_A, w_fullsomador, i_S0, w_MUX_REGISTER);

				u_registrador: registrador_ula port map (w_MUX_REGISTER, i_CLK, o_Q);

end arch_ula;