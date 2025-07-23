from random import randint
num_comp = randint(0, 10)
num = None
cont = 0
acertou = False
while not acertou:
    num = int(input('Tente advinhar em qual número estou pensando[entre 0 e 10]: '))
    cont += 1
    if num == num_comp:
        acertou = True
    else:
        if num < num_comp:
            print('Mais... Tente novamente.')
        else:
            print('Menos... Tente novamente.')
print(f'Eu estava pensando no número {num_comp}')
print(f'Você precisou de {cont} palpites para acertar.')
