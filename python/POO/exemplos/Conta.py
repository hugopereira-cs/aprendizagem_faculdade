class Conta:
    def __init__(self, numero, cpf, nomeTitular, saldo):
        self.numero = numero
        self.cpf = cpf
        self.nomeTitular = nomeTitular
        self.saldo = saldo

    def depositar(self, valor):
        self.saldo += valor

    def sacar(self, valor):
        if self.saldo < valor:
            return False
        else:
            self.saldo -= valor
            return True

    def gerar_extrato(self):
        print(f'Número: {self.numero}\ncpf: {self.cpf}\nsaldo: {self.saldo}')

    def transfere_valor(self, contaDestino, valor):
        if self.saldo < valor:
            return ('Não existe valor suficiente.')
        else:
            contaDestino.depositar(valor)
            self.saldo -= valor
            return ('Transferência Realizada.')

def main():
    c1 = Conta(1, 1, 'João', 0)
    c1.depositar(500)
    saque = c1.sacar(400)
    c1.gerar_extrato()
    print('O saque foi realizado? ', saque)

if __name__ == '__main__':
    main()