print(' Conversor de Moedas '.center(50, '='))
real = float(input('Quantos Reais você tem na carteira? R$'))
usd = real / 5.477
aud = real / 3.5565
nzd = real / 3.2852
eur = real / 6.4108
cad = real / 4.0063
gbp = real / 7.4484
# Conversões feitas com cotações do dia 07/07/2025
print('='*50)
print(f'Com R${real:.2f} você pode comprar:\nUS${usd:.2f}')
print(f'${aud:.2f} AUD')
print(f'${nzd:.2f} NZD')
print(f'${eur:.2f} EUR')
print(f'${cad:.2f} CAD')
print(f'${gbp:.2f} GBP')
print('='*50)