def encontra_maior(lista):
    if not lista:
        return None
    maior = lista[0]
    for num in lista[1:]:
        if num > maior:
            maior = num
    return maior
        
num = [50, 2, 23, 4, 5, 6]
print(num)
print(f'O maior elemento encontrado na lista {num} foi {encontra_maior(num)}')
