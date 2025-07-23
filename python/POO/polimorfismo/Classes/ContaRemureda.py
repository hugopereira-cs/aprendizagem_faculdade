from .ContaCliente import ContaCliente

# Classe com herança da contacliente

class ContaRemunerada(ContaCliente):
    def __init__(self, numero, IOF, IR, valor_investido, taxa_rendimento):
        super().__init__(numero, IOF, IR, valor_investido, taxa_rendimento)
    # Redefine o método calcular_rendimento para aplicar a taxa de rendimento sem  descontar nenhum imposto

    def calcular_rendimento(self):
        self.valor_investido += self.valor_investido * self.taxa_rendimento