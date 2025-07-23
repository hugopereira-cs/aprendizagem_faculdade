from Classes.Veiculo import Veiculo

class Aviao(Veiculo):
    def mover(self):
        return 'O avião está voando.'
    
    def ligar(self):
        return 'O avião está ligado e pronto para decolar.'