# A composição é uma forma mais forte de associação, onde um objeto é parte de outro e não pode existir de forma independente

import datetime
from Extrato import Extrato

class Conta:
    def __init__(self, clientes, numero, saldo):
        self.clientes = clientes
        self.numero = numero
        self.saldo = saldo
        self.data_abertura = datetime.datetime.today()
        self.extrato = Extrato() # Inicializando a composição

    def depositar(self, valor):
        self.saldo += valor
        self.extrato.transacoes.append(['DEPOSITO', valor, 'Data', datetime.datetime.today()])

    def sacar(self, valor):
        if self.saldo < valor:
            return False
        else:
            self.saldo -= valor
            self.extrato.transacoes.append(['SAQUE', valor, 'Data', datetime.datetime.today()])
            return True
    
    def transfereValor(self, contaDestino, valor):
        if self.saldo < valor:
            return ('Não existe saldo suficiente')
        else:
            contaDestino.depositar(valor)
            self.saldo -= valor
            self.extrato.transacoes.append(['TRANSFERÊNCIA', valor, 'Data', datetime.datetime.today()])
            return ('Transferência realizada com sucesso.')
    
    def gerarSaldo(self):
        print(f'número: {self.numero}\nsaldo: {self.saldo}')