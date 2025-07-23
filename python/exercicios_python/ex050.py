pares = 0
soma_par = 0
for i in range(1, 7):
    num = int(input('Digite um valor: '))
    if num % 2 == 0:
        soma_par += num
        pares += 1
print(f'A soma dos {pares} números pares digitados é {soma_par}')