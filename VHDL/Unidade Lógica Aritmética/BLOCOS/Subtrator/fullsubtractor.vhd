library IEEE;
use IEEE.std_logic_1164.all;
use work.all;

entity fullsubtractor is
port ( i_A : in std_logic_vector (3 downto 0);
	i_B : in std_logic_vector (3 downto 0);
	i_WIN : in std_logic;
	o_WOUT : out std_logic;
	o_S : out std_logic_vector (3 downto 0));
end fullsubtractor;
	
architecture design of fullsubtractor is
component subtrator
port (  i_A : in std_logic;
	i_B : in std_logic;
	i_WIN : in std_logic;
	o_WOUT : out std_logic;
	o_S : out std_logic);
end component;
	
signal w_wo0, w_wo1, w_wo2 : std_logic;
begin
    FS0 : subtrator port map(i_A (0), i_B (0), i_WIN, w_wo0, o_S (0));

    FS1 : subtrator port map(i_A (1), i_B (1), w_wo0, w_wo1, o_S (1));

    FS2 : subtrator port map(i_A (2), i_B (2), w_wo1, w_wo2, o_S (2));

    FS3 : subtrator port map(i_A (3), i_B (3), w_wo2, o_WOUT, o_S (3));
end design;
