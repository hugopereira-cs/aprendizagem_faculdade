import sqlite3 as conector

try:
  # Abertura de conexão e aquisição de Currsor
  conexao = conector.connect("./meu_banco.db")
  cursor = conexao.cursor()

  # Execução de um comando: SELECT... CREATE...
  comando = '''CREATE TABLE Marca (
                  id INTEGER NOT NULL,
                  nome TEXT NOT NULL,
                  sigla CHARACTER(2) NOT NULL,
                  PRIMARY KEY (id)
                  );'''
  
  cursor.execute(comando)

  # Efetivação do comando
  conexao.commit()

except conector.DatabaseError as err:
  print("Erro de banco de dados", err)

finally:
  # Fechamento das conexões
  if conexao:
    cursor.close()
    conexao.close()