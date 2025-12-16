#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 5
#define TAM_NOME 30

typedef struct {
  char nome[TAM_NOME];
  int idade;
} Pessoa;

typedef struct {
  Pessoa itens[TAM_NOME];
  int topo;
} Pilha;

void inicializarPilha(Pilha *p) {
  p->topo = -1;
}

int pilhaVazia(Pilha *p) {
  return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
  return p->topo == MAX - 1;
}

void push(Pilha *p, Pessoa nova) {
  if (pilhaCheia(p)) {
    printf("Pilha cheia! Não é possível inserir.\n");
    return;
  }

  p->topo++;
  p->itens[p->topo] = nova;
}

void pop(Pilha *p, Pessoa *removida) {
  if (pilhaVazia(p)) {
    printf("Pilha vazia! Não é possível remover.\n");
    return;
  }

  *removida = p->itens[p->topo];
  p->topo--;
}

void peek(Pilha *p, Pessoa *visualizada) {
  if (pilhaVazia(p)) {
    printf("Pilha vazia! Nada para mostrar.\n");
    return;
  }

  *visualizada = p->itens[p->topo];
}

void mostrarPilha(Pilha *p) {
  printf("Pilha (topo-> base):\n");
  for (int i = p->topo; i >= 0; i--) {
    printf("[%s, %d]\n", p->itens[i].nome, p->itens[i].idade);
  }
  printf("\n");
}


int main(){
  setlocale(LC_ALL, "Portuguese");

  Pilha p;
  inicializarPilha(&p);

  Pessoa a = {"Ana", 20};
  Pessoa b = {"Bruno", 35};
  Pessoa c = {"Carlos", 28};

  push(&p, a);
  push(&p, b);
  push(&p, c);

  mostrarPilha(&p);

  Pessoa removida;
  pop(&p, &removida);
  printf("Removida: %s, %d\n", removida.nome, removida.idade);

  mostrarPilha(&p);

  Pessoa topo;
  peek(&p, &topo);
  printf("Topo atual: %s, %d\n", topo.nome, topo.idade);

  return 0;
}