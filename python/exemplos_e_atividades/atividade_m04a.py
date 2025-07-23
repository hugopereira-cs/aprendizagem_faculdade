hamburguer = 10.50
batata_frita = 4.00
refrigerante = 3.00

quantidade_hamburguer = int(input('Digite a quantidade de hambúrgueres desejado: '))
quantidade_batata = int(input('Digite a quantidade de batatas fritas desejada: '))
quantidade_refrigerante = int(input('Digite a quantidade de refrigerante desejada: '))

preco_total = (hamburguer * quantidade_hamburguer) + (batata_frita * quantidade_batata) + (refrigerante * quantidade_refrigerante)

print(f'O total da sua compra é R${preco_total:.2f}')