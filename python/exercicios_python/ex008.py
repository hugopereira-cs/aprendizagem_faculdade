print(' Conversor de Medidas '.center(40, '='))
m = float(input('Digite a medida em metros: '))
km = m / 1000
hm = m / 100
dam = m / 10
dm = m * 10
cm = m * 100
mm = m * 1000
print('='*40)
print(f'{m:.1f}m equivale a\n{km}km\n{hm}hm\n{dam}dam\n{dm:.0f}dm\n{cm:.0f}cm\n{mm:.0f}mm')
print('='*40)