
def fibo(n):
    'Determina o n-ésimo termo da sequência de Fibonacci'
    if n == 1 or n == 2:
        return 1
    else:
        return fibo(n - 1) + fibo(n - 2)

# Exibir os n primeiros termos da sequência
def exibir_fibonacci(qtd_termos):
    for i in range(1, qtd_termos + 1):
        print(fibo(i), end=' ')
    print('ACABOU!')

# Exemplo: exibir os 10 primeiros termos
exibir_fibonacci(10)
