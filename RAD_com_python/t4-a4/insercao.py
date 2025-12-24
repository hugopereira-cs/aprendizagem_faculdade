import sqlite3 as conector

# Abertura de conexão e aquisição de cursor
conexao = conector.connect("./meu_banco.db")
cursor = conexao.cursor()

# Execução de um comando
comando = '''INSERT INTO Pessoa (cpf, nome, nascimento, oculos)
             VALUES (12345678900, 'João', '2000-01-31', 1);'''

cursor.execute(comando)

# Efetivação do commit
conexao.commit()

# Fechamento do cursor e da conexão
cursor.close()
conexao.close()