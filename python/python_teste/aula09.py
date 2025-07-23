frase = 'Curso em Vídeo Python'
print(frase[:13])

print('Oi')

print("""O céu estava coberto por nuvens cor de chumbo, anunciando uma tempestade iminente.
No parque, as folhas dançavam ao sabor do vento, como se celebrassem a mudança.
Um cachorro solitário observava o movimento com olhos curiosos e atentos.
Ao longe, o som de um trovão ecoou, fazendo os pássaros alçarem voo em desespero.
E naquele instante, tudo pareceu suspenso no tempo, como se o mundo prendesse a respiração.""")
print()
print(frase.upper().count('O'))
print()
frase = frase.replace('Python', 'Android')
print(frase)

print(frase.lower().find('vídeo'))

dividido = (frase.split())
print(dividido[0])
print(dividido[2][3])
