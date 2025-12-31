from faker import Faker
from conectar import conexao, meu_cursor

# Configurando gerador
fake = Faker('pt_BR')

for _ in range(10): # Utilizamos o _ (underscore) em Python, como convenção, para indicar que não usamos uma variável de iteração.
  # O laço irá percorrer os números de 0 a 99, mas o valor de cada número não é importante para a lógica dentro do laço.
  nome = fake.word()
  preco = round(fake.random_number(digits=5) / 100, 2) # Gera um número aleatório com digitos, ao dividir por 100, ele
  # passará a ter 3 dígitos e duas casa decimais.
  print(nome, preco)
  meu_cursor.execute('''
                      INSERT INTO PRODUTO (NOME, PRECO) VALUES (%s, %s)
                    ''', (nome, preco))

conexao.commit()
print("Dados inseridos com sucesso!")
meu_cursor.close()
conexao.close()