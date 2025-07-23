from Classes.Animal import Animal
from Classes.Cachorro import Cachorro
from Classes.Gato import Gato
from Classes.Pato import Pato
from Classes.Vaca import Vaca


def fazer_som(animal):
    return animal.falar()

def fazer_movimento(animal):
    return animal.mover()


cachorro = Cachorro('Rex')
gato = Gato('Foquinho')
pato = Pato('Donald')
vaca = Vaca('Mimosa')

print(fazer_som(cachorro))  # Saída: Au! Au!
print(fazer_som(gato))      # Saída: Miau! Miau!
print(fazer_som(pato))      # Saída: Quack! Quack!
print(fazer_som(vaca))      # Saída: Muu!   

print(fazer_movimento(cachorro))  # Saída: Rex está andando.
print(fazer_movimento(gato))      # Saída: Foquinho está andando.
print(fazer_movimento(pato))      # Saída: Donald está andando, Donald está voando(), Donald está nadando.
print(fazer_movimento(vaca))      # Saída