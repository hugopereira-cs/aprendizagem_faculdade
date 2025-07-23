from Conta import Conta
from ContaPoupanca import Poupanca

class ContaRemuneradaPoupanca(Conta, Poupanca): #Herança múltipla
    def __init__(self, taxa_remuneracao, clientes, numero, saldo):
        Conta.__init__(self, clientes, numero, saldo)
        Poupanca.__init__(self, taxa_remuneracao)

    def remuneraConta(self):
        self.saldo += self.saldo * (self.taxaremuneracaoMes / 30)
