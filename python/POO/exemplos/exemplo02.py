from Conta import Conta
conta1 = Conta(1, 123, 'João', 0)
conta2 = Conta(3, 456, 'Maria', 0)
conta1.depositar(1000)
conta1.transfere_valor(conta2, 500)
print(conta1.saldo)
print(conta2.saldo)