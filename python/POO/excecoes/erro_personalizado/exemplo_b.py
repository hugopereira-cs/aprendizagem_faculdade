class SaldoInsuficiente(Exception):
    def __init__(self, saldo, valor_saque):
        mensagem = f'Saldo insuficiente. Saldo atual: {saldo} valor do saque: {valor_saque}'
        super().__init__(mensagem)
        self.saldo = saldo
        self.valor_saque = valor_saque

    def __str__(self):
        return f'SandoInsuficiente: {self.args[0]}'
    
class ContaBancaria:
    def __init__(self, saldo):
        self.saldo = saldo

    def sacar(self, valor):
        if valor > self.saldo:
            raise SaldoInsuficiente(self.saldo, valor)
        self.saldo -= valor
        return self.saldo
    
# Criando uma conta bancária com saldo de 100
conta = ContaBancaria(100)

try:
    conta.sacar(250) # Tentando sacar um valor maior que o saldo
except SaldoInsuficiente as e:
    print(e)