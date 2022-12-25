library IEEE;
use IEEE.std_logic_1164.all;

entity tb_fsm_gray is
--empty
end tb_fsm_gray;

architecture arch_1 of tb_fsm_gray is

component fsm_gray is
port(	i_CLR : in std_logic; -- clear/reset
		i_CLK : in std_logic; -- clock
        i_GCNT : in std_logic;
        o_X : out std_logic;
        o_Y : out std_logic;
        o_Z : out std_logic);
end component;

signal w_CLR, w_CLK, w_GCNT, w_X, w_Y, w_Z : std_logic;
begin

	--connect DUT
    u_DUT : fsm_gray port map(i_CLR => w_CLR,
    						i_CLK => w_CLK,
                              i_GCNT => w_GCNT,
                              o_X => w_X,
                              o_Y => w_Y,
                              o_Z => w_Z);
                       
process
	begin
    --reset
    w_CLR <= '0';
    w_CLK <= '0';
    w_GCNT <= '0';
    wait for 1ns;
    assert(w_CLR <='0' and w_CLK <='0') report "Fail @ 00" severity error; 
    
    w_CLR <= '1';
    w_GCNT <= '0';
    wait for 1ns;
    
    w_CLR <= '0';
    w_GCNT <= '0';
    wait for 1ns;
    
    --clock and gcnt
    w_CLK <= '1';
    w_GCNT <= '0';
    wait for 1ns;
    
    w_CLK <= '0';
    w_GCNT <= '0';
    wait for 1ns;
    
    w_CLK <= '1';
    w_GCNT <= '0';
    wait for 1ns;
    
    w_CLK <= '0';
    w_GCNT <= '0';
    wait for 1ns;
    
    w_CLK <= '1';
    w_GCNT <= '0';
    wait for 1ns;
    
    w_CLK <= '0';
    w_GCNT <= '0';
    wait for 1ns;
    
    w_CLK <= '1';
    w_GCNT <= '0';
    wait for 1ns;
    
    w_CLK <= '0';
    w_GCNT <= '0';
    wait for 1ns;
    
    w_CLK <= '1';
    w_GCNT <= '0';
    wait for 1ns;
    
    w_CLK <= '0';
    w_GCNT <= '0';
    wait for 1ns;
    
    w_CLK <= '1';
    w_GCNT <= '0';
    wait for 1ns;
    
    w_CLK <= '0';
    w_GCNT <= '0';
    wait for 1ns;
    
    w_CLK <= '1';
    w_GCNT <= '0';
    wait for 1ns;
    
    w_CLK <= '0';
    w_GCNT <= '0';
    wait for 1ns;
    
    w_CLK <= '1';
    w_GCNT <= '0';
    wait for 1ns;
    
    w_CLK <= '0';
    w_GCNT <= '0';
    wait for 1ns;
    
    w_CLK <= '1';
    w_GCNT <= '1';
    wait for 1ns;
    
    w_CLK <= '0';
    w_GCNT <= '1';
    wait for 1ns;
    
    w_CLK <= '1';
    w_GCNT <= '1';
    wait for 1ns;
    
    w_CLK <= '0';
    w_GCNT <= '1';
    wait for 1ns;
    
    w_CLK <= '1';
    w_GCNT <= '1';
    wait for 1ns;
    
    w_CLK <= '0';
    w_GCNT <= '1';
    wait for 1ns;
    
    w_CLK <= '1';
    w_GCNT <= '1';
    wait for 1ns;
    
    w_CLK <= '0';
    w_GCNT <= '1';
    wait for 1ns;
    
    w_CLK <= '1';
    w_GCNT <= '1';
    wait for 1ns;
    
    w_CLK <= '0';
    w_GCNT <= '1';
    wait for 1ns;
    
    w_CLK <= '1';
    w_GCNT <= '1';
    wait for 1ns;
    
    w_CLK <= '0';
    w_GCNT <= '1';
    wait for 1ns;
    
    w_CLK <= '1';
    w_GCNT <= '1';
    wait for 1ns;
    
    w_CLK <= '0';
    w_GCNT <= '1';
    wait for 1ns;
    
    w_CLK <= '1';
    w_GCNT <= '1';
    wait for 1ns;
    
    w_CLK <= '0';
    w_GCNT <= '1';
    wait for 1ns;
    
    --clear inputs
    w_CLR <= '1';
    wait;
	end process;
end arch_1;
