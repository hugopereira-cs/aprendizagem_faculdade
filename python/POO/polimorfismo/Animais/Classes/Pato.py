# Classe herdeira de Animal, Voador, Nadador
from.Animal import Animal
from .Voador import Voador
from .Nadador import Nadador

class Pato(Animal, Voador, Nadador):
    def falar(self):
        return 'Quack! Quack!'
    
    def mover(self):
        return f'{self.andar()}, {self.voar()}, {self.nadar()}'
    
    def andar(self):
        return f"{self.nome} está andando."