class Conta:
    def __init__(self, numero, saldo):
        self.__numero = numero #atributoprivado
        self.__saldo = saldo #atributoprivado

def main():
        conta = Conta(1, 1000)
        saldo = conta.saldo

if __name__ == "__main__":
    main()