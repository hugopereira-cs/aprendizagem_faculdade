# Realizando a agregação
from Conta import Conta
from Cliente import Cliente

cliente1 = Cliente(123, 'João', 'Rua 1')
cliente2 = Cliente(456, 'Maria', 'Rua 2')
# Criando uma conta com dois clientes, fazendo a agregação com uma lista
conta1 = Conta([cliente1, cliente2], 1, 0)

conta1.gerarSaldo()
conta1.depositar(1500)
conta1.sacar(500)
conta1.gerarSaldo()