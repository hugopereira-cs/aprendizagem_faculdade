#Exemplo de classe sem um método construtor:
class A():
    def f(self):
        print('foo')

def main():
    obj_A = A() # Objeto sendo instanciado
    obj_A.f()

if __name__ == '__main__':
    main()
