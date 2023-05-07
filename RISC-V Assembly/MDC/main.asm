# Disciplina: Arquitetura e Organização de Processadores
# Atividade: Avaliação 03 – Programação de Procedimentos
# Alunos: Caua Domingos e Taryck Santos

.data #Segmento de Dados

  Msg1: .asciz "\n\n Digite um valor para X: "
	Msg2: .asciz "\n\n Digite um valor para Y: "
	Msg3: .asciz "\n\n Resultado do MDC: "
  Msg4: .asciz "\n\n Apenas números maiores ou iguais a 1!"
	
.text #Segmento de Texto

global:

     j main
	
mdc:

	addi sp, sp, -12 # Aloca espaço na pilha
	sw ra, 8(sp) # Salva o endereço de retorno na pilha
	sw a1, 4(sp) # Salva o registrador a1 na pilha
	sw a2, 0(sp) # Salva o registrador a2 na pilha
	
	while:
	
	  beq a1, a2, end_while # Se a1 e a2 forem iguais, pula para o end_while
		blt a1, a2, if_lt # se a2 for maior que a1, pula para o if_lt
		
		sub a1, a1, a2 # Subtrai de a1 o valor de a2
		j while # Volta para o while
		
	if_lt:
	
		sub a2, a2, a1 # Subtrai de a2 o valor de a1
		j while # Volta para o while
		
	end_while:
	
		mv s7, a1 # Move para s7 o valor de a1
		lw ra, 8(sp) # Move para ra o valor dessa posição da pilha
		lw a1, 4(sp) # Move para a1 o valor dessa posição da pilha
		lw a2, 0(sp) # Move para a2 o valor dessa posição da pilha
   
          addi sp, sp, 12 # Desaloca o espaço na pilha      
          jr ra # Salta para o endereço armazenado em ra 

erro: 
	#Mensagem de erro
	li a7, 4 # Chama o serviço 4 (print_string)
	la a0, Msg4 # Msg4
	ecall 
             
main:
	li t0, 1 # Carrega a constante 1 em t0

	#Armazenando um valor para X
	li a7, 4 # Chama o serviço 4 (print_string)
	la a0, Msg1 # Msg1
	ecall
	
	li a7, 5 # Chama o serviço 5 (read_int)
	ecall
	
	mv a1, a0 # Move o inteiro para o endereço a1

  blt a1, t0, erro # Caso a1 seja menor que 1, pula para a função erro
	
	#Armazenando um valor para Y
	li a7, 4 # Chama o serviço 4 (print_string)
	la a0, Msg2 # Msg2
	ecall
	
	li a7, 5 # Chama o serviço 5 (read_int)
	ecall
	
	mv a2, a0 # Move o inteiro para o endereço a2

  blt a2, t0, erro # Caso a1 seja menor que 1, pula para a função erro
	
  jal mdc # Salta para a função mdc
	
	#Mostra a Msg3
	li a7, 4 
	la a0, Msg3 
	ecall
	
	# Print na constante s7
	li a7, 1
	mv a0, s7 
	ecall
