#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Define uma constante para o comprimento máximo que cada texto pode ter.
#define MAX_STR_LEN 50

// PARTE 1: LISTA ESTÁTICA

// Define uma constante para o número máximo de itens que nossa lista pode conter.
#define TAM_MAX 10

// Estruutura que representa a lista estática
typedef struct {
  char dados[TAM_MAX][MAX_STR_LEN]; // Matriz: 10 linhas (itens), 50 colunas (caracteres por item)
  int quantidade; // Contador de controle. Ele informa quantos itens estão realmente na lista.
} ListaEstatica;

// Funçõe da Lista Estática
// Essa função prepara lista para ser usada
// Ela simplesmente define o contador quantiddade como 0, indicando que a lista está vazia.
// Recebemos um ponteiro (*lista) para modificar a variável original passada para a função.
void inicializarListaEstatica(ListaEstatica *lista);

void inserirListaEstatica(ListaEstatica *lista, const char* texto);
void removerListaEstatica(ListaEstatica *lista, const char* texto);
void listarListaEstatica(const ListaEstatica *lista);

// PPARTE 2: LISTA ENCADEADA (DE STRINGS)
// Estrutura do nó (cada elemento da lista)
// - char* dado: Este é o ponteiro. Ele não armazena o texto em si, mas sim o endereço
// de memória onde o texto está guardado.
// Isso é muito flexível, pois cada texto pode ter um tamanho diferente, e alocamos apenas
// a memória necessária para cada um.
// - struct No *proximo: este é o ponteiro que cria a "ligação". Ele armazena o endereço do próximo nó na lista.
// O último nó da lista terá esse ponteiro apontando para NULL.
typedef struct No {
  char* dado;
  struct No *proximo;
} No;

// Isso é um atalho. Em vez de escrever No* sempre que quisermos nos referir à nossa lista, basta usar "ListaEncadeada"
// A "lista" em si é apenas um ponteiro para o primeiro nó (a cabeça da lista).
typedef No* ListaEncadeada;

// Funções da Lista Encadeada

// Uma lista encadeada vazia é representada por um ponteiro de cabeça que aponta para NULL.
// Essa função simplesmente atribui NULL ao ponteiro que representa a nossa lista.
void inicializarListaEncadeada(ListaEncadeada *lista);

void inserirListaEncadeada(ListaEncadeada *lista, const char* texto);
void removerListaEncadeada(ListaEncadeada *lista, const char* texto);
void listarListaEncadeada(const ListaEncadeada lista);
void liberarListaEncadeada(ListaEncadeada *lista);

// FUNÇÃO PRINCIPAL (MAIN) E MENUS

void menuListaEstatica();
void menuListaEncadeada();

int main() {

  setlocale(LC_ALL, "Portuguese");

  int opcao;
  do {
    printf("\n--- MANIPULAÇÃO DE LISTAS (TEXTO) ---\n");
    printf("1. Lista Estática\n");
    printf("2. Lista Encadeada\n");
    printf("0. Sair\n");
    printf("Escolha um opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        menuListaEstatica();
        break;
      case 2:
        menuListaEncadeada();
        break;
      case 0:
        printf("Saindo do programa...\n");
        break;
      default:
        printf("Opção inválida!");
    }
  } while (opcao != 0);
  
  return 0;
}


// IMPLEMENTAÇÃO DAS FUNÇÕES

void inicializarListaEstatica(ListaEstatica *lista) {
  lista->quantidade = 0;
}

void inserirListaEstatica(ListaEstatica *lista, const char* texto) {
  // Verifica se lista->quantidade atingiu TAM_MAX.
  // Se sim, a lista está chei e a função retorna.
  if(lista->quantidade == TAM_MAX) {
    printf("ERRO: Lista cheia! Não é possível inserir.\n");
    return;
  }
  // A inserção ocorre na primeira "linha" livre da matriz.
  // Para strings, não podemos fazer lista->dados[i] = texto, porque em C não se pode atribuir vetores/strings com o operador "=".
  // Precisamos copiar o contúdo da string para a posição correta na nossa matriz dados.
  strcpy(lista->dados[lista->quantidade], texto);
  // Após a cópia, lista->quantidade é incrementada, pois agora temos mais um item na lista.
  lista->quantidade++;
  printf("Texto \"%s\" inserido com sucesso.\n", texto);
}

void removerListaEstatica(ListaEstatica *lista, const char* texto) {
  int pos = -1;
  // Para comparar strings usamos strcmp(). Retorna 0 se forem iguais.
  // A função percorre os itens em uso na lista (de 0 até quantidade).
  // Para comparar strings, usamos strcmp(string1, string2).
  // Essa função retorna 0 se as strings forem idênticas. Se encontrar, guarda a posição (pos) e para o loop.
  for (int i = 0; i < lista->quantidade; i++) {
    if(strcmp(lista->dados[i], texto) == 0) {
      pos = i;
      break;
    }
  }

  // Tratamento de Erro: Se o loop terminar e pos continuar -1, o item não foi encontrado
  if (pos == -1) {
    printf("ERRO: Texto \"%s\" não encontrado na lista.\n", texto);
  }

  // Fecha a Lacuna: Se removenos um item do meio da lista, criamos um "buraco".
  // Para preenchê-lo, movemos todos os item subsequentes uma posição para a esquerda.
  // O loop for começa na posição do item removido e copia cada item i+1 para a posição i.
  // Deslocar os elementos posteriores para a esquerda usando strcpy.
  for (int i = pos; i < lista->quantidade -1; i++) {
    strcpy(lista->dados[i], lista->dados[i + 1]);
  }

  // Atualização do Contador: Finalente, quantidade é decrementada para refletir que a lista tem um item a menos.
  lista->quantidade--;
  printf("Texto \"%s\" removido com sucesso.\n", texto);
}

void listarListaEstatica(const ListaEstatica *lista) {
  if (lista->quantidade == 0) {
    printf("A lista estática está vazia.\n");
    return;
  }
  printf("Itens da lista estática: [ ");
  for (int i = 0; i < lista->quantidade; i++) {
    printf("\"%s\" ", lista->dados[i]); // Usar %s para imprimir strings
  }
  printf("]\n");
}

// IMPLEMENTAÇÃO DAS FUNÇÕES - LISTA ENCADEADA

// Uma lista encadeada vazia é representada por um ponteiro de cabeça que aponta para NULL.
// Esta função simplesmente atribui NULL ao ponteiro que representa nossa lista.
void inicializarListaEncadeada(ListaEncadeada *lista) {
  *lista = NULL;
}

void inserirListaEncadeada(ListaEncadeada *lista, const char* texto) {
  // 1. Alocar memória para o NOVO NÓ
  // Alocação do Nó: malloc(sizeof(No)) pede ao sistema operacional memória suficiente para um nó.
  // novoNo agora aponta para essa memória.
  No* novoNo = (No*) malloc(sizeof(No));

  if (novoNo == NULL) {
    printf("ERRO: Falha na alocação de memória para o no.\n");
    return;
  }

  // 2. Alocar memória para a STRING DENTRO DO NÓ
  // strlen(texto) + 1 para incluir o caracter nulo '\0' no final
  // Alocação da String: malloc(strlen(texto) + 1) aloca memória para o texto.
  // strlen conta todos os caracteres, e o +1 é vital para o caracter nulo (\0) que finaliza toda string em C.
  // novoNo->dado agora aponta para esse espaço.
  novoNo->dado = (char*) malloc(strlen(texto) + 1);

  if (novoNo->dado == NULL) {
    printf("ERRO: Falha na alocação de memória para o texto.\n");
    free(novoNo);
    return;
  }

  // 3. Copiar o texto para a memória recém-alocada
  // Cópia do Texto: strcpy copia o texto de entrada para a área de memória recém-alocada apontada por novoNo->dado.
  strcpy(novoNo->dado, texto);

  // 4. Ligar o novo nó à lista
  // O ponteiro próximo do novo nó passa a apontar para o que era o antigo primeiro nó da lista.
  novoNo->proximo = *lista;
  // A cabeça da lista (*lista) é atualizada para apontar para o novoNo. O novoNo é a gora o primeiro item.
  *lista = novoNo;

  printf("Texto\"%s\" inserida com sucesso.\n", texto);
}

void removerListaEncadeada(ListaEncadeada *lista, const char* texto) {
  // Usamos dois ponteiros, atual e anterior, para percorrer a lista. Atual avança, e anterior o segue.
  // Paramos quando atua aponta para o nó a ser removido.
  No *atual = *lista;
  No *anterior = NULL;

  while (atual != NULL && strcmp(atual->dado, texto) != 0) {
    anterior = atual;
    atual = atual->proximo;
  }

  if (atual == NULL) {
    printf("ERRO: Texto \"%s\" não encontrado na lista.\n", texto);
    return;
  }

  // Se o nó a ser removido for o primeiro (anterior == NULL), a cabeça da lista (*lista) passa a ser o segundo (atual)
  // Se estiver no meio/fim, o ponteiro próximo do nó anterior "pula" o atual e aponta para atual->proximo.
  if (anterior == NULL) {
    *lista = atual->proximo;
  } else {
    anterior->proximo = atual->proximo;
  }


  // Liberação de Memória (Muito Importante): Para evitar vazamento de memória (memory leak), precisamos devolver ao sistema.
  // Primeiro, free(atual->dado): Libera a memŕia que foi usada para guardar o texto.
  // Depois, free(atual): Libera a memória do próprio nó. Se fizéssemos o contrário, perderímos a referência para a string.

  // ANTES de liberar o nó, precisamos liberar a string DENTRO dele.
  free(atual->dado);
  // AGORA podemos liberar o nó.
  free(atual);
  printf("Texto \"%s\" removido com sucesso.\n", texto);
}

void listarListaEncadeada(const ListaEncadeada lista) {
  No *temp = lista;
  if (temp == NULL) {
    printf("A lista encadeada está vazia\n");
    return;
  }
  printf("Itens da Lista Encadeada: [");
  while (temp!= NULL) {
    printf("\"%s\" ", temp->dado);
    temp = temp->proximo;
  }
  printf("]\n");
}

// Função para liberar toda a memória da lista encadeada no final
// Ela percorre todos os nós da lista, um por um, e aplica a mesma lógica de liberação dupla (free(dado)
// e depois free(no)) para cada um deles, garantindo que nenhuma memória alocada seja deixada para trás quando o progerma for encerrado.
void liberarListaEncadeada(ListaEncadeada *lista) {
  No *atual = *lista;
  No *proximo;
  while (atual != NULL) {
    proximo = atual->proximo;
    free(atual->dado); // Libera a string
    free(atual); // Libera o nó
    atual = proximo;
  }
  *lista = NULL;
}

void menuListaEstatica() {
  ListaEstatica lista;
  inicializarListaEstatica(&lista);
  
  int opcao;
  char texto[MAX_STR_LEN];
  
  do {
    printf("\n--- MENU LISTA ESTÃTICA ---\n");
    printf("1. Inserir texto\n");
    printf("2. Remover texto\n");
    printf("3. Listar todos\n");
    printf("0. Voltar\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar(); // Limpa o buffer
    
    switch (opcao) {
      case 1:
        printf("Digite o texto a inserir: ");
        fgets(texto, MAX_STR_LEN, stdin);
        texto[strcspn(texto, "\n")] = '\0'; // Remove o \n
        inserirListaEstatica(&lista, texto);
        break;
      case 2:
        printf("Digite o texto a remover: ");
        fgets(texto, MAX_STR_LEN, stdin);
        texto[strcspn(texto, "\n")] = '\0';
        removerListaEstatica(&lista, texto);
        break;
      case 3:
        listarListaEstatica(&lista);
        break;
      case 0:
        printf("Voltando ao menu principal...\n");
        break;
      default:
        printf("Opção inválida!\n");
    }
  } while (opcao != 0);
}

void menuListaEncadeada() {
  ListaEncadeada lista;
  inicializarListaEncadeada(&lista);
  
  int opcao;
  char texto[MAX_STR_LEN];
  
  do {
    printf("\n--- MENU LISTA ENCADEADA ---\n");
    printf("1. Inserir texto\n");
    printf("2. Remover texto\n");
    printf("3. Listar todos\n");
    printf("0. Voltar\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar(); // Limpa o buffer
    
    switch (opcao) {
      case 1:
        printf("Digite o texto a inserir: ");
        fgets(texto, MAX_STR_LEN, stdin);
        texto[strcspn(texto, "\n")] = '\0';
        inserirListaEncadeada(&lista, texto);
        break;
      case 2:
        printf("Digite o texto a remover: ");
        fgets(texto, MAX_STR_LEN, stdin);
        texto[strcspn(texto, "\n")] = '\0';
        removerListaEncadeada(&lista, texto);
        break;
      case 3:
        listarListaEncadeada(lista);
        break;
      case 0:
        printf("Voltando ao menu principal...\n");
        liberarListaEncadeada(&lista);
        break;
      default:
        printf("Opção inválida!\n");
    }
  } while (opcao != 0);
}

