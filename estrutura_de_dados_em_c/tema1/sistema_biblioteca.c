// ===========================================================================
// PRÁTICA: SISTEMA DE BIBLIOTECA - PARTE 1
// 
//  OBJETIVO DESTA PARTE:
//  Implementar o cadastro e a listagem de livros usando um array estático.
//  Foco em structs, entrada e saída de dados e organização básica.
// 
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

// --- Função Para limpara o Buffer de Entrada ---
void limparBufferEntrada() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
};

// --- Função Principal (main) ---
int main() {
  // ALOCAÇÃO DINÂMICA DE MEMÓRIA
  // Utilizando ponteiros
  struct Livro *biblioteca;
  struct Emprestimo *emprestimos;

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
    // Exibe o menu de opções.
    printf("===================================\n");
    printf("    BIBLIOTECA - PARTE 1\n");
    printf("===================================\n");
    printf("1 - Cadastrar novo livro\n");
    printf("2 - Listar todos os livros\n");
    printf("3 - Realizar um empréstimo\n");
    printf("4 - Listar empréstimos\n");
    printf("0 - Sair\n");
    printf("-----------------------------------\n");
    printf("Escolha uma opção: ");

    // Lê a opção do usuário
    scanf("%d", &opcao);
    limparBufferEntrada(); // Limpa o '\n' deixado pelo scanf.

    // --- Processamento da Opção
    switch (opcao) {
      case 1: // CADASTRO DE LIVRO
        printf("--- Cadastro de Novo Livro ---\n\n");

        if (totalLivros < MAX_LIVROS) {
          printf("Digite o nome do livro: ");
          fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

          printf("Digite o autor: ");
          fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

          printf("Digite a editora: ");
          fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);
          
          biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
          biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
          biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

          printf("Digite a edição: ");
          scanf("%d", &biblioteca[totalLivros].edicao);
          limparBufferEntrada();

          /* importante: marcar livro como disponível ao cadastrar */
          biblioteca[totalLivros].disponivel = 1;

          totalLivros++;
          
          printf("\nLivro cadastrado com sucesso!\n");
        } else {
          printf("Biblioteca cheia! Não é possível cadastrar mais livros.\n");        
        }
        break;
      
      case 2: // LISTAGEM DE LIVROS
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
        break;

      case 3: // REALIZAR EMPRÉSTIMO DE LIVRO
        printf("--- REALIZAR EMPRÉSTIMO ---\n\n");

        if (totalLivros == 0) {
          printf("Nenhum livro cadastrado.\n");
        } else if (totalEmprestimos >= MAX_EMPRESTIMOS) {
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
            if (scanf("%d", &numLivro) == 1) {
              limparBufferEntrada();
              int indice = numLivro - 1;
              if (indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel) {
                printf("Digite o nome do usuário que está pegando o livro: ");
                fgets(emprestimos[totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                emprestimos[totalEmprestimos].nomeUsuario[strcspn(emprestimos[totalEmprestimos].nomeUsuario, "\n")] = '\0';

                emprestimos[totalEmprestimos].indiceLivro = indice;
                biblioteca[indice].disponivel = 0;
                totalEmprestimos++;
                printf("\nEmpréstimo realizado com sucesso!\n");
              } else {
                printf("\nNúmero de livro inválido ou livro indisponível.\n");
              }
            } else {
              limparBufferEntrada();
              printf("Entrada inválida.\n");
            }
          }
        }
        printf("\nPressione Enter para continuar...");
        getchar();
        break;
      
      case 4: // LISTAR EMPRÉSTIMOS
        printf("--- Lista d Empréstimos ---\n\n");
        if (totalEmprestimos == 0) {
          printf("Nenhum empréstimo realizado.\n");
        } else {
          for (int i = 0; i < totalEmprestimos; i++) {
            // Usa o índice armazenado no emprèstimo para buscar o nome do livro.
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

  // LIBERAÇÃO DA MEMÓRIA
  // Antes de terminar, é essencial liberar a memória que foi alocada dinamicamente.
  // Isso evita "memory leaks" (vazamentos de memória).
  free(biblioteca);
  free(emprestimos);

  printf("Memória liberada com sucesso!\n");

  return 0;
}