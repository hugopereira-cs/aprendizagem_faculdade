# Criando exceções

class ErroPersonalizado(Exception): # Define a exceção customizada
    def __init__(self, mensagem, codigo_erro):
        super().__init__(mensagem)
        self.codigo_erro = codigo_erro

    def __str__(self):
        return f'[Erro {self.codigo_erro}]: {self.args[0]}'