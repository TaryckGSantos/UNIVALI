library IEEE;
use IEEE.std_logic_1164.all;

entity tb_mux_demux is
end tb_mux_demux;

architecture arch_1 of tb_mux_demux is 
component mux_demux is
port ( i_SEL  :  in std_logic;
       i_SW0  :  in std_logic;
       i_SW1  :  in std_logic;
       o_LED0 :  out std_logic;
       o_LED1 :  out std_logic);
end component;

signal w_SEL, w_SW0, w_SW1, w_LED0, w_LED1: std_logic;
begin

	u_DUT: mux_demux port map(i_SEL   => w_SEL,
                              i_SW0   => w_SW0,
                              i_SW1   => w_SW1,
                              o_LED0  => w_LED0,
                              o_LED1  => w_LED1);
                              
process
begin

  w_SEL <= '0';
  w_SW0 <= '0';
  w_SW1 <= '0';
  wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 000" severity error;
  
  
  w_SEL <= '0';
  w_SW0 <= '1';
  w_SW1 <= '0';
  wait for 1 ns;
  assert(w_LED0 = '1' and w_LED1 = '0') report "Fail @ 010" severity error;
  
  w_SEL <= '1';
  w_SW0 <= '1';
  w_SW1 <= '0';
  wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 110" severity error;
  
  w_SEL <= '0';
  w_SW0 <= '0';
  w_SW1 <= '1';
  wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 001" severity error;
  
  w_SEL <= '1';
  w_SW0 <= '0';
  w_SW1 <= '1';
  wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '1') report "Fail @ 101" severity error;
  
  w_SEL <= '1';
  w_SW0 <= '1';
  w_SW1 <= '1';
  wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '1') report "Fail @ 111" severity error;
  
  w_SEL <= '0';
  w_SW0 <= '0';
  w_SW1 <= '0';
  assert false report "Test done." severity note;
  wait;
  end process;
end arch_1;
