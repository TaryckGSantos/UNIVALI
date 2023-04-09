# Disciplina: Arquitetura e Organização de Processadores
# Atividade: Avaliação 01 – Programação em Linguagem de Montagem
# Exercício 01
# Aluno: Taryck Gean Santos Pego

.data

      newline: .asciiz "\n"
      Msg1: .asciiz "\n\nEntre com o valor de W: "
      Msg2: .asciiz "\n\nEntre com o valor de X: "
      Msg3: .asciiz "\n\nEntre com o valor de Y: "
      Msg4: .asciiz "\n\nEntre com o valor de Z: "
      Msg5: .asciiz "\n\nA média aritmética da soma é igual a: "
      Msg6: .asciiz "\n\nSoma: "

.text

main:
	
        # Print na mensagem 1
      	li  $v0, 4                # Chama o serviço 4 (print_string)
      	la  $a0, Msg1             # Msg1
      	syscall
      	
      	li $v0, 0
      	# Lê a primeira variável
      	li  $v0, 5                # Chama o serviço 5 (read_int)
      	syscall
      
      	# Move o inteiro para o endereço t0
	move $t0, $v0
      
	# Print na mensagem 2
	li  $v0, 4                # Chama o serviço 4
      	la  $a0, Msg2             # Msg2
      	syscall                    

	li $v0, 0
      	# Lê a segunda variável
      	li  $v0, 5                 # Chama o serviço 5
      	syscall
      
      	# Move o inteiro para o endereço t1
      	move $t1, $v0
      
       	# Print na mensagem 3
      	li  $v0, 4                # Chama o serviço 4
      	la  $a0, Msg3             # Msg3
      	syscall                    
	
	li $v0, 0
      	# Lê a segunda variável
      	li  $v0, 5                 # Chama o serviço 5
	syscall
      
      	# Move o inteiro para o endereço t2
	move $t2, $v0
      
       	# Print na mensagem 4
      	li  $v0, 4                # Chama o serviço 4
      	la  $a0, Msg4             # Msg4
      	syscall                    

	li $v0, 0
      	# Lê a segunda variável
	li  $v0, 5                 # Chama o serviço 5
	syscall
      
	# Move o inteiro para o endereço t3
	move $t3, $v0
      
	li $s0, 0      
      	add $s0, $t0, $t1 # Faz a soma de $t0 e $t1 e guarda em $s0
      	add $s0, $s0, $t2 # Faz a soma de $s0 e $t2 e guarda em $s0 novamente
      	add $s0, $s0, $t3 # Faz a soma de $s0 e $t3 e guarda em $s0 novamente
      	
      	# Print na mensagem 4
      	li  $v0, 4                # Chama o serviço 4
      	la  $a0, Msg6             # Msg6
      	syscall
      	
      	# Print do inteiro $s5
      	li  $v0, 1                # Chama o serviço 1 (print_int)
      	move $a0, $s0             # Conteúdo de $s0
      	syscall
      	
      	li $t4, 4 # Constante usada para subtração
      	li $t8, 1 # Constante usada a fim de comparação
      	li $s5, 0 # Contador da divisão

      	loop:
      		beq $s0, $t4, inc_beq # Caso a subtração dê igual a 4, pula para o resultado
      		slti $t9, $s0, 4 # Caso o resultado da subtração seja menor que 4
      		beq $t8, $t9, result # Caso a comparação acima seja verdadeira, pula para o resultado
      		
      		# caso nenhuma afirmação acima seja verdadeira
      		sub $s0, $s0, $t4 # subtrai 4 da soma
      		addi $s5, $s5, 1 # aumenta 1 no contador
      		j loop # Volta para o loop
      	
      	inc_beq:
      		addi $s5, $s5, 1
      		j result
      	
      	result:
      	# Print na mensagem 5
      	li  $v0, 4                # Chama o serviço 4 (print_string)
      	la  $a0, Msg5             # Msg5
      	syscall
      	
      	# Print do inteiro $s5
      	li  $v0, 1                # Chama o serviço 1 (print_int)
      	move $a0, $s5             # Conteúdo de $s5
      	syscall
