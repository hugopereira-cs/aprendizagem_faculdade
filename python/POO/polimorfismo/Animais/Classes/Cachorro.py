# Classe herdeira da classe Animal
from .Animal import Animal

class Cachorro(Animal):
    def falar(self):
        return "Au! Au!"

    def mover(self):
        return f'{self.nome} está andando.'
    