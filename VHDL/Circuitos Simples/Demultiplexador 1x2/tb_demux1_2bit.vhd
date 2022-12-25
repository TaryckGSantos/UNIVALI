library ieee;
use ieee.std_logic_1164.all;

entity tb_demux1_2bit is
end tb_demux1_2bit;

architecture arch_1 of tb_demux1_2bit is
component demux1_2bit is
port ( i_SEL : in std_logic; -- Seletor de entradas a ser usada
		i_S : in std_logic; -- Entrada
		o_A : out std_logic; -- Saída A
		o_B : out std_logic); -- Saída B
end component;

signal w_SEL, w_S, w_A, w_B : std_logic;

begin
      	u_DUT: demux1_2bit port map(i_SEL => w_SEL,
			                        i_S => w_S,
			                        o_A => w_A,
			                        o_B => w_B);
process
begin
		-- Casos para que a chave seletora esteja em 0
		w_SEL <= '0';
        w_S <='0';
        wait for 1 ns;
        assert(w_A = '0' and w_B = '0') report "Fail @ 00" severity error;
    
        w_SEL <= '0';
        w_S <='1';
        wait for 1 ns;
        assert(w_A = '1' and w_B = '0') report "Fail @ 10" severity error;

        -- Casos para que a chave seletora esteja em 1
        w_SEL <= '1';
        w_S <='0';
        wait for 1 ns;
        assert(w_A = '0' and w_B = '0') report "Fail @ 00" severity error;
    

        w_SEL <= '1';
        w_S <='1';
        wait for 1 ns;
        assert(w_A = '0' and w_B = '1') report "Fail @ 01" severity error;

        -- Para limpar as entradas
        w_SEL <= '0';
        w_S <= '0';
        assert false report "Test done." severity note;
        wait;
	end process;
end arch_1;
