library ieee;
use ieee.std_logic_1164.all;

entity controller is
	port (  i_clk  : in std_logic;
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
end controller;

architecture arc_ctl of controller is
component decodificador 
port ( i_entrada : in std_logic_vector(15 downto 0);
		 o_instrucao : out std_logic_vector(3 downto 0);
		 o_Ra : out std_logic_vector(3 downto 0);
		 o_Rb : out std_logic_vector(3 downto 0);
		 o_Rc : out std_logic_vector(3 downto 0);
		 o_D : out std_logic_vector(7 downto 0));
end component;

type estado is (inicio, busca, decodificacao, carregar, 
					 armazenar, somar, carregar_constante);
signal estado_atual: estado;
signal w_operacao, w_Ra, w_Rb, w_Rc :  std_logic_vector(3 downto 0);
signal w_D: std_logic_vector(7 downto 0);
begin 
		
		u_decodificador: decodificador port map( i_IR_in, w_operacao, w_Ra, w_Rb, w_Rc, w_D);
		
		u_controller1: process(i_reset, i_clk)
		begin 
		
				if (rising_edge(i_clk)) then
						if i_reset = '1' then 
							estado_atual <= inicio;
						else 
								case estado_atual is
										when inicio =>
												
												if i_go = '1' then 
														estado_atual <= busca;
												else 
														estado_atual <= inicio;
												end if;
										
										when busca =>
												
												if i_go = '1' then 
													estado_atual <= decodificacao;
												else 
													estado_atual <= busca;
												end if;
										
										when decodificacao =>
												
												if i_go = '1' then
														if w_operacao = "0000" then 
																estado_atual <= carregar;
														elsif w_operacao = "0001" then 
																estado_atual <= armazenar;
														elsif w_operacao = "0010" then 
																estado_atual <= somar;
														elsif w_operacao = "0011" then 
																estado_atual <= carregar_constante;
														else 
																null;
														end if;
												else 
														estado_atual <= decodificacao;
												end if;
												
										when carregar =>
												
												if i_go = '1' then
														estado_atual <= busca;
												else 
														estado_atual <= carregar;
												end if;
												
										when armazenar =>
												
												if i_go = '1' then
														estado_atual <= busca;
												else 
														estado_atual <= armazenar;
												end if;
																
										when somar =>
												
												if i_go = '1' then
														estado_atual <= busca;
												else 
														estado_atual <= somar;
												end if;
												
										when carregar_constante =>
												
												if i_go = '1' then
														estado_atual <= busca;
												else 
														estado_atual <= carregar_constante;
												end if;
												
										when others =>
												null;
								end case;
						end if;
				end if;
		end process;
		
		u_controller2: process(estado_atual)
		begin 
				  o_D_addr <= "00000000";
				  o_D_rd <= '0';
				  o_D_wr <= '0';
				  o_RF_w_data <= "00000000";
				  o_RF_s1 <= '0';
				  o_RF_s0 <= '0';
				  o_RF_w_addr  <= "0000";
				  o_RF_w_wr <= '0';
				  o_RF_Rp_addr  <= "0000";
				  o_RF_Rp_rd <= '0';
				  o_RF_Rq_addr  <= "0000";
				  o_RF_Rq_rd <= '0';
				  o_alu_s0 <= '0';
				  o_PC_clr <= '0';
				  o_PC_inc <= '0';
				  o_I_rd <= '0';
				  o_IR_ld <= '0';
				
				case estado_atual is
						when inicio =>
							  o_PC_clr <= '1';
								
						when busca =>
								o_I_rd <= '1';
								o_PC_inc <= '1';
								o_IR_ld <= '1';
					
						when carregar => 
								o_D_addr <= w_D;
								o_D_rd <= '1';
								o_RF_s1 <= '0';
								o_RF_s0 <= '1';
								o_RF_w_addr  <= w_Ra;
								o_RF_W_wr <= '1';
										
						when armazenar => 
								o_D_addr <= w_D;
								o_D_wr <= '1';
								o_RF_s1 <= 'X';
								o_RF_s0 <= 'X';
								o_RF_Rp_addr <= w_Ra;
								o_RF_Rp_rd <= '1';
								
						when somar => 
								o_RF_Rp_addr <= w_Rb;
								o_RF_Rp_rd <= '1';
								o_RF_s1 <= '0';
								o_RF_s0 <= '0';
								o_RF_Rq_addr  <= w_Rc;
								o_RF_Rq_rd <= '1';
								o_RF_w_addr <= w_Ra;
								o_RF_W_wr <= '1';
								o_alu_s0 <= '1';
								
						when carregar_constante =>
								o_RF_s1 <= '1';
								o_RF_s0 <= '0';
								o_RF_w_addr <= w_Ra;
								o_RF_W_wr <= '1';
								
						when others =>
								null;
				end case;
				o_RF_w_data <= i_IR_in(7 downto 0);
		end process;
end arc_ctl;