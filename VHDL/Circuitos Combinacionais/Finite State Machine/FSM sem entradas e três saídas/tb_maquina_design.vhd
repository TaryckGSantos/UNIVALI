library ieee;
use ieee.std_logic_1164.all;

entity tb_maquina_design is
end tb_maquina_design;

architecture arch_1 of tb_maquina_design is 

component maquina_design is
  port (i_CLR : in std_logic;
  	   i_CLK : in std_logic;
        o_QX  : out std_logic;
        o_QY  : out std_logic;
        o_QZ  : out std_logic);
end component;

signal w_CLR, w_CLK, w_QX, w_QY, w_QZ : std_logic;
begin 

u_DUT: maquina_design port map (i_CLR => w_CLR,
  						  i_CLK => w_CLK,
                                o_QX  => w_QX,
                                o_QY  => w_QY,
                                o_QZ  => w_QZ);

process
	begin 
                                  
 -- RESET
 
 w_CLR <= '0';
 w_CLK <= '0';
 wait for 1 ns;
 assert(w_CLR <='0' and w_CLK <='0') report "Fail @ 00" severity error;
 
 w_CLR <= '1';
 wait for 1 ns;
 
 w_CLR <= '0';
 wait for 1 ns;
 --CLOCK
 
 w_CLK <= '1';
 wait for 1 ns;
 assert(w_CLK <='0') report "Fail @ 1" severity error;
 
 w_CLK <= '0';
 wait for 1 ns;
 assert(w_CLK <='0') report "Fail @ 0" severity error;
 
 w_CLK <= '1';
 wait for 1 ns;
 assert(w_CLK <='0') report "Fail @ 1" severity error;
 
 w_CLK <= '0';
 wait for 1 ns;
 assert(w_CLK <='0') report "Fail @ 0" severity error;
 
 w_CLK <= '1';
 wait for 1 ns;
 assert(w_CLK <='0') report "Fail @ 1" severity error;
 w_CLK <= '0';
 wait for 1 ns;
 assert(w_CLK <='0') report "Fail @ 0" severity error;
 
 w_CLK <= '1';
 wait for 1 ns;
 assert(w_CLK <='0') report "Fail @ 1" severity error;
 
 w_CLK <= '0';
 wait for 1 ns;
 assert(w_CLK <='0') report "Fail @ 0" severity error;
 
 w_CLR <= '1';
 wait;
end process;
end arch_1;
