num = int(input('Digite um número: '))
tot = 0
for i in range(1, num + 1):
    if num % i == 0:
        print('\033[33m', end='')
        tot += 1
    else:
        print('\033[31m', end='')
    print(f'{i}', end=' ')
print(f'\n\033[mO número {num} foi divisível {tot} vezes')
if tot == 2:
    print(f'E por isso é primo!')
else:
    print(f'E por isso não é primo!')