import tkinter as tk
from tkinter import ttk
from AppDB import AppDB

class PrincipalDB:
  def __init__(self, root, db):
    self.root = root
    self.db = db
    self.root.title("Gestão de Produtos")

    # Componentes da interface gráfica
    self.lblCodigo = tk.Label(root, text="Código")
    self.lblCodigo.grid(row=0, column=0)
    self.txtCodigo = tk.Entry(root)
    self.txtCodigo.grid(row=0, column=1)

    self.lblNome = tk.Label(root, text="Nome")
    self.lblNome.grid(row=1, column=0)
    self.txtNome = tk.Entry(root)
    self.txtNome.grid(row=1, column=1)

    self.lblPreco = tk.Label(root, text="Preço")
    self.lblPreco.grid(row=2, column=0)
    self.txtPreco = tk.Entry(root)
    self.txtPreco.grid(row=2, column=1)

    self.btnCadastrar = tk.Button(root, text="Cadastrar", command=self.fCadastrarProduto)
    self.btnCadastrar.grid(row=3, column=0)
    self.btnAtualizar = tk.Button(root, text="Atualizar", command=self.fAtualizarProduto)
    self.btnAtualizar.grid(row=3, column=1)
    self.btnExcluir = tk.Button(root, text="Excluir", command=self.fExcluirProduto)
    self.btnExcluir.grid(row=4, column=0)
    self.btnLimpar = tk.Button(root, text="Limpar", command=self.fLimparTela)
    self.btnLimpar.grid(row=4, column=1)

    self.tree = ttk.Treeview(root, columns=("CODIGO", "NOME", "PRECO"), show='headings')
    self.tree.heading("CODIGO", text="Código")
    self.tree.heading("NOME", text="Nome")
    self.tree.heading("PRECO", text="Preço")
    self.tree.grid(row=5, column=0, columnspan=2)
    self.tree.bind('<ButtonRelease-1>', self.apresentarRegistrosSelecionados)

    self.carregarDadosIniciais()

  def fCadastrarProduto(self):
    codigo = self.txtCodigo.get()
    nome = self.txtNome.get()
    preco = self.txtPreco.get()
    
    # Validar se os campos estão preenchidos
    if not codigo or not nome or not preco:
      print("Erro: Preencha todos os campos!")
      return
    
    # Validar se o código é um número válido
    try:
      codigo = int(codigo)
    except ValueError:
      print("Erro: Código deve ser um número!")
      return
    
    # Tentar inserir os dados
    if self.db.inserir_dados(codigo, nome, preco):
      self.tree.insert("", "end", values=(codigo, nome, preco))
      self.fLimparTela()
    else:
      print("Cadastro não realizado. Verifique o erro acima.")

  def fAtualizarProduto(self):
    codigo = self.txtCodigo.get()
    nome = self.txtNome.get()
    preco = self.txtPreco.get()
    self.db.atualizar_dados(codigo, nome, preco)
    self.fLimparTela()
    self.carregarDadosIniciais()

  def fExcluirProduto(self):
    codigo = self.txtCodigo.get()
    self.db.excluir_dados(codigo)
    self.fLimparTela()
    self.carregarDadosIniciais()

  def fLimparTela(self):
    self.txtCodigo.delete(0, tk.END)
    self.txtNome.delete(0, tk.END)
    self.txtPreco.delete(0, tk.END)

  def apresentarRegistrosSelecionados(self, event):
    item = self.tree.selection()[0]
    valores = self.tree.item(item, "values")
    self.txtCodigo.delete(0, tk.END)
    self.txtCodigo.insert(0, valores[0])
    self.txtNome.delete(0, tk.END)
    self.txtNome.insert(0, valores[1])
    self.txtPreco.delete(0, tk.END)
    self.txtPreco.insert(0, valores[2])

  def carregarDadosIniciais(self):
    for item in self.tree.get_children():
      self.tree.delete(item)
    registros = self.db.selecionar_dados()
    for registro in registros:
      self.tree.insert("", "end", values=registro)

# Criando a interface gráfica
root = tk.Tk()
app_db = AppDB()
app_gui = PrincipalDB(root, app_db)
root.mainloop()