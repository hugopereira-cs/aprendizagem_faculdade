from ExcecaoCustomizada import ExcecaoCustomizada, checa_valor, divide
# Indica para o interpretador que a área do código localizada
# entre o try e o except poderá lançar exceções

try:
    resultado = divide(10, 0)
except ZeroDivisionError as ex:
    print(f'Erro de divisão por zero: {ex}')

try:
    checa_valor(-10)
except ExcecaoCustomizada as ex:
    print(f'Exceção customizada lançada: {ex}')