/*
  Implementação Comparativa de BST e Trie em C

  O código permite inserir e buscar strings, além de visualizar percursos.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

#define VALOR_MAX 50

// ============= BST: Árvore Binária de Busca ==============

// Estrutura do nó da BST
typedef struct NoBST {
  char valor[VALOR_MAX];
  struct NoBST* esquerda;
  struct NoBST* direita;
} NoBST;

// Cria um novo nó BST
NoBST* criarNoBST(const char* valor) {
  NoBST* novo = (NoBST*)malloc(sizeof(NoBST)); // [PONTEIROS] malloc retorna o endereço do nó criado, que será manipulado via ponteiro.
  strcpy(novo->valor, valor);
  novo->esquerda = NULL; // [PONTEIROS] Um ponteiro nulo indica "não tem filho" (folha).
  novo->direita = NULL;
  return novo; // [PONTEIROS] Retorna o endereço do nó criado.
}

// Insere elemento na BST (ordem alfabética)
NoBST* inserirBST(NoBST* raiz, const char* valor) {
  if (raiz == NULL)
    return criarNoBST(valor);
  if (strcmp(valor, raiz->valor) < 0) 
    raiz->esquerda = inserirBST(raiz->esquerda, valor); // [PONTEIRO] Liga o campo "esquerda" para apontar para o novo subnó.
  else 
    raiz->direita = inserirBST(raiz->direita, valor); // [PONTEIRO] Liga o campo "direita" para apontar para o novo subnó.
  return raiz; // [PONTEIROS] Sempre deevolve o ponteiro (endereço) da raiz da árvore atualizada.
}

// Busca na BST - Complexidade logarítmica "O(log n)". A tendência é buscar apenas em metade da árvore.
bool buscarBST(NoBST* raiz, const char* chave) {
  if (raiz == NULL)
    return false;
  if (strcmp(chave, raiz->valor) == 0)
    return true;
  if (strcmp(chave, raiz->valor) < 0)
    return buscarBST(raiz->esquerda, chave); // [PONTEIROS] Vai seguindo o ponteiro para a esquerda.
  else
    return buscarBST(raiz->direita, chave); // [PONTEIROS] Vai seguindo o ponteiro para a direita.
}

// Percurso em ordem (ordem alfabética)
// Visita a subárvore esquerda, o nó atual e depois a direita. Exibe valores em ordem alfabética (ou numérica).
void emOrdemBST(NoBST* raiz) {
  if (raiz != NULL) {
    emOrdemBST(raiz->esquerda);
    printf("%s ", raiz->valor);
    emOrdemBST(raiz->direita);
  }
}

// Libera memória da BST
void liberarBST(NoBST* raiz) {
  if (raiz != NULL) {
    liberarBST(raiz->esquerda);
    liberarBST(raiz->direita);
    free(raiz);
  }
}


// ================= Trie: Árvore de Prefixos Para Strings =====================
#define TAMANHO_ALFABETO 26

// Estrutura do Nó Trie
typedef struct NoTrie {
  struct NoTrie* filhos[TAMANHO_ALFABETO];
  bool ehFimDePalavra;
} NoTrie;

// Cria um novo nó Trie
NoTrie* criarNoTrie() {
  NoTrie* novo = (NoTrie*)malloc(sizeof(NoTrie));
  novo->ehFimDePalavra = false;
  for (int i = 0; i < TAMANHO_ALFABETO; i++) {
    novo->filhos[i] = NULL;
  }
  return novo;
}

// Normaliza string (maiúsculas, sem espaços/acentos)
void normalizar(const char* entrada, char* saida) {
  int j = 0;
  for (int i = 0; entrada[i] != '\0'; i++) {
    char c = entrada[i];
    if (c >= 'A' && c <= 'Z') c += 32; // Converte maiúscula
    if (c >='a' && c <='z') saida[j++] = c; // Apenas letras
  }
  saida[j] = '\0';
}

// Insere palavra na Trie
void inserirTrie(NoTrie* raiz, const char* palavra) {
  NoTrie* atual = raiz;
  for (int i = 0; palavra[i] != '\0'; i++) {
    int indice = palavra[i] - 'a';
    if (atual->filhos[indice] == NULL)
      atual->filhos[indice] = criarNoTrie();
    atual = atual->filhos[indice];
  }
  atual->ehFimDePalavra = true;
}

// Busca palavra na Trie
bool buscarTrie(NoTrie* raiz, const char* palavra) {
  NoTrie* atual = raiz;
  for (int i = 0; palavra[i] != '\0'; i++) {
    int indice = palavra[i] - 'a';
    if (atual->filhos[indice] == NULL)
      return false;
    atual = atual->filhos[indice];
  }
  return atual != NULL && atual->ehFimDePalavra;
}

// Lista palavras na Tire (lexicográfica)
void listarPalavras(NoTrie* no, char* buffer, int nivel) {
  if (no->ehFimDePalavra) {
    buffer[nivel] = '\0';
    printf("%s ", buffer);
  }
  for (int i = 0; i < TAMANHO_ALFABETO; i++) {
    if (no->filhos[i] != NULL) {
      buffer[nivel] = 'a' + i;
      listarPalavras(no->filhos[i], buffer, nivel +1);
    }
  }
}

// Liberar memória da Trie
void liberarTrie(NoTrie* no) {
  for (int i = 0; i < TAMANHO_ALFABETO; i++)
    if (no->filhos[i] != NULL)
      liberarTrie(no->filhos[i]);
  free(no);
}


int main() {
  setlocale(LC_ALL, "Portuguese");

  // ----------------- BST --------------------
  printf("\n======= BST =======\n");
  NoBST* raizBST = NULL;
  raizBST = inserirBST(raizBST, "Pegadas de Lama");
  raizBST = inserirBST(raizBST, "Chave perdida");
  raizBST = inserirBST(raizBST, "Livro com pagina faltando");
  raizBST = inserirBST(raizBST, "Lencol manchado");
  raizBST = inserirBST(raizBST, "Gaveta perdida");

  printf("Em ordem (BST): ");
  emOrdemBST(raizBST);
  printf("\nBuscar 'Lencol manchado' (BST): %s\n", buscarBST(raizBST, "Lencol manchado") ? "Encontrado" : "Não encontrado");
  printf("Buscar 'Oculos' (BST): %s\n", buscarBST(raizBST, "Oculos") ? "Encontrado" : "Não encontardo");

  // ------------------- Trie -------------------
  printf("\n===== Trie ======\n");
  NoTrie* raizTrie = criarNoTrie();
  char normalizada[100];

  // Inserção de palavras normalizadas (maiúsculo, sem espaço)
  normalizar("Pegadas de Lama", normalizada);
  inserirTrie(raizTrie, normalizada);
  normalizar("Chave perdida", normalizada);
  inserirTrie(raizTrie, normalizada);
  normalizar("Livro com pagina faltando", normalizada);
  inserirTrie(raizTrie, normalizada);
  normalizar("Lencol manchado", normalizada);
  inserirTrie(raizTrie, normalizada);
  normalizar("Gaveta perdida", normalizada);
  inserirTrie(raizTrie, normalizada);

  printf("Palavras na Trie: ");
  char buffer[100];

  // Visualização: Exibe dados em ordem (BST) ou prefixos (Trie)
  listarPalavras(raizTrie, buffer, 0);
  printf("\n");
  normalizar("Lencol manchado", normalizada);
  printf("Buscar 'lencolmanchado' (Trie): %s\n", buscarTrie(raizTrie, normalizada) ? "Encontardo" : "Não encontardo");
  normalizar("Oculos", normalizada);
  printf("Buscar 'oculos' (Trie): %s\n", buscarTrie(raizTrie, normalizada) ? "Encontardo" : "Não encontrado");

  //Liberação da memória
  liberarBST(raizBST);
  liberarTrie(raizTrie);


  return 0;
}