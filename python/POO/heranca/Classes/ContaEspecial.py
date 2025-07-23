from Conta import Conta
import datetime

class ContaEspecial(Conta):
    def __init__(self, clientes, numero, saldo, limite):
        # super().__init__(clientes, numero, saldo) chama o construtor da classe pai
        # e inicializa os atributos herdados
        super().__init__(clientes, numero, saldo)
        # Atributo limite exclusivo da contaEspecial
        self.limite = limite

    # Polimorfismo
    # Sobrescrever o método sacar para adicionar a funcionalidade limite
    # Além do saldo até o limite definido e atualizar o valor do limite

    def sacar(self, valor):
        if (self.saldo + self.limite) < valor:
            print(f"Não existe saldo suficiente conta numero {self.numero} cliente {self.clientes.cpf}")
            return False
        else:
            self.saldo -= valor
            if (self.saldo < 0):
                self.limite += self.saldo
            self.extrato.transacoes.append(["SAQUE", valor, datetime.datetime.today()])
            return True

    # Método depositar precisa ser reescrito para a conta especial
    def depositar(self, valor):
        pass