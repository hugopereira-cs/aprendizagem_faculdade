from psycopg2 import Error
from faker import Faker
from cria_tabela import conexao, meu_cursor

class AppDB:
  def __init__(self):
    self.conn = None
    self.cur = None
    self.connect_to_db()

  def connect_to_db(self):
    self.conn = conexao
    self.cur = meu_cursor
    print("Conexão com o Banco de Dados aberta com sucesso!")

  def selecionar_dados(self):
    try:
      self.cur.execute("SELECT * FROM PRODUTO ORDER BY CODIGO")
      registros = self.cur.fetchall()
      return registros
    except (Exception, Error) as error:
      print("Erro ao selecionar dados", error)
      return []
  
  def produto_existe(self, codigo):
    """Verifica se um produto com o ID já existe"""
    try:
      self.cur.execute(
        '''SELECT CODIGO FROM PRODUTO WHERE CODIGO = %s''',
        (codigo,)
      )
      return self.cur.fetchone() is not None
    except (Exception, Error) as error:
      print("Erro ao verificar produto", error)
      return False
    
  def inserir_dados(self, codigo, nome, preco):
    """Insere um novo produto com validação de ID duplicado"""
    try:
      # Validar se o ID já existe
      if self.produto_existe(codigo):
        print(f"Erro: Produto com código {codigo} já existe!")
        return False
      
      self.cur.execute(
        '''INSERT INTO PRODUTO (CODIGO, NOME, PRECO) VALUES (%s, %s, %s)''',
        (codigo, nome, preco)
      )
      self.conn.commit()
      print("Dados inseridos com sucesso!")
      return True
    except (Exception, Error) as error:
      print("Erro ao inserir dados", error)
      return False

  def atualizar_dados(self, codigo, nome, preco):
    try:
      self.cur.execute(
        '''UPDATE PRODUTO SET NOME = %s, PRECO = %s WHERE CODIGO = %s''',
        (nome, preco, codigo)
      )
      self.conn.commit()
      print("Atualização realizada com sucesso!")
    except (Exception, Error) as error:
      print("Erro ao atualizar dados", error)

  def excluir_dados(self, codigo):
    try:
      self.cur.execute(
        '''DELETE FROM PRODUTO WHERE CODIGO = %s''',
        (codigo,)
      )
      self.conn.commit()
      print("Exclusão realizada com sucesso!")
    except (Exception, Error) as error:
      print("Erro ao excluir dados", error)

if __name__ == "__main__":
  app_db = AppDB()
  fake = Faker('pt_BR')

  for _ in range(10):
    nome = fake.word()
    preco = round(fake.random_number(digits=5) / 100, 2)
    app_db.inserir_dados(nome, preco)