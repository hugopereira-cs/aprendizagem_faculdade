frase = str(input('Digite uma frase: ')).strip().upper()
palavras = frase.split()
junto = ''.join(palavras)
print(f'Você digitou a frase {frase}')
inverso = junto[::-1] # macete do fatiamento 
# for letra in range(len(junto) -1, -1, -1):
#     inverso += junto[letra]
print(f'O inverso é {inverso}')
if inverso == junto:
    print(f'{frase} é um palíndromo!')
else:
    print(f'{frase} não é um palíndroma!')