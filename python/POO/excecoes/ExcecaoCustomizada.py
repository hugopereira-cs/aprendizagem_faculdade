# Permite a criação de exceções para diferenciar os erros gerados pelas bibliotecas
# da linguagem daqueles gerados pelas aplicações desenvolvidas

class ExcecaoCustomizada(Exception): # Define a exceção customizada
    pass

def checa_valor(valor): # define um método que, se for chamado, criará a exceção
    if valor < 0:
        raise ExcecaoCustomizada('Valor não pode ser negativo!')
    
def divide(a, b):
    return a / b