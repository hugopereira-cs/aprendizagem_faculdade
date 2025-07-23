from random import randint
jogador = computador = total = cont = 0
print('=-'*15)
print('VAMOS JOGAR PAR OU ÍMPAR')
print('=-'*15)

while True:
    jogador = int(input('Diga um valor: '))
    computador = randint(1, 9)
    total = jogador + computador
    par_impar = ' '
    while par_impar not in 'PI':
        par_impar = str(input('Par ou Ímpar? [P/I] ')).upper()[0]
    print('-'*30)
    print(f'Você jogou {jogador} e o computador {computador}. Total de {total}', end=' ')
    print('DEU PAR' if total % 2 == 0 else 'DEU ÍMPAR')
    print('-'*30)
    if total % 2 == 0:
        if par_impar == 'P':
            print('Você VENCEU!\nVamos jogar novamente...')
            print('=-'*15)
            cont += 1
        else:
            print('Você PERDEU!')
            print('=-'*15)
            break
    else:
        if par_impar == 'I':
            print('Você VENCEU!\nVamos jogar novamente...')
            print('=-'*15)
            cont += 1
        else:
            print('Você PERDEU!')
            print('=-'*15)
            break
print(f'GAME OVER! Você venceu {cont} vezes.')


