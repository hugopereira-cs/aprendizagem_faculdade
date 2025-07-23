salada = 10.50
batata_palha = 4.00
refrigerante = 3.00

quantidade_salada = int(input('Digite a quantidade de salada desejada: '))
quantidade_batata = int(input('Digite a quantidade de batatas palha desejada: '))
quantidade_refrigerante = int(input('Digite a quantidade de refrigerante desejada: '))

preco_total = (salada * quantidade_salada) + (batata_palha * quantidade_batata) + (refrigerante * quantidade_refrigerante)

print(f'O preço total do seu pedido é R${preco_total:.2f}')