
tot18 = totH = totM20 = idade =0

print('='*7, 'FIM DO PROGRAMA', '='*7)
while True:
    print('-'*25)
    print('   CADASTRE UMA PESSOA   ')
    print('-'*25)
    idade = int(input('Idade: '))
    sexo = ' '
    while sexo not in 'MF':
        sexo = str(input('Sexo: [M/F] ')).strip().upper()[0]

    if idade > 18:
        tot18 += 1
    if sexo == 'M':
        totH += 1
    elif sexo == 'F' and idade < 20:
        totM20 += 1

    resp = ' '
    while resp not in 'SN':
        resp = str(input('Quer continuar? [S/N] ')).strip().upper()[0] 
    
    if resp =='N':
        break

print('='*7, 'FIM DO PROGRAMA', '='*7)
print('Total de pessoas com mais de 18 anos: ', tot18)
print(f'Ao todo temos {totH} homens cadastrados')
print(f'E temos {totM20} mulheres com menos de 20 anos')
