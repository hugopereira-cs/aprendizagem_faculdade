/**
 * Sistema para registrar novas aquisições de livros
 */

#include <stdio.h>

int main() {
  char livro[100], autor[100];
  int paginas;

  printf("Digite o nome do livro: ");

  // Lê o nome do livro, incluindo espaços até encontrar uma nova linha
  // " %99[^\n]" especifica que deve ler até 99 caracteres ou até encontrar uma nova linha
  // O espaço antes do % é para ignorar qualquer espaço em branco inicial
  scanf(" %99[^\n]", livro);

  printf("Digite o nome do autor: ");
  scanf(" %99[^\n]", autor);

  printf("Digite o número de páginas: ");
  scanf("%d", &paginas);

  printf("\nVoce registrou o livro: '%s' de %s com %d paginas.\n", livro, autor, paginas);

  return 0;
}