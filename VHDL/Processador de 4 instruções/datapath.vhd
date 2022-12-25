library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity datapath is 
port ( i_clk : in std_logic;
		 i_D_addr : in std_logic_vector(7 downto 0);
		 i_D_rd : in std_logic;
       i_D_wr : in std_logic;
		 i_RF_w_data : in std_logic_vector(7 downto 0);
		 i_RF_s1 : in std_logic;
		 i_RF_s0 : in std_logic;
		 i_RF_w_addr :  in std_logic_vector(3 downto 0);
		 i_RF_w_wr : in std_logic;
		 i_RF_Rp_addr : in std_logic_vector(3 downto 0);
		 i_RF_Rp_rd : in std_logic;
		 i_RF_Rq_addr : in std_logic_vector(3 downto 0);
		 i_RF_Rq_rd : in std_logic;
		 i_alu_s0 : in std_logic;
		 o_Q_memory : out std_logic_vector(15 downto 0);
		 o_Q_ula : out std_logic_vector(15 downto 0));
end datapath;

architecture arq_ctrl_unit of datapath is 
component data_memory 
port ( i_clk : in std_logic; 
		 i_addr : in std_logic_vector(7 downto 0);
		 i_rd : in std_logic;
		 i_wr : in std_logic;
		 i_w_data : in std_logic_vector(15 downto 0);
		 o_r_data : out std_logic_vector(15 downto 0));
end component;

component mux_3x1_16bits
port ( i_R2 : in std_logic_vector(15 downto 0);
		 i_R1 : in std_logic_vector(15 downto 0);
		 i_R0 : in std_logic_vector(15 downto 0);
		 i_S1 : in std_logic;
		 i_S0 : in std_logic;
		 o_Q : out std_logic_vector(15 downto 0));
end component;

component register_file
port ( i_clk : in std_logic; 
		 i_w_data : in std_logic_vector(15 downto 0);
		 i_w_addr : in std_logic_vector(3 downto 0);
		 i_w_wr : in std_logic; 
		 i_rp_data : in std_logic_vector(3 downto 0);
		 i_rp_rd : in std_logic; 
		 i_rq_data : in std_logic_vector(3 downto 0);
		 i_rq_rd : in std_logic;
		 o_rp_data : out std_logic_vector(15 downto 0);
		 o_rq_data : out std_logic_vector(15 downto 0));
end component;

component ula
port ( i_CLK : in std_logic;
		 i_A : in std_logic_vector (15 downto 0);
       i_B : in std_logic_vector (15 downto 0);
       i_S0 : in std_logic;
       o_Q : out std_logic_vector(15 downto 0));
end component;

signal w_Rp_data, w_Rq_data, w_ula, w_mux, w_r_data, w_RF_w_data: std_logic_vector(15 downto 0);
begin

		w_RF_w_data (15 downto 8) <= "00000000";
		w_RF_w_data (7 downto 0) <= i_RF_w_data;
		
		u_data_memory : data_memory port map(i_clk, i_D_addr, i_D_rd, i_D_wr, w_Rp_data, w_r_data);
								
		u_mux_3x1_16bits : mux_3x1_16bits port map ( w_RF_w_data, w_r_data, w_ula, i_RF_s1, i_RF_s0, w_mux);
		
		u_register_file : register_file port map(i_clk, w_mux, i_RF_w_addr, i_RF_w_wr, i_RF_Rp_addr, i_RF_Rp_rd, 
															  i_RF_Rq_addr, i_RF_Rq_rd, w_Rp_data, w_Rq_data);
		
		u_ula : ula port map ( i_clk, w_Rp_data, w_Rq_data, i_alu_s0, w_ula);
		
		o_Q_memory <= w_r_data;
		
		o_Q_ula <= w_ula;

end arq_ctrl_unit;