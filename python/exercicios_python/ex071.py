valor = 0
print('='*30)
print(f'{"BANCO CEV":^30}')
print('='*30)
valor = float(input('Que valor você quer sacar? R$'))
ced_50 = valor // 50
ced_20 = (valor % 50) // 20
ced_10 = ((valor % 50) % 20) // 10
ced_1 = (((valor %50) % 20) % 10) // 1
if ced_50 > 0:
    print(f'Total de {ced_50:.0f} cédulas de R$50')
if ced_20 > 0:
    print(f'Total de {ced_20:.0f} cédulas de R$20')
if ced_10 > 0:
    print(f'Total de {ced_10:.0f} cédulas de R$10')
if ced_1 > 0:
    print(f'Total de {ced_1:.0f} cédulas de R$1')
print('='*29)
print('Volte sempre ao BANCO CEV! Tenha um bom dia!')