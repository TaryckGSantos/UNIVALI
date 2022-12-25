library ieee;
use ieee.std_logic_1164.all;

entity tb_decod4_2bit is
end tb_decod4_2bit;

architecture arch_1 of tb_decod4_2bit is

component decod4_2bit is
port (i_A : in std_logic_vector(3 downto 0); -- Seletor de entradas
	  o_R : out std_logic; -- Saída A
	  o_S : out std_logic); -- Saída B
end component;

signal w_A : std_logic_vector(3 downto 0); 
signal w_S, w_R : std_logic;

begin
		-- Connect DUT
        u_DUT: decod4_2bit port map(i_A => w_A,
                                    o_R => w_R,
                                    o_S => w_S);
        process
        begin
    
-- Casos para que a chave seletora esteja em 0
        w_A(0) <= '0';
        w_A(1) <= '0';
        w_A(2) <= '0';
        w_A(3) <= '0';
        wait for 1 ns;
        assert(w_R <= '0' and w_S <= '0') report "Fail @ 00" severity error;

        w_A(0) <= '1';
        w_A(1) <= '0';
        w_A(2) <= '0';
        w_A(3) <= '0';
        wait for 1 ns;
        assert(w_R <= '0' and w_S <= '0') report "Fail @ 00" severity error;
   
		w_A(0) <= '0';
        w_A(1) <= '1';
        w_A(2) <= '0';
        w_A(3) <= '0';
        wait for 1 ns;
        assert(w_R = '0' and w_S = '1') report "Fail @ 01" severity error;

        w_A(0) <= '1';
        w_A(1) <= '1';
        w_A(2) <= '0';
        w_A(3) <= '0';
        wait for 1 ns;
        assert(w_R = '0' and w_S = '0') report "Fail @ 00" severity error;

        w_A(0) <= '0';
        w_A(1) <= '0';
        w_A(2) <= '1';
        w_A(3) <= '0';
        wait for 1 ns;
        assert(w_R = '1' and w_S = '0') report "Fail @ 10" severity error;

        w_A(0) <= '1';
        w_A(1) <= '0';
        w_A(2) <= '1';
        w_A(3) <= '0';
        wait for 1 ns;
        assert(w_R = '0' and w_S = '0') report "Fail @ 00" severity error;

        w_A(0) <= '0';
        w_A(1) <= '1';
        w_A(2) <= '1';
        w_A(3) <= '0';
        wait for 1 ns;
        assert(w_R = '0' and w_S = '0') report "Fail @ 00" severity error;

        w_A(0) <= '1';
        w_A(1) <= '1';
        w_A(2) <= '1';
        w_A(3) <= '0';
        wait for 1 ns;
        assert(w_R = '0' and w_S = '0') report "Fail @ 00" severity error;

        w_A(0) <= '0';
        w_A(1) <= '0';
        w_A(2) <= '0';
        w_A(3) <= '1';
        wait for 1 ns;
        assert(w_R = '1' and w_S = '1') report "Fail @ 11" severity error;

        w_A(0) <= '1';
        w_A(1) <= '0';
        w_A(2) <= '0';
        w_A(3) <= '1';
        wait for 1 ns;
        assert(w_R = '0' and w_S = '0') report "Fail @ 00" severity error;

        w_A(0) <= '0';
        w_A(1) <= '1';
        w_A(2) <= '0';
        w_A(3) <= '1';
        wait for 1 ns;
        assert(w_R = '0' and w_S = '0') report "Fail @ 00" severity error;

        w_A(0) <= '1';
        w_A(1) <= '1';
        w_A(2) <= '0';
        w_A(3) <= '1';
        wait for 1 ns;
        assert(w_R = '0' and w_S = '0') report "Fail @ 00" severity error;

        w_A(0) <= '0';
        w_A(1) <= '0';
        w_A(2) <= '1';
        w_A(3) <= '1';
        wait for 1 ns;
        assert(w_R = '0' and w_S = '0') report "Fail @ 00" severity error;

        w_A(0) <= '1';
        w_A(1) <= '0';
        w_A(2) <= '1';
        w_A(3) <= '1';
        wait for 1 ns; 
        assert(w_R = '0' and w_S = '0') report "Fail @ 00" severity error;

        w_A(0) <= '0';
        w_A(1) <= '1';
        w_A(2) <= '1';
        w_A(3) <= '1';
        wait for 1 ns;
        assert(w_R = '0' and w_S = '0') report "Fail @ 00" severity error;

		w_A(0) <= '1';
        w_A(1) <= '1';
        w_A(2) <= '1';
        w_A(3) <= '1';
        wait for 1 ns;
        assert(w_R = '0' and w_S = '0') report "Fail @ 00" severity error;


 -- Para limpar as entradas
        w_A(0) <= '0';
        w_A(1) <= '0';
        w_A(2) <= '0';
        w_A(3) <= '0';
    	assert false report "Test done." severity note;
   		wait;
 	end process;
end arch_1;
