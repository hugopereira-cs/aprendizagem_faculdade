#include <stdio.h>
#include <stdlib.h>

#define TAM_NOME 30
#define MAX_FILA 5

typedef struct {
  char nome[TAM_NOME];
  int idade;
} Pessoa;

typedef struct {
  Pessoa itens[MAX_FILA];
  int inicio;
  int fim;
  int total;
} Fila;

void inicializarFila(Fila *f) {
  f->inicio = 0;
  f->fim = 0;
  f->total = 0;
}

int filaCheia(Fila *f) {
  return f->total == MAX_FILA;
}

int filaVazia(Fila *f) {
  return f->total == 0;
}

void inserir(Fila *f, Pessoa p) {
  if (filaCheia(f)) {
    printf("Fila cheia! Não é possível inserir.\n");
    return;
  }

  f->itens[f->fim] = p;
  f->fim = (f->fim + 1) % MAX_FILA;
  f->total++;
}

void remover(Fila *f, Pessoa *p) {
  if (filaVazia(f)) {
    printf("Fila vazia! Não é possível remover.");
    return;
  }

  *p = f->itens[f->inicio];
  f->inicio = (f->inicio + 1) % MAX_FILA;
  f->total--;
}

void mostrarFila(Fila *f) {
  printf("Fila: ");

  for (int i = 0, idx = f->inicio; i < f->total; i++, idx = (idx + 1) % MAX_FILA) {
    printf("[%s, %d] ", f->itens[idx].nome, f->itens[idx].idade);
  }

  printf("\n");
}

int main() {
  Fila f;
  inicializarFila(&f);

  // Insere algumas pessoas na fila
  Pessoa p1 = {"João", 25};
  Pessoa p2 = {"Maria", 30};
  Pessoa p3 = {"Hugo", 33};

  inserir(&f, p1);
  inserir(&f, p2);
  inserir(&f, p3);

  mostrarFila(&f); // Mostra a fila antes da remoção

  // Remove uma pessoa da fila
  Pessoa removida;
  remover(&f, &removida);
  printf("Pessoa removida: %s, %d\n", removida.nome, removida.idade);

  mostrarFila(&f);

  return 0;
}