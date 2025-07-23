from .ContaCliente import ContaCliente

# Classe com herança da contacliente

class ContaComum (ContaCliente):
    def __init__(self, numero, IOF, IR, valor_investido, taxa_rendimento):
        super().__init__(numero, IOF, IR, valor_investido, taxa_rendimento)
    # Redefine o método calcular_rendimento para aplicar a taxa de rendimento e descontar apenas o IOF

    def calcular_rendimento(self):
        remuneracao = self.valor_investido * self.taxa_rendimento
        valorIOF = remuneracao * self.IOF
        self.valor_investido += remuneracao - valorIOF
