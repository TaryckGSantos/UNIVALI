# Disciplina: Arquitetura e Organização de Processadores
# Atividade: Avaliação 01 – Programação em Linguagem de Montagem
# Exercício 01
# Aluno: Taryck Gean Santos Pego

.data
      newline: .string "\n"
      Msg1: .string "\n\nEntre com o valor de W: "
      Msg2: .string "\n\nEntre com o valor de X: "
      Msg3: .string "\n\nEntre com o valor de Y: "
      Msg4: .string "\n\nEntre com o valor de Z: "
      Msg5: .string "\n\nA média aritmética da soma é igual a: "
      Msg6: .string "\n\nSoma: "

.text

main:
      # Print na mensagem 1
      la a0, Msg1 # Msg1
      addi a7, x0, 4 # Chama o serviço 4 ( print_string )
      ecall
      
      li t0, 0 # zera o endereço t0
      
      # Lê a primeira variável
      addi a7, x0, 5 # Chama o serviço 5 (read_int)
      ecall
      
      # Move o inteiro para o endereço t0
      add t0, a0, zero
      
      # Print na mensagem 2
      la a0, Msg2
      addi a7, x0, 4
      ecall
      
      li t1, 0 # zera o endereço t1
      
      # Lê a segunda variável
      addi a7, x0, 5
      ecall
      
      # Move o inteiro para o endereço t1
      add t1, a0, zero
      
      # Print na mensagem 3
      la a0, Msg3
      addi a7, x0, 4
      ecall
      
      li t2, 0 # zera o endereço t2
      
      # Lê a terceira variável
      addi a7, x0, 5
      ecall
      
      # Move o inteiro para o endereço t2
      add t2, a0, zero
      
      # Print na mensagem 4
      la a0, Msg4
      addi a7, x0, 4
      ecall
      
      li t3, 0 # zera o endereço t3
      
      # Lê a terceira variável
      addi a7, x0, 5
      ecall
      
      # Move o inteiro para o endereço t3
      add t3, a0, zero
      
      li s0, 0 # Inicializa s0
      add s0, t0, t1 # Faz a soma de t0 e t1 e guarda em s0
      add s0, s0, t2 # Faz a soma de s0 e t2 e guarda em s0 novamente
      add s0, s0, t3 # Faz a soma de s0 e t3 e guarda em s0 novamente
      
      # Print na mensagem 6
      la a0, Msg6
      addi a7, x0, 4
      ecall
      
      # Print do inteiro da soma
      add a0, zero, s0 # adiciona s0 em a0
      addi a7, x0, 1
      ecall
      
      li t4, 4 # Constante usada para subtração
      li t5, 1 # Constante usada a fim de comparação
      li s5, 0 # Contador da divisão
      
      loop:
            slti t6, s0, 4 # Caso o resultado da subtração seja menor que 4, t6 é 1
            beq t5, t6, result # Caso a comparação acima seja verdadeira, pula para o resultado
            
            # caso nenhuma afirmação acima seja verdadeira
            sub s0, s0, t4 # subtrai 4 da soma
            addi s5, s5, 1 # aumenta 1 no contador
            j loop # Volta para o loop
            
      result:
            # Print na mensagem 5
            la a0, Msg5
            addi a7, x0, 4
            ecall
            
            # Print do inteiro s5
            add a0, zero, s5
            addi a7, x0, 1
            ecall
