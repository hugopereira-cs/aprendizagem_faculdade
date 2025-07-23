import datetime
from Extrato import Extrato

class Conta:

    def __init__(self, clientes, numero, saldo):
        self.clientes = clientes
        self.numero = numero
        self.saldo = saldo
        self.data_abertura = datetime.datetime.today()
        self.extrato = Extrato()

    def depositar(self, valor):
        self.saldo += valor
        self.extrato.transacoes.append(['Depósito', valor, datetime.datetime.today()])

    def sacar (self, valor):
        if self.saldo < valor:
            print(f'Não existe saldo suficiente conta número {self.numero}')
            return False
        else:
            self.saldo -= valor
            self.extrato.transacoes.append(['Saque', valor, datetime.datetime.today()])
            return True
        
    def transfereValor(self, contaDestino, valor):
        if self.saldo < valor:
            return ('Não existe saldo suficiente')
        else:
            contaDestino.depositar(valor)
            self.saldo -= valor
            self.extrato.transacoes.append(['Transferência', valor, datetime.datetime.today()])
            return ('Transferência realizada com sucesso.')
        
    def gerarSaldo(self):
        print(f'numero: {self.numero}\nSaldo: R${self.saldo:10.2f}')
