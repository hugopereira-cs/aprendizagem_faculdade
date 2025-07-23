from random import randint
itens = ('Pedra', 'Papel', 'Tesoura')
computador = randint(0, 2)
print("""Suas opções:
[ 0 ] PEDRA
[ 1 ] PAPEL
[ 2 ] TESOURA""")
jogador = int(input('Qual é a sua jogada? '))
print('=-'*11)
print(f'O computador jogou {itens[computador]}')
print(f'O jogador jogou {itens[jogador]}')
print('=-'*11)

if computador == 0: # computador jogou pedra
    if jogador == 0:
        print('Deu EMPATE!')
    elif jogador == 1:
        print('O jogador VENCEU')
    elif jogador == 2:
        print('O computador VENCEU!')
    else:
        print('JOGADA INVÁLIDA!')
elif computador == 1: # computador jogou papel
    if jogador == 0:
        print('O computador VENCEU!')
    elif jogador == 1:
        print('Deu EMPATE!')
    elif jogador == 2:
        print('O jogador VENCEU')
    else:
        print('JOGADA INVÁLIDA!')
elif computador == 2: # computador jogou tesoura
    if jogador == 0:
        print('O jogador VENCEU')
    elif jogador == 1:
        print('O computador VENCEU!')
    elif jogador == 2:
        print('Deu EMPATE!')
    else:
        print('JOGADA INVÁLIDA!')
