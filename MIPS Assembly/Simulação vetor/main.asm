# Disciplina: Arquitetura e Organização de Processadores
# Atividade: Avaliação 01 – Programação em Linguagem de Montagem
# Exercício 03
# Aluno: Caua Domingos e Taryck Santos

.data # segmento de dados

	Vetor_A: .word 0, 0, 0, 0, 0, 0, 0, 0
	newline: .asciiz "\n"
	Msg1: .asciiz "\n\n Entre com o tamanho do Vetor_Aor (máx. = 8): "
	Msg2: .asciiz "\n\n Valor inválido! "
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
		
	# Move o inteiro para o endereço s7
	move $s7, $v0
	
	slt $t8, $s6, $s7 # Caso o inteiro inserido seja maior que 8, t8 = 1
	beq $t8, $s1, mensagem_invalida # Caso t8 e s1 sejam iguais, saltam para "mensagem invalida"
	
	li $t8, 0 # limpa t8
	
	slti $t8, $s7, 2 # caso s7 seja menor que 2, t8 = 1
	beq $t8, $s1, mensagem_invalida # Caso t8 e s1 sejam iguais, saltam para "mensagem invalida"
		
	loop_inserir_vetor:
			
		# Print na mensagem 1
		li $v0, 4 # Chama o serviço 4 (print_string)
		la $a0, Msg3 # Msg3
		syscall
		
		# Print na constante $t0
		li $v0, 1 # Chama o serviço 1 (print_int)
		move $a0, $t0 # Carrega a constante de $t0 para o syscall
		syscall
		
		# Print na mensagem 2
		li $v0, 4 # Chama o serviço 4 (print_string)
		la $a0, Msg4 # Msg4
		syscall
		
		# Lê a variável
		li $v0, 5 # Chama o serviço 5 (read_int)
		syscall
		
		move $t1, $v0 # Move o inteiro para o endereço t1
		
		sw $t1, Vetor_A($s0) # Coloca na posição $s0 do VEtor_A o valor contido em $t1
		
		addi $t0, $t0, 1 # adiciona 1 em t0
		addi $s0, $s0, 4 # adiciona 4 (1 word) em s0
		bne $t0, $s7, loop_inserir_vetor # Caso $t0 seja diferente de $s7 retorna ao loop
	
	inserir_indice_busca:
		
		li $t0, 0 # zera t0
		li $t1, 0 # zera t1
		li $s0, 0 # zera s0
		
		# Print na mensagem 1
		li $v0, 4 # Chama o serviço 4 (print_string)
		la $a0, Msg5 # Msg5
		syscall
		
		# Lê a variável
		li $v0, 5 # Chama o serviço 5 (read_int)
		syscall 
		
		move $s2, $v0 # Move o inteiro para o endereço s1
		
		sub $s5, $s7, $s1 # Subtrai 1 de s7 e insere em s5
		
		slt $t8, $s5, $s2 #  Caso o indice inserido seja maior que o numero de posições no vetor, t8 = 1
		beq $t8, $s1, mensagem_invalida_busca # se t8 for igual a s1
	
		li $t8, 0
	
		slti $t8, $s2, 0
		beq $t8, $s1, mensagem_invalida_busca
		
		li $s0, 0
		
		j loop_buscar_vetor
		
	mensagem_invalida: 
		
		# Print na mensagem 1
		li $v0, 4 # Chama o serviço 4 (print_string)
		la $a0, Msg2 # Msg1
		syscall	
		
		j main
		
	mensagem_invalida_busca:
		
		# Print na mensagem 1
		li $v0, 4 # Chama o serviço 4 (print_string)
		la $a0, Msg2 # Msg1
		syscall	
		
		j inserir_indice_busca
		
	loop_buscar_vetor:
		
		beq $t0, $s2, mostrar_vetor_buscado
		addi $s0, $s0, 4
		addi $t0, $t0, 1
		j loop_buscar_vetor
		
	mostrar_vetor_buscado:
		
		# Print na mensagem 1
		li $v0, 4 # Chama o serviço 4 (print_string)
		la $a0, Msg6 # Msg1
		syscall
		
		# Print na constante $t0
		li $v0, 1 # Chama o serviço 1 (print_int)
		move $a0, $t0 # Carrega a constante de $t0 para o syscall
		syscall
		
		# Print na mensagem 1
		li $v0, 4 # Chama o serviço 4 (print_string)
		la $a0, Msg7 # Msg1
		syscall
		
		lw $s3, Vetor_A($s0) 
		
		# Print na constante $t0
		li $v0, 1 # Chama o serviço 1 (print_int)
		move $a0, $s3 # Carrega a constante de $t0 para o syscall
		syscall
