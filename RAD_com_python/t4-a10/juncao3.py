import sqlite3 as conector
from modelo import Veiculo, Marca

# Abertura de conexao e aquisição de cursor
conexao = conector.connect("./meu_banco.db")
cursor = conexao.cursor()

# Definição dos comandos
comando = '''SELECT * FROM Veiculo JOIN Marca ON Marca.id = Veiculo.marca;'''
cursor.execute(comando)

# Recuperação dos resgistros
registros = cursor.fetchall()
for registro in registros:
  print(registro)
  marca = Marca(*registro[6:]) # As colunas de Marca ocuparão as colunas a partir da sexta coluna
  veiculo = Veiculo(*registro[:5], marca) # Ocupará as cinco primeiras colunas
  print("Placa:", veiculo.placa, ", Marca:", veiculo.marca.nome)

# Fechamento das conexões
cursor.close()
conexao.close()