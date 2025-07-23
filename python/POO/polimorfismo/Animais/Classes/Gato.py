# Classe herdeira da classe Animal

from .Animal import Animal

class Gato(Animal):
    def falar(self):
        return 'Miau! Miau!'
    
    def mover(self):
        return f'{self.nome} está andando.'
    