# Disciplina: Arquitetura e Organização de Processadores
# Atividade: Avaliação 01 – Programação em Linguagem de Montagem
# Exercício 03
# Aluno: Taryck Gean Santos Pego

.data # segmento de dados

	newline: .asciiz "\n"
	Msg1: .asciiz "\n\n Entre com A["
	Msg2: .asciiz "]: "
	Msg3: .asciiz "\n\n A["
	buffer: .asciiz ""
	vet: .align 2
	.space 32 # Declaração do vetor com 8 words
	
.text # segmento de código

main:

li $t0, 0 # Declarando t0 = 0
li $t1, 0 # Declarando t1 = 0
li $s7, 8 # Declarando s7 = 8
la $s0, vet # declarando s0 como o primeiro endereço do vetor

	read_loop: # loop de leitura
	
		# Print na mensagem 1
		li $v0, 4 # Chama o serviço 4 (print_string)
		la $a0, Msg1 # Msg1
		syscall
		
		# Print na constante $t0
		li $v0, 1 # Chama o serviço 1 (print_int)
		move $a0, $t0 # Carrega a constante de $t0 para o syscall
		syscall
		
		# Print na mensagem 2
		li $v0, 4 # Chama o serviço 4 (print_string)
		la $a0, Msg2 # Msg2
		syscall
		
		# Lê a variável
		li $v0, 5 # Chama o serviço 5 (read_int)
		syscall
		
		# Move o inteiro para o endereço t1
		move $t1, $v0
		
		sw $t1, 0($s0) # Coloca na posição $s0 o valor contido em $t1
		
		addi $t0, $t0, 1 # adiciona 1 em t0
		addi $s0, $s0, 4 # adiciona 4 (1 word) em s0
		bne $t0, $s7, read_loop # Caso $t0 seja diferente de $s7 retorna ao loop
		
		li $t0, 0 # zera o t0
		li $t1, 0 # zera o t1
		la $s0, vet # s0 retorna a primeira posição de vet
		
	write_loop: # loop de escrever
	
		# Print na mensagem 3
		li $v0, 4 # Chama o serviço 4 (print_string)
		la $a0, Msg3 # Msg3
		syscall
		
		# Print na constante $t0
		li $v0, 1 # Chama o serviço 1 (print_int)
		move $a0, $t0 # Carrega a constante de $t0 para o syscall
		syscall
		
		# Print na mensagem 2
		li $v0, 4 # Chama o serviço 4 (print_string)
		la $a0, Msg2 # Msg2
		syscall
		
		lw $t1, 0($s0) # carrega em t1 o conteudo da posição s0 do vetor
		
		# Print na constante $t1
		li $v0, 1 # Chama o serviço 1 (print_int)
		move $a0, $t1 # Carrega a constante de $t1 para o syscall
		syscall
		
		addi $t0, $t0, 1 # adiciona 1 em t0
		addi $s0, $s0, 4 # adiciona 1 word em s0
		bne $t0, $s7, write_loop # Caso $s1 seja diferente de $s2 retorna ao loop
