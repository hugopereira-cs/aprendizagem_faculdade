import psycopg2

# Criar conexão
conexao = psycopg2.connect(
  host = 'localhost',
  database = 'postgresDB',
  user = 'usuario',
  password = 'senha'
)
print("Conexão com o Banco de Dados aberta com sucesso!")

# Criar cursor
meu_cursor = conexao.cursor()