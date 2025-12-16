import os

arquivo1 = open("dados1.txt", 'w') # Função para abrir o arquivo - 'w' instrui o programa a criar um caso ainda não exista
# OBS.: Caso esteja utilizando Windows, é recomendável colocar após o 'w', o seguinte: encoding='UTF-8'
# isso evita erros de caracteres

print(os.path.abspath(arquivo1.name)) # Retornará o caminho absoluto (onde o arquivo está localizado)



arquivo1.write("Olá, mundo!!!")

print(os.path.relpath(arquivo1.name))
print(arquivo1)

# É de suma importância encerrar o programa
arquivo1.close()