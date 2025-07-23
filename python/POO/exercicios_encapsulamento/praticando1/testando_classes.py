from Livro import Livro
from Biblioteca import Biblioteca

# Criando alguns livros
livro1 = Livro('O Senhor dos Anéis', 'J.R.R. Tolkien', '1234567890')
livro2 = Livro('1984', 'George Orwell', '0987654321')
livro3 = Livro('O Apanhador no Campo de Centeio', 'J.D. Salinger', '1122334455')

# Criando uma biblioteca
biblioteca = Biblioteca('Biblioteca Central')

# Adicionando livros à biblioteca
biblioteca.adicionar_livro(livro1)
biblioteca.adicionar_livro(livro2)
biblioteca.adicionar_livro(livro3)

# Listando todos os livros na biblioteca
biblioteca.listar_livros()

# Removendo um livro da biblioteca
biblioteca.remover_livro('0987654321')

# Listando todos os livros na biblioteca
biblioteca.listar_livros()

# Buscando livros pelo nome
biblioteca.buscar_livro('O Senhor dos Anéis')
biblioteca.buscar_livro('1984')
biblioteca.buscar_livro('O Apanhador no Campo de Centeio')
