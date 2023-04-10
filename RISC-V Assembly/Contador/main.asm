# Disciplina: Arquitetura e Organização de Processadores
# Atividade: Avaliação 01 – Programação em Linguagem de Montagem
# Exercício 02
# Aluno: Taryck Gean Santos Pego

.data # segmento de dados
      
      newline: .string "\n"
      Msg: .string "\n Contagem: "
      buffer: .string ""
      
.text # segmento de código

main:
      
      addi t0, zero, 0 # Declaração de t0 como 0
      
      loop:
            # Print na mensagem
            la a0, Msg
            addi a7, x0, 4 # Chama o serviço 4 ( print_string )
            ecall
            
            # Print do inteiro t0
            add a0, zero, t0 # adiciona t0 em a0
            addi a7, x0, 1
            ecall
            
            slti t1, t0, 9 # Comparaçao de "menor que" com a constante 9. Caso seja menor, t1 é igual a 1
            addi t0, t0, 1 # Adiciona 1 em t0 em cada loop completo
            bne t1, zero, loop # Caso t1 seja diferente de 0, o loop irá continuar
