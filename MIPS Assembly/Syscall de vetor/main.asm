# Disciplina: Arquitetura e Organização de Processadores
# Atividade: Avaliação 01 – Programação em Linguagem de Montagem
# Exercício 03
# Aluno: Taryck Gean Santos Pego

   .data   # segmento de dados

newline:  .asciiz "\n"
Msg1:     .asciiz "\n\n Entre com A["
Msg2:     .asciiz "]: "
Msg3:     .asciiz "\n\n A["
buffer:   .asciiz ""

vet:    .align 2
	.space 32 # Declaração do vetor com todos os elementos como 0

    .text # segmento de código

main:
	li $t0, 0
	li $t1, 0
	li $s7, 8
	la $s0, vet
	
	read_loop: # loop de leitura
		
		# Print na mensagem 1
      		li  $v0, 4  # Chama o serviço 4 (print_string)
      		la  $a0, Msg1 # Msg1
      		syscall
      		
      		# Print na constante $s1
      		li  $v0, 1  # Chama o serviço 1 (print_int)
      		move $a0, $t0 # Carrega a constante de $s1 para o syscall
      		syscall
      		
      		# Print na mensagem 2
      		li  $v0, 4 # Chama o serviço 4 (print_string)
      		la  $a0, Msg2 # Msg2
      		syscall
      		
      		# Lê a variável
      		li  $v0, 5  # Chama o serviço 5 (read_int)
      		syscall
      
      		# Move o inteiro para o endereço t0
		move $t1, $v0
		
		sw $t1, 0($s0) # Coloca na posição $s0 o valor contido em $t0
		
		addi $t0, $t0, 1
		addi $s0, $s0, 4
		
		bne $t0, $s7, read_loop # Caso $s1 seja diferente de $s2 retorna ao loop
		li $t0, 0
		li $t1, 0
		la $s0, vet
	write_loop:
		
		# Print na mensagem 3
      		li  $v0, 4  # Chama o serviço 4 (print_string)
      		la  $a0, Msg3 # Msg3
      		syscall
      		
      		# Print na constante $s1
      		li  $v0, 1  # Chama o serviço 1 (print_int)
      		move $a0, $t0 # Carrega a constante de $s1 para o syscall
      		syscall
      		
      		# Print na mensagem 2
      		li  $v0, 4 # Chama o serviço 4 (print_string)
      		la  $a0, Msg2 # Msg2
      		syscall
      		
      		lw $t1, 0($s0)
      		
      		# Print na constante $s1
      		li  $v0, 1  # Chama o serviço 1 (print_int)
      		move $a0, $t1 # Carrega a constante de $s1 para o syscall
      		syscall
      		
      		addi $t0, $t0, 1
		addi $s0, $s0, 4
		
		bne $t0, $s7, write_loop # Caso $s1 seja diferente de $s2 retorna ao loop
