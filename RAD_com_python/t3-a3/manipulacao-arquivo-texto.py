def main():
  print ("Digite suas frases. Digite 'sair' para terminar e salvar o arquivo.")
  frases = []
  while True:
    entrada = input("> ")
    if entrada.lower() == 'sair':
      break
    frases.append(entrada) # Adiciona a etrada do usuário na lista fases

# Por meio de iteração, armazena cada frase no arquivo txt
  with open("./t3-a3/meu_arquivo.txt", "w") as arquivo:
    for frase in frases:
      arquivo.write(frase + "\n")

  print("Arquivo original criado. Agora vamos manipular os dados.")
  dados_modificados = []

  # Lê cada linha do arquivo e realiza a manipulação de dados, salvando em uma outra lista
  with open("meu_arquivo.txt", "r") as arquivo:
    for linha in arquivo:
      dados_modificados.append(linha.strip().upper()) # Exemplo de manipulação: converter para maiúsculas

# Sobrescreve o arquivo original, já com a manipulação realizada
  with open("meu_arquivo.txt", "w") as arquivo:
    for linha in dados_modificados:
      arquivo.write(linha + "\n")
  print("O arquivo foi sobrescrito com os dados modificados.")

# Se eu estiver executando esse módulo diretamente, chame a função main
if __name__ == "__main__":
  main()