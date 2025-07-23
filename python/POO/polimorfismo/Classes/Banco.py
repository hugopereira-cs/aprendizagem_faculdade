# Classe que gerencia todas as contas e calcula o rendimento mensal

class Banco:
    def __init__(self, codigo, nome):
        self.codigo = codigo
        self.nome = nome
        self.contas = []
    # Métodos para dicionar contas,
    # calcular rendimento mensal, imprimir o saldo das contas
    def adicionar_conta(self, conta_cliente):
        self.contas.append(conta_cliente)

    def calcular_rendimento_mensal(self):
        for conta in self.contas:
            conta.calcular_rendimento()

    def imprimir_saldo_contas(self):
        for conta in self.contas:
            conta.extrato()
