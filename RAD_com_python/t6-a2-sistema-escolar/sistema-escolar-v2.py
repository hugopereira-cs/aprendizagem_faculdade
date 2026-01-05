import tkinter as tk
from tkinter import ttk
import pandas as pd

# Classe principal
class PrincipalRAD:
  def __init__(self, win):
    # Componentes
    self.lblNome=tk.Label(win, text='Nome do Aluno:')
    self.lblNota1=tk.Label(win, text='Nota 1:')
    self.lblNota2=tk.Label(win, text='Nota 2:')
    self.lblMedia=tk.Label(win, text='Média:')
    self.txtNome=tk.Entry(win, bd=3)
    self.txtNota1=tk.Entry()
    self.txtNota2=tk.Entry()
    self.btnCalcular=tk.Button(win, text='Calcular Média', command=self.fCalcularMedia)
    # -------------- Componente TreeView ------------
    self.dadosColunas = ("Aluno", "Nota 1", "Nota 2", "Média", "Situação")
    

    self.treeMedias = ttk.Treeview(win, columns=self.dadosColunas, selectmode='browse')

    self.verscrlbar = ttk.Scrollbar(win,
                                    orient="vertical",
                                    command=self.treeMedias.yview)


    # Remover pack() para scrollbar, será posicionado com place()

    self.treeMedias.configure(yscrollcommand=self.verscrlbar.set)

    self.treeMedias.heading("Aluno", text="Aluno")
    self.treeMedias.heading("Nota 1", text="Nota 1")
    self.treeMedias.heading("Nota 2", text="Nota 2")
    self.treeMedias.heading("Média", text="Média")
    self.treeMedias.heading("Situação", text="Situação")
    

    self.treeMedias.column("Aluno", minwidth=0, width=100)
    self.treeMedias.column("Nota 1", minwidth=0, width=100)
    self.treeMedias.column("Nota 2", minwidth=0, width=100)
    self.treeMedias.column("Média", minwidth=0, width=100)
    self.treeMedias.column("Situação", minwidth=0, width=100)

    # Remover pack() e usar place() em vez disso
    # self.treeMedias.pack(padx=10, pady=10)


    #------------------------------------------
    # Posicionamento dos componentes na janela
    #------------------------------------------
    self.lblNome.place(x=100, y=50)
    self.txtNome.place(x=220, y=50)

    self.lblNota1.place(x=100, y=100)
    self.txtNota1.place(x=220, y=100)

    self.lblNota2.place(x=100, y=150)
    self.txtNota2.place(x=220, y=150)

    self.btnCalcular.place(x=100, y=200)

    self.treeMedias.place(x=100, y=300)
    self.verscrlbar.place(x=805, y=300, height=225)


    self.id = 0
    self.iid = 0

    self.carregarDadosIniciais()

  #------------------------------------------
  def carregarDadosIniciais(self):
    try:
      fsave = './t6-a2-sistema-escolar/planilhaAlunos.xlsx'
      dados = pd.read_excel(fsave)
      print(dados)

      u = dados.count()
      print('u:'+str(u))
      nn = len(dados['Aluno'])
      for i in range(nn):
        nome = str(dados['Aluno'][i])
        nota1 = str(dados['Nota 1'][i])
        nota2 = str(dados['Nota 2'][i])
        media = str(dados['Média'][i])
        situacao = dados['Situação'][i]

        self.treeMedias.insert('', 'end',
                               iid=self.iid,
                               values=(nome,
                                       nota1,
                                       nota2,
                                       media,
                                       situacao))


        self.iid += 1
        self.id += 1
    except:
      print('Ainda não existem dados para carregar.')

  #------------------------------------------
  # Salvar dados para uma planilha Excel
  #------------------------------------------
  def fSalvarDados(self):
    try:
      fsave = './t6-a2-sistema-escolar/planilhaAlunos.xlsx'
      dados = []

      # Percorre a tabela e adiciona cada linha em uma lista
      for line in self.treeMedias.get_children():
        lstDados = []
        for value in self.treeMedias.item(line)['values']:
          lstDados.append(value)

        dados.append(lstDados)

      # Cria um DataFrame a partir da lista de linhas
      df = pd.DataFrame(data=dados, columns=self.dadosColunas)

      # Abre uma conexão com a planilha e faz o salvamento
      planilha = pd.ExcelWriter(fsave)
      df.to_excel(planilha, 'Inconsistências', index=False)

      # Fecha a planilha
      planilha.close()
      print('Dados salvos')
  
    except:
      print('Não foi possível salvar os dados')

  #------------------------------------------
  # Calcula a média e verifica qual é a situação do aluno
  #------------------------------------------
  def fVerificarSituacao(self, nota1, nota2):
    media = (nota1 + nota2) / 2
    if (media >= 7.0):
      situacao = 'Aprovado'
    elif (media >= 5.0):
      situacao ='Recuperação'
    else:
      situacao = 'Reprovado'

    return media, situacao

  #------------------------------------------
  # Imprime os dados do aluno
  #------------------------------------------
  def fCalcularMedia(self):
    try:
      nome = self.txtNome.get()
      nota1 = float(self.txtNota1.get())
      nota2 = float(self.txtNota2.get())
      media, situacao = self.fVerificarSituacao(nota1, nota2)


      self.treeMedias.insert('', 'end',
                             iid=self.iid,
                             values=(nome,
                                     str(nota1),
                                     str(nota2),
                                     str(media),
                                     situacao))
      
      self.iid += 1
      self.id += 1

      self.fSalvarDados()
    except ValueError:
      print('Entre com valores válidos')
    finally:
      self.txtNome.delete(0, 'end')
      self.txtNota1.delete(0, 'end')
      self.txtNota2.delete(0, 'end')

#------------------------------------------
# Programa principal
#------------------------------------------
janela = tk.Tk()
principal = PrincipalRAD(janela)
janela.title('Bem Vindo ao RAD')
janela.geometry("800x600+10+10")
janela.mainloop()
