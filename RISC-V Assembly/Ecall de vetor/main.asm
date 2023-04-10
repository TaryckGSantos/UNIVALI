# Disciplina: Arquitetura e Organização de Processadores
# Atividade: Avaliação 01 – Programação em Linguagem de
Montagem
# Exercício 03
# Aluno: Taryck Gean Santos Pego

.data # segmento de dados
      newline: .string "\n"
      Msg1: .string "\n\n Entre com A["
      Msg2: .string "]: "
      Msg3: .string "\n\n A["
      buffer: .string ""
      vet: .align 2
      .space 32 # Declaração do vetor com todos os elementos como 0
      
.text # segmento de código

main:
      addi t0, zero, 0 # Declarando t0 = 0
      addi t1, zero, 0 # Declarando t1 = 0
      addi s7, zero, 8 # Declarando s7 = 8
      la s0, vet # declaramdo s0 como o primeiro endereço do vetor
      
      read_loop: # loop de leitura
            
            # Print na mensagem 1
            la a0, Msg1
            addi a7, x0, 4 # Chama o serviço 4 ( print_string )
            ecall
            
            # Print do inteiro t0
            add a0, zero, t0 # adiciona t0 em a0
            addi a7, x0, 1
            ecall
            
            # Print na mensagem 2
            la a0, Msg2
            addi a7, x0, 4
            ecall
            
            li t1, 0 # zera o endereço t0
            
            # Lê a primeira variável
            addi a7, x0, 5 # Chama o serviço 5 (read_int)
            ecall
            
            add t1, a0, zero # Adiciona o inteiro lido para o endereço t0
            
            sw t1, 0(s0) # Coloca na posição s0 o valor contido em t1
            
            addi t0, t0, 1 # adiciona 1 em t0
            addi s0, s0, 4 # adiciona 4 (1 word) em s0
            bne t0, s7, read_loop # Caso t0 seja diferente de s7 retorna ao loop
            
            addi t0, zero, 0 # zera o t0
            addi t1, zero, 0 # zera o t1
            la s0, vet # s0 retorna a primeira posição de vet
            
      write_loop: # loop de escrever
            
            # Print na mensagem 3
            la a0, Msg3
            addi a7, x0, 4 # Chama o serviço 4 ( print_string )
            ecall
            
            # Print do inteiro t0
            add a0, zero, t0 # adiciona t0 em a0
            addi a7, x0, 1
            ecall
            
            # Print na mensagem 2
            la a0, Msg2
            addi a7, x0, 4
            ecall
            
            lw t1, 0(s0) # carrega em t1 o conteudo da posição s0 do vetor
            
            # Print do inteiro t1
            add a0, zero, t1 # adiciona t1 em a0
            addi a7, x0, 1
            ecall
            
            addi t0, t0, 1 # adiciona 1 em t0
            addi s0, s0, 4 # adiciona 1 word em s0
            bne t0, s7, write_loop # Caso t0 seja diferente de s7 retorna ao loop
