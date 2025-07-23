soma_idade = idade_mais_velho = m_menos20 = 0
mais_velho = ' '
for i in range(1, 5):
    nome = str(input('Nome: ')).strip()
    idade = int(input('Idade: '))
    sexo = str(input('Sexo: [M/F] ')).strip().upper()[0]
    soma_idade += idade
    media = soma_idade / 4
    if sexo == 'M':
        if i == 1 or idade > idade_mais_velho:
            idade_mais_velho = idade
            mais_velho = nome
    if sexo == 'F' and idade < 20:
        m_menos20 += 1

print(f'A média de idade do grupo é {media:.1f}.')
print(f'{mais_velho} é o homem mais velho do grupo, com {idade}.')
print(f'Tem {m_menos20} mulheres com menos de 20 anos no grupo.')