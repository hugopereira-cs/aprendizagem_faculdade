nome = str(input('Digite seu nome completo: ')).strip()
dividido = nome.split()
print('Muito prazer em te conhecer!')
print(f'Seu primeiro nome é {dividido[0]}\nSeu último nome é {dividido[-1]}')
