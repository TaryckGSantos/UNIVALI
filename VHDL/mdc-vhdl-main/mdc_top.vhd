library ieee;
use ieee.std_logic_1164.all;

entity mdc_top is
port (  i_CLK : in std_logic;
		  i_CLR : in std_logic;
		  i_GO : in std_logic;
		  i_X : in std_logic_vector(7 downto 0);
		  i_Y : in std_logic_vector(7 downto 0); 
		  o_Q_mdc : out std_logic_vector(7 downto 0));
end mdc_top;

architecture arch_3 of mdc_top is
		component mdc_datapath
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
		end component;
		
		component mdc_control 
		port (  i_CLK : in std_logic;
				  i_CLR : in std_logic;
				  i_IGUAL : in std_logic;
				  i_MENOR : in std_logic;
				  i_GO : in std_logic;
				  o_XSEL : out std_logic;
				  o_YSEL : out std_logic;
				  o_XLD : out std_logic; 
				  o_YLD : out std_logic;
				  o_SLD : out std_logic);
		end component;
		
		signal w_IGUAL, w_MENOR, w_XSEL, w_YSEL, w_XLD, w_YLD, w_SLD: std_logic;
		begin  
		
		u_bloco_datapath: mdc_datapath
				port map( i_CLK => i_CLK,
							 i_CLR => i_CLR,
							 i_XSEL => w_XSEL,
							 i_YSEL => w_YSEL,
							 i_XLD => w_XLD,
							 i_YLD => w_YLD,
							 i_SLD => w_SLD,
							 i_X => i_X,
							 i_Y => i_Y,
							 o_IGUAL => w_IGUAL,
							 o_MENOR => w_MENOR,
							 o_Q => o_Q_mdc);
		
		u_bloco_control: mdc_control
				port map( i_CLK => i_CLK,
							 i_CLR => i_CLR,
							 i_IGUAL => w_IGUAL,
							 i_MENOR => w_MENOR,
							 i_GO => i_GO,
							 o_XSEL => w_XSEL,
							 o_YSEL => w_YSEL,
							 o_XLD => w_XLD,
							 o_YLD => w_YLD,
							 o_SLD => w_SLD);
end arch_3;					  			  