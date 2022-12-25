library ieee;
use ieee.std_logic_1164.all;

entity control_unit is 
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
end control_unit;

architecture arq_ctrl_unit of control_unit is 
component controller 
port ( i_clk  : in std_logic;
		 i_reset  : in std_logic;
		 i_go : in std_logic := '1';
		 i_IR_in  : in std_logic_vector(15 downto 0);
		 o_D_addr : out std_logic_vector(7 downto 0);
		 o_D_rd : out std_logic;
		 o_D_wr : out std_logic;  
		 o_RF_w_data : out std_logic_vector(7 downto 0); 
		 o_RF_s1 : out std_logic;
		 o_RF_s0 : out std_logic;
		 o_RF_w_addr  :  out std_logic_vector(3 downto 0);
		 o_RF_w_wr : out std_logic;
		 o_RF_Rp_addr  : out std_logic_vector(3 downto 0);
		 o_RF_Rp_rd : out std_logic;
		 o_RF_Rq_addr  : out std_logic_vector(3 downto 0);
		 o_RF_Rq_rd : out std_logic;
		 o_alu_s0 : out std_logic;
		 o_PC_clr: out std_logic;
		 o_PC_inc: out std_logic;
		 o_I_rd: out std_logic;
		 o_IR_ld: out std_logic);
end component;

component program_counter
port ( i_clk : in std_logic;
		 i_pc_clr : in std_logic;
		 i_pc_inc : in std_logic;
		 o_pc_Q : out std_logic_vector(15 downto 0));
end component;

component instruction_register
port ( i_clk : in std_logic;
		 i_ir_ld : in std_logic;
		 i_ir_D : in std_logic_vector(15 downto 0);
		 o_ir_Q : out std_logic_vector(15 downto 0));
end component;

component instruction_memory
port ( i_clk	: in std_logic;
	    i_rd	: in std_logic;
		 i_addr	: in std_logic_vector(15 downto 0);
		 o_q		: out std_logic_vector(15 downto 0));
end component;

signal w_pc_data, w_im_data, w_ir_data : std_logic_vector(15 downto 0);
signal w_D_addr, w_RF_w_data : std_logic_vector(7 downto 0);
signal w_RF_w_addr, w_RF_Rp_addr, w_RF_Rq_addr : std_logic_vector(3 downto 0);
signal w_D_rd, w_D_wr, w_RF_s1, w_RF_s0, w_RF_w_wr, w_RF_Rp_rd, w_RF_Rq_rd, 
		 w_alu_s0, w_PC_clr, w_PC_inc, w_I_rd, w_IR_ld, w_go : std_logic;
begin

		u_controller : controller port map(i_clk, i_reset, w_go, w_ir_data, o_D_addr, o_D_rd, o_D_wr, o_RF_w_data, 
													  o_RF_s1, o_RF_s0, o_RF_w_addr, o_RF_w_wr, o_RF_Rp_addr, o_RF_Rp_rd, 
													  o_RF_Rq_addr, o_RF_Rq_rd, o_alu_s0, w_PC_clr, w_PC_inc, w_I_rd, w_IR_ld);
													  
		u_program_counter : program_counter port map ( i_clk, w_PC_clr, w_pc_inc, w_pc_data );
		
		u_instruction_memory : instruction_memory port map(i_clk, w_I_rd, w_pc_data, w_im_data );
		
		u_instruction_register : instruction_register port map ( i_clk, w_IR_ld, w_im_data, w_ir_data );
		
		o_ctrl_unit <= w_im_data;
		
		o_pc <= w_pc_data;

end arq_ctrl_unit;