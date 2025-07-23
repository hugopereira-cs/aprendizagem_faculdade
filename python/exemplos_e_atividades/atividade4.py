inteiro = int(input('Digite um número inteiro: '))
flut = float(input('Digite um número de ponto flutuante: '))
boole = input('Digite um valor booleano (True ou False): ')
boole = boole.lower() # Converte para minúsculas para garantir que seja reconhecido como booleano
boole = boole == 'true' # Converte para tipo bool
print('Valores convertidos:')
print(f'- Número inteiro: {inteiro} (tipo: {type(inteiro).__name__})\n- Número de ponto flutuante: {flut} (tipo: {type(flut).__name__})\n- Valor booleano: {boole} (tipo: {type(boole).__name__})')