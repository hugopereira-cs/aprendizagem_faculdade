import psycopg2

# Criar conexão
conexao = psycopg2.connect(
  database = "postgresDB",
  user = "usuario",
  password = "senha",
  host = "127.0.0.1",
  port = "5432"
)
print("Conexão com o Banco de Dados aberta com sucesso!")

# Criação do cursor
meu_cursor = conexao.cursor()

if __name__ == "__main__":
  # Criação da tabela
  meu_cursor.execute('''
                      CREATE TABLE IF NOT EXISTS PRODUTO (
                        CODIGO SERIAL PRIMARY KEY,
                        NOME VARCHAR(100) NOT NULL,
                        PRECO NUMERIC(10, 2) NOT NULL
                     );
                    ''')
  
  # Just in case
  conexao.commit()
  print("Tabela criada com sucesso!")
  conexao.close()