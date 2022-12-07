library ieee;
use ieee.std_logic_1164.all;

entity controller is 
port (  i_CLK : in std_logic;
		  i_CLR : in std_logic;
		  i_IGUAL : in std_logic;
		  i_MENOR : in std_logic;
		  i_GO : in std_logic;
		  o_XSEL : out std_logic;
		  o_YSEL : out std_logic;
		  o_XLD : out std_logic; 
		  o_YLD : out std_logic;
		  o_SLD : out std_logic);
end controller;

architecture arch_2 of controller is
type estado is (inicio, entrada, teste1, teste2, 
					 update1, update2, final);
					 
signal estado_atual, proximo_estado: estado;
begin 

u_q_registrador: process (i_CLK, i_CLR)
begin 
		if i_CLR = '1' then 
				estado_atual <= inicio;
		elsif i_CLK' event and i_CLK = '1' then
				estado_atual <= proximo_estado;
		end if;
end process;

u_control1: process (estado_atual, i_GO, i_IGUAL, i_MENOR)
begin
		case estado_atual is
				when inicio =>
						if i_GO = '1' then
								proximo_estado <= entrada;
						else 
								proximo_estado <= inicio;
						end if;
				when entrada => 
						proximo_estado <= teste1;
				when teste1 =>
						if i_IGUAL = '1' then
								proximo_estado <= final;
						else 
								proximo_estado <= teste2;
						end if;
				when teste2 => 
						if i_MENOR = '1' then
								proximo_estado <= update1;
						else 
								proximo_estado <= update2;
						end if;
				when update1 =>
						proximo_estado <= teste1;
				when update2 =>
						proximo_estado <= teste1;
				when final =>
						proximo_estado <= final;
				when others =>
						null;
		end case;
end process;

u_control2: process (estado_atual)
begin 

		o_XLD <= '0';
		o_YLD <= '0';
		o_SLD <= '0';
		o_XSEL <= '0';
		o_YSEL <= '0';
		case estado_atual is
				when entrada =>
						o_XLD <= '1';
						o_YLD <= '1';
						o_XSEL <= '1';
						o_YSEL <= '1';
				when update1 =>
						o_YLD <= '1';
				when update2 =>
						o_XLD <= '1';
				when final =>
						o_SLD <= '1';
				when others =>
						null;
		end case;
end process;

end arch_2;