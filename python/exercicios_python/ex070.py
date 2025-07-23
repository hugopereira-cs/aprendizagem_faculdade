produto = mais_barato = ' '
total = mais_de_mil = preco_mais_barato = cont = 0
print('-'*32)
print('        LOJA SUPER BARATÃO        ')
print('-'*32)
while True:
    produto = str(input('Nome do Produto: '))
    preco = float(input('Preço: R$'))
    cont += 1
    total += preco

    if cont == 1 or preco < preco_mais_barato:
        preco_mais_barato = preco
        mais_barato = produto

    if preco > 1000:
        mais_de_mil += 1

    resp = ' '
    while resp not in 'SN':
        resp = str(input('Quer continuar? [S/N] ')).strip().upper()
    
    if resp == 'N':
        break

print('-'*11, 'FIM DO PROGRAMA', '-'*11)
print(f'O total da compra foi R${total:.2F}')
print(f'Temos {mais_de_mil} produtos custando mais de R$1000.00')
print(f'O produto mais barato foi {mais_barato} que custa R${preco_mais_barato:.2F}')