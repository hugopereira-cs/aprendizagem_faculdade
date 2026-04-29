/** Desenvolva um programa em C que atue como um sistema de registro para uma conferência. Porém, você deve levar em consideração algumas premissas:

 

O programa deve ser capaz de salvar informações de participantes em um arquivo de texto e, simultaneamente, registrar o número deles em um arquivo binário.
 

O programa também deve conseguir ler os arquivos para verificar o número atual de participantes e listar todos os registrados.
*/

#include <stdio.h>

int main() {
  FILE *fpTexto, *fpBinario; // Declara ponteiros para os arquivos de texto e binário
  char nome[100];
  int contador = 0;

  // Abertura dos arquivos
  fpTexto = fopen("participantes.txt", "a+"); // Abre ou cria o arquivo de texto no modo de adicionar ao final
  fpBinario = fopen("contador.bin", "rb+"); // Tenta abrir o arquivo binário no modo de leitura e escrita

  if (fpBinario == NULL) {
    // Se o arquivo binário não existir, cria-o no modo de ecrita e leitura
    fpBinario = fopen("contador.bin", "wb+");
    fwrite(&contador, sizeof(int), 1, fpBinario); // Escreve o valor inicial do contador (0) no arquivo binário
  } else {
    // Se o arquivo binário existir, lê o valor do contador
    fread(&contador, sizeof(int), 1, fpBinario);
  }

  // Solicita ao usuário para digitar o nome do participante
  printf("Digite o nome do participante: ");
  scanf(" %[^\n]", nome);

  // Escreve o nome do participante no arquivo de texto
  fprintf(fpTexto, "%s\n", nome);

  // Incrementa o contador de participantes
  contador++;

  // Volta para o início do arquivo binário
  rewind(fpBinario);

  // Atualiza o contador no arquivo binário
  fwrite(&contador, sizeof(int), 1, fpBinario);

  // Fecha os arquivos
  fclose(fpTexto);
  fclose(fpBinario);

  // Imprime o total de participantes registrados
  printf("Total de participantes registrados: %d\n", contador);

  // Retorna 0 para indicar que o programa terminou corretamente
  return 0;
}