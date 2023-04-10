# Disciplina: Arquitetura e Organização de Processadores
# Atividade: Avaliação 01 – Programação em Linguagem de Montagem
# Exercício 02
# Aluno: Taryck Gean Santos Pego

.data # segmento de dados

	newline: .asciiz "\n"
	Msg: .asciiz "\n Contagem: "
	buffer: .asciiz ""

.text # segmento de código

main:
	li $t0, 0 # Declaração de t0 como 0
	
	loop:
		# Print na mensagem
		li $v0, 4 # Chama o serviço 4 (print_string)
		la $a0, Msg # Msg
		syscall
		
		# Print do inteiro $t0
		li $v0, 1 # Chama o serviço 1 (print_int)
		move $a0, $t0 # Conteúdo de $t0
		syscall
		
		slti $t1, $t0, 9 # Comparaçao de menor que com a constante 9. Caso seja menor, $t1 é igual a 1
		addi $t0, $t0, 1 # Adiciona 1 em $t0 em cada loop completo
		bne $t1, $zero, loop # Caso $t1 seja diferente de 0, o loop irá continuar
