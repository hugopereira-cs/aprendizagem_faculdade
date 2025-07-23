class Televisao:
    def __init__(self, pcanal, min, max):
        self.canal = pcanal
        self.cMenor = min
        self.cMaior = max

    def diminuir_canal(self):
        if self.canal - 1 >= self.cMenor:
            self.canal -= 1
        else:
            self.canal = self.cMaior

    def aumentar_canal(self):
        if self.canal + 1 <= self.cMaior:
            self.canal += 1
        else:
            self.canal = self.cMenor

tv1 = Televisao(2, 2, 10)
print(f'Canal Sintonizado: {tv1.canal}')
print(f'Mudando canal para cima')
for i in range(1, 19):
    tv1.aumentar_canal()
    print(f'Canal Sintonizado: {tv1.canal}')

tv2 = Televisao(10, 2, 10)
print(f'Canal Sintonizado: {tv2.canal}')
print(f'Mudando canal para baixo')
for i in range(1, 20):
    tv2.diminuir_canal()
    print(f'Canal Sintonizado: {tv2.canal}')
