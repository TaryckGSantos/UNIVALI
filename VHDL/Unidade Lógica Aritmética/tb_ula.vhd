library ieee;
use ieee.std_logic_1164.all;

entity tb_ula is
end tb_ula;

architecture arch_1 of tb_ula is

component ula is
port (i_A : in std_logic_vector(3 downto 0); 
	  i_B : in std_logic_vector(3 downto 0);
      i_XYZ : in std_logic_vector(2 downto 0);
      i_CLK : in std_logic;
      i_EN : in std_logic;
	  o_S : out std_logic_vector(3 downto 0)); 
end component;

signal w_A, w_B,w_S: std_logic_vector(3 downto 0);
signal w_XYZ: std_logic_vector(2 downto 0);
signal w_CLK, w_EN: std_logic;

begin
		
		u_DUT: ula port map (i_A => w_A,
			                 i_B => w_B,
                             i_XYZ => w_XYZ,
                             i_CLK => w_CLK,
                             i_EN => w_EN,
			                 o_S => w_S);
        process
      	begin
      	
      	w_A <= "1000";
        w_B <= "0010";
        w_XYZ <= "000";
        w_CLK <= '0'; 
        w_EN <= '1';
        wait for 1 ns;
        
        w_CLK <= '1';
        w_S <= "1010";
        wait for 1 ns;
        
        w_XYZ <= "001";
        w_CLK <= '0';
        wait for 1 ns;
        
        w_CLK <= '1';
        w_S <= "0110";
        wait for 1 ns;
        
        w_XYZ <= "010";
        w_CLK <= '0';
        wait for 1 ns;
        
        w_CLK <= '1';
        w_S <= "1001";
        wait for 1 ns;
        
        w_XYZ <= "011";
        w_CLK <= '0';
        wait for 1 ns;
        
        w_CLK <= '1';
        w_S <= "1000";
        wait for 1 ns;
        
        w_XYZ <= "100";
        w_CLK <= '0';
        wait for 1 ns;
        
        w_CLK <= '1';
        w_S <= "1010";
        wait for 1 ns;
        
        w_XYZ <= "101";
        w_CLK <= '0';
        wait for 1 ns;
        
        w_CLK <= '1';
        w_S <= "1010";
        wait for 1 ns;
        
        w_XYZ <= "110";
        w_CLK <= '0';
        wait for 1 ns;
        
        w_CLK <= '1';
        w_S <= "1010";
        wait for 1 ns;
        
        w_XYZ <= "111";
        w_CLK <= '0';
        wait for 1 ns;
        
        w_CLK <= '1';
        w_S <= "0101";
        wait for 1 ns;
        
        w_A <= "0000";
        w_B <= "0000";
        w_XYZ <= "000";
        w_CLK <= '0'; 
        w_EN <= '0';
        assert false report "Test done." severity note;
        wait;
	end process;
end arch_1;
