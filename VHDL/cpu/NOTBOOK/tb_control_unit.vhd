library IEEE;
use IEEE.std_logic_1164.all;

entity tb_control_unit is
end tb_control_unit;

architecture arch_tb_ctrl_unit of tb_control_unit is

component control_unit is
port ( i_clk : in std_logic;
		 i_reset : in std_logic;
		 o_D_addr : out std_logic_vector(7 downto 0);
		 o_D_rd : out std_logic;
		 o_D_wr : out std_logic;
		 o_RF_w_data : out std_logic_vector(7 downto 0);
		 o_RF_s1 : out std_logic;
		 o_RF_s0 : out std_logic;
		 o_RF_w_addr :  out std_logic_vector(3 downto 0);
		 o_RF_w_wr : out std_logic;
		 o_RF_Rp_addr : out std_logic_vector(3 downto 0);
		 o_RF_Rp_rd : out std_logic;
		 o_RF_Rq_addr : out std_logic_vector(3 downto 0);
		 o_RF_Rq_rd : out std_logic;
		 o_alu_s0 : out std_logic;
		 o_ctrl_unit : out std_logic_vector(15 downto 0);
		 o_pc : out std_logic_vector(15 downto 0));
end component;

signal w_clk, w_reset, w_D_rd, w_D_wr, w_RF_s1, w_RF_s0, w_RF_w_wr,
		 w_RF_Rp_rd, w_RF_Rq_rd, w_alu_s0: std_logic;
signal w_D_addr, w_RF_w_data : std_logic_vector(7 downto 0);
signal w_RF_w_addr, w_RF_Rp_addr, w_RF_Rq_addr : std_logic_vector(3 downto 0);
signal w_Q_ctrl_unit, w_pc : std_logic_vector(15 downto 0);
begin
			u_DUT : control_unit port map ( i_clk => w_clk,
												i_reset => w_reset,
												o_D_addr => w_D_addr,
												o_D_rd => w_D_rd,
											   o_D_wr => w_D_wr,
												o_RF_w_data => w_RF_w_data,
												o_RF_s1 => w_RF_s1,
												o_RF_s0 => w_RF_s0,
												o_RF_w_addr => w_RF_w_addr,
												o_RF_w_wr => w_RF_w_wr,
												o_RF_Rp_addr => w_RF_Rp_addr,
												o_RF_Rp_rd => w_RF_Rp_rd,
												o_RF_Rq_addr => w_RF_Rq_addr,
												o_RF_Rq_rd => w_RF_Rq_rd,
												o_alu_s0 => w_alu_s0,
												o_ctrl_unit => w_Q_ctrl_unit,
												o_pc => w_pc);
		process
		begin
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1';
		wait for 1 ns;
		
		w_reset <= '1';
		w_clk <= '0';
		wait for 1 ns;
			
		w_reset <= '1';
		w_clk <= '1';
		wait for 1 ns;
		
		w_reset <= '1';
		w_clk <= '0';
		wait for 1 ns;
			
		w_reset <= '1';
		w_clk <= '1';
		wait for 1 ns;
		
		---------------
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
			
		w_reset <= '0';
		w_clk <= '1'; 
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
			
		w_reset <= '0';
		w_clk <= '1'; -- 2
		wait for 1 ns;
			
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 3
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 4
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 5
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 6
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 7
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 8
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 9
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 10
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 11
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 12
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 13
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 14
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 15
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 16
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
			
		w_reset <= '0';
		w_clk <= '1'; 
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
			
		w_reset <= '0';
		w_clk <= '1'; -- 2
		wait for 1 ns;
			
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 3
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 4
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 5
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 6
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 7
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 8
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 9
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 10
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 11
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 12
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 13
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 14
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 15
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 16
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
			
		w_reset <= '0';
		w_clk <= '1'; 
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
			
		w_reset <= '0';
		w_clk <= '1'; -- 2
		wait for 1 ns;
			
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 3
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 4
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 5
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 6
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 7
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 8
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 9
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 10
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 11
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 12
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 13
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 14
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 15
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 16
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
			
		w_reset <= '0';
		w_clk <= '1'; 
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
			
		w_reset <= '0';
		w_clk <= '1'; -- 2
		wait for 1 ns;
			
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 3
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 4
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 5
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 6
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 7
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 8
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 9
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 10
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 11
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 12
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 13
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 14
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 15
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '1'; -- 16
		wait for 1 ns;
		
		w_reset <= '0';
		w_clk <= '0';
		wait for 1 ns;
		
		end process;
end arch_tb_ctrl_unit;
