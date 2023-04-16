# Disciplina: Arquitetura e Organização de Processadores
# Atividade: Avaliação 01 – Programação em Linguagem de Montagem
# Exercício 03
# Aluno: Caua Domingos e Taryck Santos

.data # segmento de dados

	Vetor_A: .word 0, 0, 0, 0, 0, 0, 0, 0
	newline: .asciiz "\n"
	Msg1: .asciiz "\n\n Entre com o tamanho do Vetor_A (máx. = 8): "
	Msg2: .asciiz "\n Valor inválido! "
	Msg3: .asciiz "\n\n Vetor_A["
	Msg4: .asciiz "]: "
	Msg5: .asciiz "\n\n Digite o índice do valor a ser impresso: " 
	Msg6: .asciiz "\n\n O elemento do vetor na posição "
	Msg7: .asciiz " possui o valor: "
	
.text # segmento de código

main:

	li $s1, 1 # Declarando s1 = 1
	li $s6, 8 # Declarando s6 = 8

	# Print na mensagem 1
	li $v0, 4 # Chama o serviço 4 (print_string)
	la $a0, Msg1 # Msg1
	syscall
		
	# Lê a variável
	li $v0, 5 # Chama o serviço 5 (read_int)
	syscall
		
	move $s7, $v0 # Move o inteiro para o endereço s7
	
	slt $t8, $s6, $s7 # Caso o inteiro inserido seja maior que 8, t8 = 1
	beq $t8, $s1, mensagem_invalida # Caso t8 e s1 sejam iguais, saltam para "mensagem invalida"
	
	li $t8, 0 # limpa t8
	
	slti $t8, $s7, 2 # caso s7 seja menor que 2, t8 = 1
	beq $t8, $s1, mensagem_invalida # Caso t8 e s1 sejam iguais, saltam para "mensagem invalida"
		
	loop_inserir_vetor:
			
		# Print na mensagem 3
		li $v0, 4 
		la $a0, Msg3
		syscall
		
		# Print na constante $t0
		li $v0, 1 # Chama o serviço 1 (print_int)
		move $a0, $t0 # Carrega a constante de $t0 para o syscall
		syscall
		
		# Print na mensagem 4
		li $v0, 4 
		la $a0, Msg4
		syscall
		
		# Lê a variável
		li $v0, 5 # Chama o serviço 5 (read_int)
		syscall
		
		move $t1, $v0 # Move o inteiro para o endereço t1
		
		sw $t1, Vetor_A($s0) # Coloca na posição $s0 do Vetor_A o valor contido em $t1
		
		addi $t0, $t0, 1 # adiciona 1 em t0
		addi $s0, $s0, 4 # adiciona 4 (1 word) em s0
		bne $t0, $s7, loop_inserir_vetor # Caso $t0 seja diferente de $s7 retorna ao loop
	
	inserir_indice_busca:
		
		li $t0, 0 # zera t0
		li $t1, 0 # zera t1
		li $s0, 0 # zera s0
		
		# Print na mensagem 5
		li $v0, 4 
		la $a0, Msg5 
		syscall
		
		# Lê a variável
		li $v0, 5 # Chama o serviço 5 (read_int)
		syscall 
		
		move $s2, $v0 # Move o inteiro para o endereço s2
		
		sub $s5, $s7, $s1 # Subtrai 1 de s7 e insere em s5 (para a busca no vetor que vai de 0 até s7 - 1
		
		slt $t8, $s5, $s2 #  Caso o indice inserido seja maior que o numero de posições no vetor, t8 = 1
		beq $t8, $s1, mensagem_invalida_busca # se t8 for igual a s1
	
		li $t8, 0
	
		slti $t8, $s2, 0 #  Caso o indice inserido seja menor que 0, t8 = 1
		beq $t8, $s1, mensagem_invalida_busca # se t8 for igual a s1
		
		li $s0, 0 # zera s0 
		
		j loop_buscar_vetor
		
	mensagem_invalida: # função de print para ser chamada na invalidez do tamanho do vetor
		
		# Print na mensagem 2
		li $v0, 4 
		la $a0, Msg2 
		syscall	
		
		j main
		
	mensagem_invalida_busca: # função de print para ser chamada na invalidez da busca no vetor
		
		# Print na mensagem 2
		li $v0, 4 
		la $a0, Msg2 
		syscall	
		
		j inserir_indice_busca
		
	loop_buscar_vetor: # função de buscar no vetor 
		
		beq $t0, $s2, mostrar_vetor_buscado # caso a contagem de posição for igual a posição buscada, mostrar o valor naquela posição do vetor
		
		# caso $t0 != $s2:
		addi $s0, $s0, 4 # adiciona 4 (1 word) em s0
		addi $t0, $t0, 1 # adiciona 1 em t0
		j loop_buscar_vetor # retorna ao início do loop
		
	mostrar_vetor_buscado: # Mostra o vetor buscado
		
		# Print na mensagem 6
		li $v0, 4 
		la $a0, Msg6 
		syscall
		
		# Print na constante $t0
		li $v0, 1
		move $a0, $t0 
		syscall
		
		# Print na mensagem 7
		li $v0, 4 
		la $a0, Msg7 
		syscall
		
		lw $s3, Vetor_A($s0) # carrega em s3 o valor contido naquela posição do vetor 
		
		# Print na constante $s3
		li $v0, 1 
		move $a0, $s3 
		syscall
