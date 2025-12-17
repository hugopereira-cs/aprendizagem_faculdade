# Atributo do Objeto Tipo arquivo
import os
# Abrindo o arquivo no modo escrita
arquivo = open('exemplo.txt', 'w')

# Exibindo os atributos do arquivo
print("nome do arquivo: ", arquivo.name)
print("Modo de abertura: ", arquivo.mode)
print("Arquivo está fechado? ", arquivo.closed)

# Escrevendo no arquivo
arquivo.write("Olá, mundo")
# Fechando o arquivo
arquivo.close()

# Verificando se o arquivo está fechado
print("Arquivo está fechado agora? ", arquivo.closed)

# Exibindo caminhos relativo e absoluto
relPath = os.path.realpath('exemplo.txt')
absPath = os.path.abspath('exemplo.txt')

print("Caminho relativo: ", relPath)
print("Caminho absoluto: ", absPath)


#exit()