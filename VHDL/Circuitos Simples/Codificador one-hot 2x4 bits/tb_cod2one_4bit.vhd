library ieee;
use ieee.std_logic_1164.all;

entity tb_cod2one_4bit is
end tb_cod2one_4bit;

architecture arch_1 of tb_cod2one_4bit is
component cod2one_4bit is
port (i_A : in std_logic; -- Seletor de entradas a ser usada
	 i_B : in std_logic; -- Saída A
	 o_S : out std_logic_vector(3 downto 0)); -- Saída B
end component;

signal w_A, w_B : std_logic;
signal w_S : std_logic_vector(3 downto 0); 

begin
		-- Connect DUT
		u_DUT: cod2one_4bit port map(i_A => w_A,
			                        i_B => w_B,
			                        o_S => w_S);
          process
      	begin
      	
      	w_A <= '0';
          w_B <= '0';
          wait for 1 ns;
    	     assert(w_S(3) = '0' and w_S(2) = '0' and w_S(1) = '0' and w_S(0) = '1') report "Fail @ 0001" severity error;

          w_A <= '0';
          w_B <= '1';
          wait for 1 ns;
          assert(w_S(3) = '0' and w_S(2) = '0' and w_S(1) = '1' and w_S(0) = '0') report "Fail @ 0010" severity error;

          w_A <= '1';
          w_B <= '0';
          wait for 1 ns;
          assert(w_S(3) = '0' and w_S(2) = '1' and w_S(1) = '0' and w_S(0) = '0') report "Fail @ 0100" severity error;

          w_A <= '1';
          w_B <= '1';
          wait for 1 ns;
          assert(w_S(3) = '1' and w_S(2) = '0' and w_S(1) = '0' and w_S(0) = '0') report "Fail @ 1000" severity error;
          -- Para limpar as entradas
          w_A <= '0';
          w_B <= '0';
          assert false report "Test done." severity note;
          wait;
	end process;
end arch_1;
