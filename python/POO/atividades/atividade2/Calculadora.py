class Calculadora:

    # Criando os métodos adição, subtração, multiplicação e divisão
    def adicao(self, a, b):
        try:
            return a + b
        except TypeError:
            return 'Erro: Tipos de dados inválidos para adição.'

    def subtracao(self, a, b):
        try:
            return a - b
        except TypeError:
            return 'Erro: Tipos de dados inválidos para subtração.'

    def multiplicacao(self, a, b):
        try:
            return a * b
        except TypeError:
            return 'Erro: Tipos de dados inválidos para multiplicação.'

    def divisao(self, a, b):
        try:
            return a / b
        except TypeError:
            return 'Erro: Tipos de dados inválidos para divisão.'
        except ZeroDivisionError:
            return 'Erro: Não é possível dividir por zero.'
        
# Testando as implementações
calculadora = Calculadora()

print(calculadora.adicao(5, 3))
print(calculadora.subtracao(5, 3))
print(calculadora.multiplicacao(5, 3))
print(calculadora.divisao(5, 0))