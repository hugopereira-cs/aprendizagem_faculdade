def calcular_expressao():
    # Solicitar ao usuário que insira uma expressão matemática
    expressao = input('Digite uma expressão matemática: ')

    try:
        # Avaliar a expressão usando eval
        resultado = eval(expressao)
        print('O resultado da expressão é: ', resultado)
    except:
        print('Erro ao avaliar a expressão: ', expressao)

# Chamar a função
calcular_expressao()