import os
import shutil # Módulo que contém a interface shutil.move (que usaremos) que permite movimentar arquivos

def criar_diretorios(diretorios):
  for diretorio in diretorios:
    if not os.path.exists(diretorio):
      try:
        os.mkdir(diretorio)
        print(f"Diretorio {diretorio} criado com sucesso.")
      except PermissionError:
        print(f"Sem permissão para criar o diretorio {diretorio}.")
      except Exception as e:
        print(f"Erro inesperado ao criar o diretorio {diretorio}: {e}")


def mover_arquivos(diretorio_origem):
  for arquivo in os.listdir(diretorio_origem):
    caminho_arquivo = os.path.join(diretorio_origem, arquivo)
    if os.path.isfile(caminho_arquivo):
      extensao = arquivo.split('.')[-1].lower() # Separa (com ponto como separador) o nome do arquivo, e pega o último (-1) que é o tipo do arquivo (extensão)  
      if extensao in ['pdf', 'txt', 'jpg', 'svg', 'sql', 'png', 'zip', 'jar']:
        diretorio_destino = os.path.join(diretorio_origem, extensao) # Concatena o diretório de origem com a extensão para criar o caminho do diretório de destino.
        try:
          shutil.move(caminho_arquivo, diretorio_destino)
          print(f"{arquivo} movido para {arquivo}.")
        except PermissionError:
          print(f"Sem permissão para mover {arquivo}.")
        except Exception as e:
          print(f"Erro inesperado ao mover {arquivo}: {e}")
      else:
        print(f"Extensão {extensao} de {arquivo} não é suportada.")
      
def main():
  diretorio_trabalho = "/home/hugoper_cs-pop-os/Downloads"
  diretorios = [os.path.join(diretorio_trabalho, 'pdf'),
                os.path.join(diretorio_trabalho, 'txt'),
                os.path.join(diretorio_trabalho, 'jpg'),
                os.path.join(diretorio_trabalho, 'svg'),
                os.path.join(diretorio_trabalho, 'sql'),
                os.path.join(diretorio_trabalho, 'png'),
                os.path.join(diretorio_trabalho, 'zip'),
                os.path.join(diretorio_trabalho, 'jar')]
  
  # Criar diretórios sw não existirem
  criar_diretorios(diretorios)

  # Mover arquivos para os diretórios correspondentes
  mover_arquivos(diretorio_trabalho)

if __name__ == "__main__":
  main()