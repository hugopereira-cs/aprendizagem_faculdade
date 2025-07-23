print(' Tabuada '.center(30, '='))
n = int(input('Digite um número inteiro: '))
print('-' * 12)
print(f'A tabuada de {n} é a seguinte:')
for i in range(1, 11):
    print(f'{n} x {i:2} = {n * i}')
print('-' * 12)