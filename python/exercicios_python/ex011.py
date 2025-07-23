print(' Calculadora de Pintor '.center(40, '='))
l = float(input('Informe a largura da parede: '))
a = float(input('Informe a altura da parede: '))
area = l * a
q_tinta = area * 0.5
print('='*40)
print(f'Sua parede tem a dimensão de {l}x{a}. A área dessa parede mede {area}m². Logo, a quantidade de tinta necessária para pintá-la será {q_tinta}l.')
print('='*40)