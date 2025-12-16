/**
 * Implemantação de Árvore Binária Em C
 * ---------------------------------------
 * Este programa permite:
 *  - Inserir elementos na árvore binária (alocação dinâmica)
 *  - Percorrer e exibir os elementos usando:
 *    - Pré-ordem
 *    - Em ordem
 *    - Pós-ordem
 *    
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <locale.h>

 #define MAX_VALOR 50

 // Estrutura do Nó da Árvore Binária
typedef struct No {
  char valor[VALOR_MAX];
  struct No* esquerda;
  struct No* direita;
} No;

// Aloca dinamicamente um novo nó, define o valor
// e inicializa os ponteiros dos filhos como NULL
No* criarNo( const char* valor) {
  No* novo = (No*)malloc(sizeof(No)); // Alocação dinâmica de memória
  if (novo == NULL) {
    printf("Erro ao alocar memória!\n");
    exit(1); // Encerra o programa em caso de erro de memória
  }
  strcpy(novo->valor, valor); // Copia a string valor para o campo do nó
  novo->esquerda = NULL; // Inicializa filho esquerdo como NULL
  novo->direita = NULL; // Inicializa filho direito como NULL
  return novo;
}

// Insere um novo valor na árvore binária de forma recursiva.
// A ordem alfabética é utilizada para organizar os nós.
No* inserir(No* raiz, const char* valor) {
  if (raiz == NULL) {
    // Se a árvore ou subárvore está vazia, cria um novo nó
    return criarNo(valor);
  }
  if (strcmp(valor, raiz->valor) < 0) { // Se valor for < que nó atual
    // Insere na subárvore esquerda
    raiz->esquerda = inserir(raiz->esquerda, valor);
  } else {
    // Insere na subárvore direita
    raiz->direita = inserir(raiz->direita, valor);
  }
  return raiz;
}

// Funções para percorrer a árvore
void preOrdem(No* raiz) {
  if (raiz != NULL) {
    printf("%s " , raiz->valor); // Visita o nó atual (raiz)
    preOrdem(raiz->esquerda); // Visita a subárvore esquerda
    preOrdem(raiz->direita); // Visita a subárvore direita
  }
}

void emOrdem(No* raiz) {
  if (raiz != NULL) {
    emOrdem(raiz->esquerda); // Esquerda primeiro
    printf("%s ", raiz->valor); // Depois a raiz
    emOrdem(raiz->direita); // Direita por último
  }
}

void posOrdem(No* raiz) {
  if (raiz != NULL) {
    posOrdem(raiz->esquerda); // Esquerda primeiro
    posOrdem(raiz->direita); // Depois direita
    printf("%s ", raiz->valor); // raiz por último
  }
}

void liberar(No* raiz) {
  if (raiz != NULL) {
    liberar(raiz->esquerda);
    liberar(raiz->direita);
    free(raiz); // Libera o nó atual
  }
}

 // Função main: Montagem da Árvore e Demonstração dos Percursos
 int main() {
  setlocale(LC_ALL, "Portuguese");

  No* raiz = NULL; // Inicializa a árvore vazia

  // Insere elementos na árvore (valores de exemplo)
  raiz = inserir(raiz, "Hall de Entrada");
  // Insereção dos valores iniciais
  raiz = inserir(raiz, "Sala de Estar");
  raiz = inserir(raiz, "Biblioteca");
  raiz = inserir(raiz, "Quarto");

  // Exibe os elementos da árvore em cada tipo de percurso
  printf("Pré-ordem: ");
  preOrdem(raiz);
  printf("\n");

  printf("Em ordem: ");
  emOrdem(raiz);
  printf("\n");

  printf("Pós-ordem: ");
  posOrdem(raiz);
  printf("\n");

  // Libera toda a memória alocada para a árvore
  liberar(raiz);

  return 0;
 }