// ===========================================================================
// PRÁTICA: SISTEMA DE BIBLIOTECA - PARTE 3
// 
//  OBJETIVO DESTA PARTE:
//  Modularizar o código com funções especializadas, aplicando boas práticas.
//  - Passagem por valor )para exibição) e por referência (para modificação).
//  - Funções para cada funcionalidade principal do sistema
//  - A função main() se torna um "orquestrador", chamando as outras.
//
// ===========================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para strspn()

// --- Constantes Globais ---
#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 100
#define TAM_STRING 100

// --- Definição de Estruturas (Structs) ---
struct Livro {
  char nome[TAM_STRING];
  char autor[TAM_STRING];
  char editora[TAM_STRING];
  int edicao;
  int disponivel; // 1 para sim, 0 para não. Funciona como um flag.
};

struct Emprestimo {
  int indiceLivro; // Para saber qual livro do array foi emprestado.
  char nomeUsuario[TAM_STRING];
};

// --- Protótipo de Funções ---
// Declarar as funções aqui permite que a 'main' as chame antes de suas definições.
void limparBufferEntrada();
void exibirMenu();
void cadastrarLivro(struct Livro *biblioteca, int *totalLivros);
void listarLivros(const struct Livro *biblioteca, int totalLivros);
void realizarEmprestimo(struct Livro *biblioteca, int totalLivros, struct Emprestimo *emprestimos, int *totalEmprestimos);
void listarEmprestimos(const struct Livro *biblioteca, const struct Emprestimo *eprestimos, int totalEmprestimos);
void realizarDevolucao(struct Livro *biblioteca, int totalLivros, struct Emprestimo *emprestimos, int *totalEmprestimos);
void liberarMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos);

// --- Função Principal (main) ---
// Agora a main é muito mais limpa. Ela aloca memória, controla o menu
// e delega as tarefas para as funções especializadas.
int main() {
  // ALOCAÇÃO DINÂMICA DE MEMÓRIA
  // Utilizando ponteiros
  struct Livro *biblioteca = (struct Livro*) calloc(MAX_LIVROS,sizeof(struct Livro));
  struct Emprestimo *emprestimos = (struct Emprestimo *) malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));
  
  // Usamos calloc para o array de livros. calloc(num_elementos, tamanho_de_cada_elemento)
  // Vantagem: inicializa toda a memória com zeros. Isso significa que 'disponível' já com o valor zerado.
  biblioteca = (struct Livro *) calloc(MAX_LIVROS, sizeof(struct Livro));

  // Usamos malloc para o array de empréstimos. malloc(tamanho_total_em_bytes)
  emprestimos = (struct Emprestimo *) malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));
  
  // VERIFICAÇÃO: É crucial verificar se a alocação de memória deu certo.
  if (biblioteca == NULL || emprestimos == NULL) {
    printf("ERRO: Falha ao alocar memória.\n");
    return 1; // Retorna 1 para identificar o erro.
  }
  
  int totalLivros = 0;
  int totalEmprestimos = 0;
  int opcao;
  
  //  --- Laço Principal do Menu ---
  do {
    exibirMenu();
    scanf("%d", &opcao);
    limparBufferEntrada();
    
    switch (opcao) {
      case 1:
        // Passamos o endereço de 'totalLivros' (&) para que a função possa MODIFICAR seu valor.
        cadastrarLivro(biblioteca, &totalLivros); 
        break;
        
      case 2:
        // Passamos apenas o valor, pois a função só precisa LER.
        listarLivros(biblioteca, totalLivros);
        break;
        
      case 3:
        realizarEmprestimo(biblioteca, totalLivros, emprestimos, &totalEmprestimos);  
        break;
      
      case 4: // LISTAR EMPRÉSTIMOS
        listarEmprestimos(biblioteca, emprestimos, totalEmprestimos);
        break;

      case 5:
        realizarDevolucao(biblioteca, totalLivros, emprestimos, &totalEmprestimos);
        break;
        
      case 0: // SAIR
        printf("\nSaindo do sistema...\n");
        break;
        
      default: // OPÇÂO INVÁLIDA
        printf("\nOpção inválida! Tente novamente.\n");
        printf("\n Pressione Enter para continuar...");
        getchar();
        break;
    }
  } while (opcao != 0);
  liberarMemoria(biblioteca, emprestimos);
  
  return 0;
};

// --- Implementação de Funções ---


void limparBufferEntrada() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
};

void exibirMenu() {
  printf("===================================\n");
  printf("    BIBLIOTECA - PARTE 1\n");
  printf("===================================\n");
  printf("1 - Cadastrar novo livro\n");
  printf("2 - Listar todos os livros\n");
  printf("3 - Realizar um empréstimo\n");
  printf("4 - Listar empréstimos\n");
  printf("5 - Devolver livro\n");
  printf("0 - Sair\n");
  printf("-----------------------------------\n");
  printf("Escolha uma opção: ");
};
  
void cadastrarLivro(struct Livro *biblioteca, int *totalLivros) {
  printf("--- Cadastro de Novo Livro ---\n\n");
      
  if (*totalLivros < MAX_LIVROS) {
    int indice = *totalLivros; // Usa o valor apontado pelo ponteiro para o índice.

    printf("Digite o nome do livro: ");
    fgets(biblioteca[indice].nome, TAM_STRING, stdin);
    
    printf("Digite o autor: ");
    fgets(biblioteca[indice].autor, TAM_STRING, stdin);
    
    printf("Digite a editora: ");
    fgets(biblioteca[indice].editora, TAM_STRING, stdin);
    
    biblioteca[indice].nome[strcspn(biblioteca[indice].nome, "\n")] = '\0';
    biblioteca[indice].autor[strcspn(biblioteca[indice].autor, "\n")] = '\0';
    biblioteca[indice].editora[strcspn(biblioteca[indice].editora, "\n")] = '\0';
    
    printf("Digite a edição: ");
    scanf("%d", &biblioteca[indice].edicao);
    limparBufferEntrada();
    
    /* importante: marcar livro como disponível ao cadastrar */
    biblioteca[indice].disponivel = 1;

    (*totalLivros)++; // Incrementa o valor da variável original na main.
    
    printf("\nLivro cadastrado com sucesso!\n");
  } else {
    printf("\nBiblioteca cheia! Não é possível cadastrar mais livros.\n");        
  }
  printf("\nPressione Enter para continuar...");
  getchar();
};

/*
 * @brief Lista todos os livros cadastrados.
 * @param biblioteca Oarray (ponteiro contante, apenas para leitura).
 * @param totalLivros O número de livros (passagem por valor).
 */
void listarLivros(const struct Livro *biblioteca, int totalLivros) {
  printf("--- Lista de Livros Cadastrados ---\n\n");
        
  if (totalLivros == 0) {
    printf("Nenhum livro cadastrado ainda. \n");
  } else {
    for (int i = 0; i < totalLivros; i++) {
      printf("-----------------------------------\n");
      printf("LIVRO %d\n", i + 1);
      printf("Nome: %s\n", biblioteca[i].nome);
      printf("Autor: %s\n", biblioteca[i].autor);
      printf("Editora: %s\n", biblioteca[i].editora);
      printf("Edição: %d\n", biblioteca[i].edicao);
    }
    printf("-----------------------------------\n");
  }
  // A pausa é crucial para que o usuário veja a lista antes do próximo loop limpar a tela.
  printf("Pressione Enter para continuar...");
  getchar();
};

/*
 * @brief Realiza o empréstimo de um livro.
 * @param biblioteca Array de livros (modificável, para alterar o status).
 * @param total de livros cadastrados.
 * @param emprestimos Array de empréstimos (modificável).
 * @param totalEmprestimos Ponteiro para o contador de empréstimos (para ser atualizado).
 */
void realizarEmprestimo(struct Livro *biblioteca, int totalLivros, struct Emprestimo *emprestimos, int *totalEmprestimos) {
  printf("--- REALIZAR EMPRÉSTIMO ---\n\n");
        
  if (*totalEmprestimos >= MAX_EMPRESTIMOS) {
    printf("Limite de empréstimos atingido!\n");
  } else {
    printf("Livros disponíveis:\n");
    int disponiveis = 0;
    for (int i = 0; i < totalLivros; i++) {
      if (biblioteca[i].disponivel) {
        printf("%d - %s\n", i + 1, biblioteca[i].nome);
        disponiveis++;
      }
    }
    
    if (disponiveis == 0) {
      printf("Nenhum livro disponível para empréstimo.\n");
    } else {
      printf("\nDigite o número do livro que deseja emprestar: ");
      int numLivro;
      scanf("%d", &numLivro);
      limparBufferEntrada();

      int indice = numLivro - 1;

      if (indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel) {
        printf("Digite o nome do usuário que está pegando o livro: ");
        fgets(emprestimos[*totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
        emprestimos[*totalEmprestimos].nomeUsuario[strcspn(emprestimos[*totalEmprestimos].nomeUsuario, "\n")] = '\0';
        
        emprestimos[*totalEmprestimos].indiceLivro = indice;
        biblioteca[indice].disponivel = 0; // Modifica o array original

        (*totalEmprestimos)++; // Modifica o array original
        printf("\nEmpréstimo realizado com sucesso!\n");
      } else {
        printf("\nNúmero de livro inválido ou livro indisponível.\n");
      }
    }
  }
  printf("\nPressione Enter para continuar...");
  getchar();
};

/*
* @brief Lista todos os empréstimos realizados.
* @param biblioteca Array de livros (leitura).
* @param emprestimos Array de empréstimos (leitura).
* @param total de emprestimos (valor).
*/
void listarEmprestimos(const struct Livro *biblioteca, const struct Emprestimo *emprestimos, int totalEmprestimos) {
  printf("--- Lista de Empréstimos ---\n\n");
  if (totalEmprestimos == 0) {
    printf("Nenhum empréstimo realizado.\n");
  } else {
    for (int i = 0; i < totalEmprestimos; i++) {
      int indiceLivro = emprestimos[i].indiceLivro;
      printf("-----------------------------------\n");
      printf("Empréstimo %d\n", i + 1);
      printf("Livro: %s\n", biblioteca[indiceLivro].nome);
      printf("Usuário: %s\n", emprestimos[i].nomeUsuario);
    }
    printf("-----------------------------------\n");
  }
  printf("Pressione Enter para continuar...");
  getchar();
};

/*
 * @brief Realiza a devolução de um livro emprestado. 
 * @param biblioteca Array de livros (modificável, para alterar o status).
 * @param total de livros cadastrados.
 * @param emprestimos Array de empréstimos (modificável).
 * @param totalEmprestimos Ponteiro para o contador de empréstimos (para ser atualizado).
 */
void realizarDevolucao(struct Livro *biblioteca, int totalLivros, struct Emprestimo *emprestimos, int *totalEmprestimos) {
  printf("--- REALIZAR DEVOLUÇÃO ---\n\n");

  if (*totalEmprestimos == 0) {
    printf("Nenhum empréstimo registrado.\n");
  } else {
    printf("Empréstimos atuais:\n");
    for (int i = 0; i < *totalEmprestimos; i++) {
      int indiceLivro = emprestimos[i].indiceLivro;
      printf("%d - %s (Usuário: %s)\n", i + 1, biblioteca[indiceLivro].nome, emprestimos[i].nomeUsuario);
    }

    printf("\nDigite o número do empréstimo que deseja devolver: ");
    int numEmprestimo;
    scanf("%d", &numEmprestimo);
    limparBufferEntrada();

    int indiceEmprestimo = numEmprestimo - 1;

    if (indiceEmprestimo >= 0 && indiceEmprestimo < *totalEmprestimos) {
      int indiceLivro = emprestimos[indiceEmprestimo].indiceLivro;
      biblioteca[indiceLivro].disponivel = 1; // Marca o livro como disponível

      // Remove o empréstimo da lista, deslocando os demais para preencher o espaço
      for (int j = indiceEmprestimo; j < *totalEmprestimos - 1; j++) {
        emprestimos[j] = emprestimos[j + 1];
      }
      (*totalEmprestimos)--; // Decrementa o total de empréstimos

      printf("\nDevolução realizada com sucesso!\n");
    } else {
      printf("\nNúmero de empréstimo inválido.\n");
    } 
  }
  printf("Pressione Enter para continuar...\n");
  getchar();
};

/*
* @brief Libera a memória alocada para os arrays dinâmicos. 
*/
void liberarMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos) {
  free(biblioteca);
  free(emprestimos);
  printf("Memória liberada com sucesso!\n");
};