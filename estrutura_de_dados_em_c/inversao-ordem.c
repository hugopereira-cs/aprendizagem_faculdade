#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 50
#define TAM_NOME 30

typedef struct {
  char nome[TAM_NOME];
  int idade;
} Pessoa;

typedef struct {
  Pessoa dados[MAX];
  int inicio, fim;
} Fila;

typedef struct {
  Pessoa dados[MAX];
  int topo;
} Pilha;

// Inicializando a Fila e a Pilha
void incializarFila(Fila *f) {
  f->inicio = 0;
  f->fim = 0;
}

void inicializarPilha(Pilha *p) {
  p->topo = -1;
}

// Operações de Fila
void inserir(Fila *f, Pessoa p) {
  if (f->fim < MAX) {
    f->dados[f->fim++] = p;
  }
}

Pessoa remover(Fila *f) {
  return f->dados[f->inicio++];
}

// Operações de Pìlha
void push(Pilha *p, Pessoa pes) {
  if (p->topo < MAX - 1) {
    p->dados[++p->topo] = pes;
  }
}

Pessoa pop(Pilha *p) {
  return p->dados[p->topo--];
}

// Exibe a Fila
void exibirFila(Fila f) {
  for (int i = f.inicio; i  < f.fim; i ++) {
    printf("Nome: %s | Idade: %d\n", f.dados[i].nome, f.dados[i].idade);
  }
}

int main() {
  setlocale(LC_ALL, "Portuguese");

  Fila filaOriginal, filaInvertida;
  Pilha auxiliar;

  incializarFila(&filaOriginal);
  incializarFila(&filaInvertida);
  inicializarPilha(&auxiliar);

  Pessoa pessoas[] = {
    {"Carlos", 45}, {"Joana", 62}, {"Lucas", 30}, {"Maria", 75}
  };

  for (int i = 0; i < 4; i++) { // i < 4 (só tem 3 pessoas) garante que não saia do array
    inserir(&filaOriginal, pessoas[i]);
  }

  printf("Fila original:\n");
  exibirFila(filaOriginal);

  while (filaOriginal.inicio < filaOriginal.fim) {
    push(&auxiliar, remover(&filaOriginal));
  }

  while (auxiliar.topo >= 0) {
    inserir(&filaInvertida, pop(&auxiliar));
  }

  printf("Fila invertida:\n");
  exibirFila(filaInvertida);

  return 0;
}