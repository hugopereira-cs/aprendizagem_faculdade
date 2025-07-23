from datetime import date

class Pessoa:
    def __init__(self, nome, idade):
        self.nome = nome
        self.idade = idade
    # Um método de classe para criar uma instância de Pessoa a partir de uma data de nascimento
    @classmethod
    def apartirAnoNascimento(cls, nome, ano):
        return cls(nome, date.today().year - ano)
# Método estático para verificar se é maior de idade
    @staticmethod
    def maiorDeIdade(idade):
        return idade >= 18
pessoa1 = Pessoa('Hugo', 33)
print(pessoa1.nome)
print(pessoa1.idade)
print(Pessoa.maiorDeIdade(pessoa1.idade))
pessoa2 = Pessoa.apartirAnoNascimento('LUG', 2013)
print(pessoa2.nome)
print(pessoa2.idade)
print(Pessoa.maiorDeIdade(pessoa2.idade))