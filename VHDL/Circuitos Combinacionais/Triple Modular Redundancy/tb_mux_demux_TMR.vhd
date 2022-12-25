library IEEE;
use IEEE.std_logic_1164.all;

entity tb_mux_demux_TMR is
end tb_mux_demux_TMR;

architecture arch_1 of tb_mux_demux_TMR is
component mux_demux_TMR is
port (i_SEL  :  in std_logic;
      i_SW0  :  in std_logic;
      i_SW1  :  in std_logic;
      i_BUT1 :  in std_logic;
      i_BUT2 :  in std_logic;
      i_BUT3 :  in std_logic;
      o_LED0 :  out std_logic;
      o_LED1 :  out std_logic);
end component;

signal w_SEL, w_SW0, w_SW1,w_BUT1,w_BUT2,w_BUT3, w_LED0, w_LED1: std_logic;
begin

     u_DUT : mux_demux_TMR port map(i_SEL  => w_SEL,
                                   i_SW0   => w_SW0,
                                   i_SW1   => w_SW1,
                                   i_BUT1  => w_BUT1,
                                   i_BUT2  => w_BUT2,
                                   i_BUT3  => w_BUT3,
                                   o_LED0  => w_LED0,
                                   o_LED1  => w_LED1);
                                   
process
begin

    w_SEL <= '0';
    w_SW0 <= '0';
    w_SW1 <= '0';
    w_BUT1<= '0';
    w_BUT2<= '0';
    w_BUT3<= '0';
    wait for 1 ns;
    assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 000000" severity error;
  
--Botoes desativados    
  
  	w_SEL <= '0';
    w_SW0 <= '1';
    w_SW1 <= '0';
    w_BUT1<= '0';
    w_BUT2<= '0';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '1' and w_LED1 = '0') report "Fail @ 010000" severity error;
  
  	w_SEL <= '0';
    w_SW0 <= '0';
    w_SW1 <= '1';
    w_BUT1<= '0';
    w_BUT2<= '0';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 001000" severity error;
  
  	w_SEL <= '0';
    w_SW0 <= '1';
    w_SW1 <= '1';
    w_BUT1<= '0';
    w_BUT2<= '0';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '1' and w_LED1 = '0') report "Fail @ 011000" severity error;
  
  	w_SEL <= '1';
    w_SW0 <= '1';
    w_SW1 <= '0';
    w_BUT1<= '0';
    w_BUT2<= '0';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 110000" severity error;
  
  	w_SEL <= '1';
    w_SW0 <= '0';
    w_SW1 <= '1';
    w_BUT1<= '0';
    w_BUT2<= '0';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '1') report "Fail @ 101000" severity error;
  
  	w_SEL <= '1';
    w_SW0 <= '1';
    w_SW1 <= '1';
    w_BUT1<= '0';
    w_BUT2<= '0';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '1') report "Fail @ 111000" severity error;
  
-- Apenas os botes ligados   
  
  	w_SEL <= '0';
    w_SW0 <= '0';
    w_SW1 <= '0';
    w_BUT1<= '1';
    w_BUT2<= '0';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 000100"
severity error;
  
  	w_SEL <= '0';
    w_SW0 <= '0';
    w_SW1 <= '0';
    w_BUT1<= '0';
    w_BUT2<= '1';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 000010" severity error;
  
  	w_SEL <= '0';
    w_SW0 <= '0';
    w_SW1 <= '0';
    w_BUT1<= '0';
    w_BUT2<= '0';
    w_BUT3<= '1';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 000001" severity error;
  
  	w_SEL <= '0';
    w_SW0 <= '0';
    w_SW1 <= '0';
    w_BUT1<= '1';
    w_BUT2<= '1';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '1' and w_LED1 = '0') report "Fail @ 000110" severity error;
  
  	w_SEL <= '0';
    w_SW0 <= '0';
    w_SW1 <= '0';
    w_BUT1<= '1';
    w_BUT2<= '0';
    w_BUT3<= '1';
    wait for 1 ns;
  assert(w_LED0 = '1' and w_LED1 = '0') report "Fail @ 000101" severity error;
  
  	w_SEL <= '0';
    w_SW0 <= '0';
    w_SW1 <= '0';
    w_BUT1<= '0';
    w_BUT2<= '1';
    w_BUT3<= '1';
    wait for 1 ns;
  assert(w_LED0 = '1' and w_LED1 = '0') report "Fail @ 000011" severity error;
  
-- Botao mais seletor
  
  
  	w_SEL <= '1';
    w_SW0 <= '0';
    w_SW1 <= '0';
    w_BUT1<= '1';
    w_BUT2<= '0';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 100100"
severity error;
  
  	w_SEL <= '1';
    w_SW0 <= '0';
    w_SW1 <= '0';
    w_BUT1<= '0';
    w_BUT2<= '1';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 100010" severity error;
  
  	w_SEL <= '1';
    w_SW0 <= '0';
    w_SW1 <= '0';
    w_BUT1<= '0';
    w_BUT2<= '0';
    w_BUT3<= '1';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 100001" severity error;
  
  	w_SEL <= '1';
    w_SW0 <= '0';
    w_SW1 <= '0';
    w_BUT1<= '1';
    w_BUT2<= '1';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '1') report "Fail @ 100110" severity error;
  
  	w_SEL <= '1';
    w_SW0 <= '0';
    w_SW1 <= '0';
    w_BUT1<= '1';
    w_BUT2<= '0';
    w_BUT3<= '1';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '1') report "Fail @ 100101" severity error;
  
  	w_SEL <= '1';
    w_SW0 <= '0';
    w_SW1 <= '0';
    w_BUT1<= '0';
    w_BUT2<= '1';
    w_BUT3<= '1';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '1') report "Fail @ 100011" severity error;
  
  -- Botoes mais SW0 seletor desativado
  
  
  	w_SEL <= '0';
    w_SW0 <= '1';
    w_SW1 <= '0';
    w_BUT1<= '1';
    w_BUT2<= '0';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '1' and w_LED1 = '0') report "Fail @ 010100" severity error;
  	
  	w_SEL <= '0';
    w_SW0 <= '1';
    w_SW1 <= '0';
    w_BUT1<= '0';
    w_BUT2<= '1';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '1' and w_LED1 = '0') report "Fail @ 010010" severity error;
  
  	w_SEL <= '0';
    w_SW0 <= '1';
    w_SW1 <= '0';
    w_BUT1<= '0';
    w_BUT2<= '0';
    w_BUT3<= '1';
    wait for 1 ns;
  assert(w_LED0 = '1' and w_LED1 = '0') report "Fail @ 010001" severity error;
  
  	w_SEL <= '0';
    w_SW0 <= '1';
    w_SW1 <= '0';
    w_BUT1<= '1';
    w_BUT2<= '1';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 010110" severity error;
  
  	w_SEL <= '0';
    w_SW0 <= '1';
    w_SW1 <= '0';
    w_BUT1<= '1';
    w_BUT2<= '0';
    w_BUT3<= '1';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 010101" severity error;
  
  	w_SEL <= '0';
    w_SW0 <= '1';
    w_SW1 <= '0';
    w_BUT1<= '0';
    w_BUT2<= '1';
    w_BUT3<= '1';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 010011" severity error;
  
-- Botoes mais SW0 seletor ativado
  
  	w_SEL <= '1';
    w_SW0 <= '1';
    w_SW1 <= '0';
    w_BUT1<= '1';
    w_BUT2<= '0';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 110100" severity error;
  
  	w_SEL <= '1';
    w_SW0 <= '1';
    w_SW1 <= '0';
    w_BUT1<= '0';
    w_BUT2<= '1';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 110010" severity error;
  
  	w_SEL <= '1';
    w_SW0 <= '1';
    w_SW1 <= '0';
    w_BUT1<= '0';
    w_BUT2<= '0';
    w_BUT3<= '1';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 110001" severity error;
  
  	w_SEL <= '1';
    w_SW0 <= '1';
    w_SW1 <= '0';
    w_BUT1<= '1';
    w_BUT2<= '1';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '1') report "Fail @ 110110" severity error;
  
  	w_SEL <= '1';
    w_SW0 <= '1';
    w_SW1 <= '0';
    w_BUT1<= '1';
    w_BUT2<= '0';
    w_BUT3<= '1';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '1') report "Fail @ 110101" severity error;
  
  	w_SEL <= '1';
    w_SW0 <= '1';
    w_SW1 <= '0';
    w_BUT1<= '0';
    w_BUT2<= '1';
    w_BUT3<= '1';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '1') report "Fail @ 110011" severity error;
  
-- Botoes mais SW1 seletor desativado
  
  	w_SEL <= '0';
    w_SW0 <= '0';
    w_SW1 <= '1';
    w_BUT1<= '1';
    w_BUT2<= '0';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 001100" severity error;
  
  	w_SEL <= '0';
    w_SW0 <= '0';
    w_SW1 <= '1';
    w_BUT1<= '0';
    w_BUT2<= '1';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 001010" severity error;
  
  	w_SEL <= '0';
    w_SW0 <= '0';
    w_SW1 <= '1';
    w_BUT1<= '0';
    w_BUT2<= '1';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 001010" severity error;
  
  	w_SEL <= '0';
    w_SW0 <= '0';
    w_SW1 <= '1';
    w_BUT1<= '0';
    w_BUT2<= '0';
    w_BUT3<= '1';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 001001" severity error;
  
  	w_SEL <= '0';
    w_SW0 <= '0';
    w_SW1 <= '1';
    w_BUT1<= '1';
    w_BUT2<= '1';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '1' and w_LED1 = '0') report "Fail @ 001110" severity error;
  
  	w_SEL <= '0';
    w_SW0 <= '0';
    w_SW1 <= '1';
    w_BUT1<= '1';
    w_BUT2<= '0';
    w_BUT3<= '1';
    wait for 1 ns;
  assert(w_LED0 = '1' and w_LED1 = '0') report "Fail @ 001101" severity error;
  
  	w_SEL <= '0';
    w_SW0 <= '0';
    w_SW1 <= '1';
    w_BUT1<= '0';
    w_BUT2<= '1';
    w_BUT3<= '1';
    wait for 1 ns;
  assert(w_LED0 = '1' and w_LED1 = '0') report "Fail @ 001011" severity error;
  
-- Botoes mais SW1 seletor ativo
  
  	w_SEL <= '1';
    w_SW0 <= '0';
    w_SW1 <= '1';
    w_BUT1<= '1';
    w_BUT2<= '0';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '1') report "Fail @ 101100" severity error;
  
 	w_SEL <= '1';
    w_SW0 <= '0';
    w_SW1 <= '1';
    w_BUT1<= '0';
    w_BUT2<= '1';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '1') report "Fail @ 101010" severity error;
  
  	w_SEL <= '1';
    w_SW0 <= '0';
    w_SW1 <= '1';
    w_BUT1<= '0';
    w_BUT2<= '0';
    w_BUT3<= '1';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '1') report "Fail @ 101001" severity error;
  
  	w_SEL <= '1';
    w_SW0 <= '0';
    w_SW1 <= '1';
    w_BUT1<= '1';
    w_BUT2<= '1';
    w_BUT3<= '0';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 101110" severity error;
  
  	w_SEL <= '1';
    w_SW0 <= '0';
    w_SW1 <= '1';
    w_BUT1<= '1';
    w_BUT2<= '0';
    w_BUT3<= '1';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 101101" severity error;
  
  	w_SEL <= '1';
    w_SW0 <= '0';
    w_SW1 <= '1';
    w_BUT1<= '0';
    w_BUT2<= '1';
    w_BUT3<= '1';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 101011" severity error;
  
  	w_SEL <= '1';
    w_SW0 <= '1';
    w_SW1 <= '1';
    w_BUT1<= '1';
    w_BUT2<= '1';
    w_BUT3<= '1';
    wait for 1 ns;
  assert(w_LED0 = '0' and w_LED1 = '0') report "Fail @ 111111" severity error;
  	
  	w_SEL <= '0';
    w_SW0 <= '0';
    w_SW1 <= '0';
    w_BUT1<= '0';
    w_BUT2<= '0';
    w_BUT3<= '0';
  assert false report "Test done." severity note;
  wait;
  end process;
end arch_1;
