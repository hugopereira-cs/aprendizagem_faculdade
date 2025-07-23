from abc import ABC, abstractmethod

# Classe abstrat Veiculo
class Veiculo(ABC):
    @abstractmethod
    def mover(self):
        pass

    def ligar(self):
        pass