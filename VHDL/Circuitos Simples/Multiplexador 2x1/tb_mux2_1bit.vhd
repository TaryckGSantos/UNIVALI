library ieee;
use ieee.std_logic_1164.all;

entity tb_mux2_1bit is
end tb_mux2_1bit;

architecture arch_1 of tb_mux2_1bit is
component mux2_1bit is
port ( i_SEL : in std_logic; -- Seletor de entradas a ser usada
		i_A : in std_logic; -- Entrada A
		i_B : in std_logic; -- Entrada B
		o_S : out std_logic); -- Saída
end component;

signal w_SEL, w_A, w_B, w_S : std_logic;

begin

	-- Connect DUT
	u_DUT: mux2_1bit port map(i_SEL => w_SEL,
			i_A => w_A,
			i_B => w_B,
			o_S => w_S);
	process
	begin
    -- Casos para que a entrada selecionada seja a entrada A
    w_SEL <= '0';
    w_A <= '0';
    w_B <= '0';
    wait for 1 ns;
    assert(w_S='0') report "Fail @ 000" severity error;
    
    w_SEL <= '0';
    w_A <= '0';
    w_B <= '1';
    wait for 1 ns;
    assert(w_S='0') report "Fail @ 001" severity error;
    
    w_SEL <= '0';
    w_A <= '1';
    w_B <= '0';
    wait for 1 ns;
    assert(w_S='1') report "Fail @ 010" severity error;

    w_SEL <= '0';
    w_A <= '1';
    w_B <= '1';
    wait for 1 ns;
    assert(w_S='1') report "Fail @ 011" severity error;
    
    -- Casos para que a entrada selecionada seja a entrada B
    w_SEL <= '1';
    w_A <= '0';
    w_B <= '0';
    wait for 1 ns;
    assert(w_S='0') report "Fail @ 100" severity error;

    w_SEL <= '1';
    w_A <= '0';
    w_B <= '1';
    wait for 1 ns;
    assert(w_S='1') report "Fail @ 101" severity error;
    
    w_SEL <= '1';
    w_A <= '1';
    w_B <= '0';
    wait for 1 ns;
    assert(w_S='0') report "Fail @ 110" severity error;

    w_SEL <= '1';
    w_A <= '1';
    w_B <= '1';
    wait for 1 ns;
    assert(w_S='1') report "Fail @ 111" severity error;
    
    -- Para limpar as entradas
    w_SEL <= '0';
    w_A <= '0';
    w_B <= '0';
    assert false report "Test done." severity note;
    wait;
  end process;
end arch_1;
