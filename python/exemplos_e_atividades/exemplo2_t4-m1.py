# for num in range (1000,10000):
#     menor = num % 100 #obtem o numero dos algarismos menos significativos
#     maior = num // 100 #obtem o numero dos algarismos mais significativos
#     raiz = menor + maior  #obtem a raiz

#     if (raiz * raiz ) == num: #valida se a raiz gera o numero testado
#         print(num)
#         print(menor)
#         print(maior)
#         print(raiz)
# print('terminou')
# print('saiu ', num)

# Solução mais efiviente
start = int(1000**0.5) # Aproximação da raiz quadrada de 1000

if start * start < 1000: 
	start += 1 # Ajusta para garantir que o quadrado seja pelo menos 1000 

end = int(9999**0.5) # Aproximação da raiz quadrada de 9999 

for raiz in range (start, end + 1): 
	num = raiz * raiz  #calcula o numero gerado pela raiz
	menor = num % 100  #obtem o numero dos algarismos menos significativos
	maior = num // 100  #obtem o numero dos algarismos mais significativos
 
	if (menor +maior) ==raiz:  #valida se a raiz corresponde a soma
		print(num)
		print(menor)
		print(maior)
		print(raiz)
print('terminou')
print('saiu ', raiz) 
