# Classe base

class ContaCliente:
    def __init__(self, numero, IOF, IR, valor_investido, taxa_rendimento):
        self.numero = numero
        self.IOF = IOF
        self.IR = IR
        self.valor_investido = valor_investido
        self.taxa_rendimento = taxa_rendimento

    # Aplica a taxa de rendimento e desconta IOF e IR do valor investido
    def calcular_rendimento(self):
        remuneracao = self.valor_investido * self.taxa_rendimento
        valorIOF = remuneracao * self.IOF
        valorIR = remuneracao * self.IR
        self.valor_investido += remuneracao - valorIOF - valorIR

    def extrato(self):
        print(f'O saldo atual da conta {self.numero} é R${self.valor_investido:10.2f}')