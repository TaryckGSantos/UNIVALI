library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity cpu_top is 
port ( i_clk : in std_logic;
		 i_reset : in std_logic;
		 o_control_unit : out std_logic_vector(15 downto 0);
		 o_program_counter : out std_logic_vector(15 downto 0);
		 o_data_memory : out std_logic_vector(15 downto 0);
		 o_ula : out std_logic_vector(15 downto 0));
end cpu_top;

architecture arq_cpu_top of cpu_top is 

component control_unit
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

component datapath
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
end component;

signal w_D_addr, w_RF_w_data : std_logic_vector(7 downto 0);
signal w_RF_w_addr, w_RF_Rp_addr, w_RF_Rq_addr : std_logic_vector(3 downto 0);
signal w_D_rd, w_D_wr, w_RF_s1, w_RF_s0, w_RF_w_wr, w_RF_Rp_rd, w_RF_Rq_rd, w_alu_s0 : std_logic;

begin 

		u_datapath : datapath port map (i_clk , w_D_addr, w_D_rd, w_D_wr, w_RF_w_data, w_RF_s1, w_RF_s0, w_RF_w_addr,
												  w_RF_w_wr, w_RF_Rp_addr, w_RF_Rp_rd, w_RF_Rq_addr, w_RF_Rq_rd, w_alu_s0, o_data_memory, o_ula);
		
		u_control_unit : control_unit port map (i_clk, i_reset, w_D_addr, w_D_rd, w_D_wr, w_RF_w_data, w_RF_s1, 
															 w_RF_s0, w_RF_w_addr, w_RF_w_wr, w_RF_Rp_addr, w_RF_Rp_rd, 
															 w_RF_Rq_addr, w_RF_Rq_rd, w_alu_s0, o_control_unit, o_program_counter);

end arq_cpu_top;