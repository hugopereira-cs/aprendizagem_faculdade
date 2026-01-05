import tkinter as tk
from tkinter import ttk

# Criando e configurando a janela
janela = tk.Tk()
janela.title("Sistema de Gestão Escolar")
janela.geometry("600x400")

# Criando os widgets
tk.Label(janela, text="Nome do Aluno:").pack()
entrada_nome = tk.Entry(janela)
entrada_nome.pack()

tk.Label(janela, text="Nota 1:").pack()
entrada_nota1 = tk.Entry(janela)
entrada_nota1.pack()

tk.Label(janela, text="Nota 2:").pack()
entrada_nota2 = tk.Entry(janela)
entrada_nota2.pack()

# Cria e configura a tabela (Treeview) para exibir os dados dos alunos.
tabela = ttk.Treeview(janela, columns=("Nome", "Nota 1", "Nota 2", "Média", "Situação"), show="headings")
tabela.heading("Nome", text="Nome do Aluno")
tabela.heading("Nota 1", text="Nota 1")
tabela.heading("Nota 2", text="Nota 2")
tabela.heading("Média", text="Média")
tabela.heading("Situação", text="Situação")
tabela.pack()

# Criando a barra de rolagem, para caso for necessário
scrollbar = ttk.Scrollbar(janela, orient="vertical", command=tabela.yview)
tabela.configure(yscrollcommand=scrollbar.set)
scrollbar.pack(side="right", fill="y")

# Insere os dados dos alunos via lista de tuplas
alunos_iniciais = [
  ("Alice", 8.5, 7.0),
  ("Bruno", 5.0, 6.0),
  ("Carlos", 3.5, 4.0),
  ("Daniela", 9.0, 9.5)
]

# Iterando sobre a lista para calcular a média e situação, e inserir na tabela
for aluno in alunos_iniciais:
  nome, nota1, nota2 = aluno
  media = (nota1 + nota2) / 2
  situacao = "Aprovado" if media >= 7 else "Recuperação" if media >= 5 else "Reprovado"
  tabela.insert("", "end", values=(nome, nota1, nota2, f"{media:.2f}", situacao))

# Função que cadastra um novo aluno na tabela e realiza os cálculos necessários
def cadastrar_aluno():
  nome = entrada_nome.get()
  nota1 = float(entrada_nota1.get())
  nota2 = float(entrada_nota2.get())
  media = (nota1 + nota2) / 2
  situacao = "Aprovado" if media >= 7 else "Recuperação" if media >=5 else "Reprovado"

  tabela.insert("", "end", values=(nome, nota1, nota2, f"{media:.2f}", situacao))

# Botão para cadastrar o aluno
tk.Button(janela, text="Cadastrar", command=cadastrar_aluno).pack()

# Iniciando o loop principal da interface
janela.mainloop()
