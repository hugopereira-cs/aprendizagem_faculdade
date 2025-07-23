# Criando exceções

class ErroPersonalizado(Exception): # Define a exceção customizada
    def __init__(self, mensagem, codigo_erro):
        super().__init__(mensagem)
        self.codigo_erro = codigo_erro

    def __str__(self):
        return f'[Erro {self.codigo_erro}]: {self.args[0]}'
    
def funcao_que_lanca_excecao(valor):
    if valor < 0:
        raise ErroPersonalizado('Valor não pode ser negativo!', 400)
    return f'O valor é {valor}'

try:
    resultado = funcao_que_lanca_excecao(-10)
    print(resultado)
except ErroPersonalizado as e:
    print(e)