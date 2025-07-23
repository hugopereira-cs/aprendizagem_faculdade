# Realizando a composição

from Cliente import Cliente
from ContaClienteExtrato import Conta

cliente1 = Cliente(123, 'João', 'Rua X')
cliente2 = Cliente(456, 'Maria', 'Rua Z')
conta1 = Conta([cliente1, cliente2], 1, 2000)

conta1.depositar(1000)
conta1.sacar(1500)
conta1.extrato.extrato(conta1.numero)