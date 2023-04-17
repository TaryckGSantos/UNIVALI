# Disciplina: Arquitetura e Organização de Processadores
# Atividade: Avaliação 02 – Programação em Linguagem de Montagem
# Programa 01
# Aluno: Caua Domingos e Taryck Santos

.data # segmento de dados

        Vetor_A: .word 0, 0, 0, 0, 0, 0, 0, 0
	newline: .asciz "\n"
	Msg1: .asciz "\n\n Entre com o tamanho do Vetor_A (máx. = 8): "
	Msg2: .asciz "\n Valor inválido! "
	Msg3: .asciz "\n\n Vetor_A["
	Msg4: .asciz "]: "
	Msg5: .asciz "\n\n Digite o índice do valor a ser impresso: " 
	Msg6: .asciz "\n\n O elemento do vetor na posição "
	Msg7: .asciz " possui o valor: "

.text # segmento de código
main:

	li s1, 1 # Declarando s1 = 1
	li s6, 8 # Declarando s6 = 8

	# Print na mensagem 1
	li a7, 4 # Chama o serviço 4 (print_string)
	la a0, Msg1 # Msg1
	ecall
		
	# Lê a variável
	li a7, 5 # Chama o serviço 5 (read_int)
	ecall
		
	mv s7, a0 # Move o inteiro para o endereço s7
	
	slt t6, s6, s7 # Caso o inteiro inserido seja maior que 8, t6 = 1
	beq t6, s1, mensagem_invalida # Caso t6 e s1 sejam iguais, saltam para "mensagem invalida"
	
	li t6, 0 # limpa t6
	
	slti t6, s7, 2 # caso s7 seja menor que 2, t6 = 1
	beq t6, s1, mensagem_invalida # Caso t6 e s1 sejam iguais, saltam para "mensagem invalida"
	
	la s0, Vetor_A
		
	loop_inserir_vetor:
			
	     # Print na mensagem 3
		li a7, 4 
		la a0, Msg3
		ecall
		
		# Print na constante t0
		li a7, 1 # Chama o serviço 1 (print_int)
		mv a0, t0 # Carrega a constante de t0 para o syscall
		ecall
		
		# Print na mensagem 4
		li a7, 4 
		la a0, Msg4
		ecall
		
		# Lê a variável
		li a7, 5 # Chama o serviço 5 (read_int)
		ecall
		
		mv t1, a0 # Move o inteiro para o endereço t1
		
		sw t1, 0(s0) # Coloca na posição s0 do Vetor_A o valor contido em t1
		
		addi t0, t0, 1 # adiciona 1 em t0
		addi s0, s0, 4 # adiciona 4 (1 word) em s0
		bne t0, s7, loop_inserir_vetor # Caso t0 seja diferente de s7 retorna ao loop
	
	inserir_indice_busca:
		
		li t0, 0 # zera t0
		li t1, 0 # zera t1
		
		# Print na mensagem 5
		li a7, 4 
		la a0, Msg5 
		ecall
		
		# Lê a variável
		li a7, 5 # Chama o serviço 5 (read_int)
		ecall 
		
		mv s2, a0 # Move o inteiro para o endereço s2
		
		sub s5, s7, s1 # Subtrai 1 de s7 e insere em s5 (para a busca no vetor que vai de 0 até s7 - 1
		
		slt t6, s5, s2 #  Caso o indice inserido seja maior que o numero de posições no vetor, t6 = 1
		beq t6, s1, mensagem_invalida_busca # se t6 for igual a s1, pula pra mensagem_invalida_busca
	
		li t6, 0
	
		slti t6, s2, 0 #  Caso o indice inserido seja menor que 0, t6 = 1
		beq t6, s1, mensagem_invalida_busca # se t6 for igual a s1, pula pra mensagem_invalida_busca
		
		la s0, Vetor_A # zera s0 
		
		j loop_buscar_vetor
		
	mensagem_invalida: # função de print para ser chamada na invalidez do tamanho do vetor
		
		# Print na mensagem 2
		li a7, 4 
		la a0, Msg2 
		ecall	
		
		j main
		
	mensagem_invalida_busca: # função de print para ser chamada na invalidez da busca no vetor
		
		# Print na mensagem 2
		li a7, 4 
		la a0, Msg2 
		ecall	
		
		j inserir_indice_busca
		
	loop_buscar_vetor: # função de buscar no vetor 
		
		beq t0, s2, mostrar_vetor_buscado # caso a contagem de posição for igual a posição buscada, pula pra mostrar_vetor_buscado
		
		# caso $t0 != $s2:
		addi s0, s0, 4 # adiciona 4 (1 word) em s0
		addi t0, t0, 1 # adiciona 1 em t0
		j loop_buscar_vetor # retorna ao início do loop
		
	mostrar_vetor_buscado: # Mostra o vetor buscado
		
		# Print na mensagem 6
		li a7, 4 
		la a0, Msg6 
		ecall
		
		# Print na constante t0
		li a7, 1
		mv a0, t0 
		ecall
		
		# Print na mensagem 7
		li a7, 4 
		la a0, Msg7 
		ecall
		
		lw t5, 0(s0) # carrega em s3 o valor contido naquela posição do vetor 
		
		# Print na constante s3
		li a7, 1 
		mv a0, t5 
		ecall
