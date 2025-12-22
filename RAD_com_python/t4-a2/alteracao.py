import sqlite3 as connector

try:
  # Abertura da conexão e aquisição do cursor
  conexao = connector.connect("./meu_banco.db")
  cursor = conexao.cursor()
  
  # Execução de um comando:
  comando = '''ALTER TABLE Veiculo
                  ADD motor REAL;'''
  
  cursor.execute(comando)

  # Efetivação do comando
  conexao.commit()

except connector.DatabaseError as err:
  print("Erro de banco de dados", err)

finally:
  # Fechamento das conexões
  if conexao:
    cursor.close()
    conexao.close()