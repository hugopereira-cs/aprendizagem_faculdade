valor_casa = salario = anos = 0
print('='*30)
print(f'{"BANCO CEV":^30}')
print('='*30)
print(f'{"Empréstimo Bancário":^30}')
print('-'*30)
valor_casa = float(input('Qual é o valor da casa que você deseja comprar? R$'))
salario = float(input('Quanto é o seu salário? R$'))
anos = int(input('Em quantos anos você deseja pagar? '))
minimo = salario * 0.30
prestacao = valor_casa / (anos * 12)
print('='*30)
print(f'Para pagar uma casa de {valor_casa:.2f} em {anos} anos', end=' ')
print(f'a prestação será de R${prestacao:.2f}')
if minimo >= prestacao:
    print('Seu empréstimo foi aprovado!')
else:
    print('Seu empréstimo foi negado!')
print('='*30)