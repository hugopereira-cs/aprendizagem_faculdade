frase = str(input('Digite uma frase: ')).upper().strip()
print(f'A letra A aparece {frase.count('A')} vezes na frase.')
print(f'A primeira letra A está na posição {frase.find('A')+1}\nA última letra A está na posição {frase.rfind('A')+1}')