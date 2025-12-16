#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

// --- DECLARAÇÃO DAS FUNÇÕES (PROTÓTIPOS) ---

// 1. Busca Sequencial
int buscaSequencialIterativa(const char* lista[], int tamanho, const char* item);
int buscaSequencialRecursiva(const char* lista[], int tamanho, const char* item);
int buscaSequencialRecursiva_aux(const char* lista[], int tamanho, const char* item, int indice);

// 2. Busca Binária
int buscaBinariaIterativa(const char* lista[], int tamanho, const char* item);
int buscaBinariaRecursiva(const char* lista[], int tamanho, const char* item);
int buscaBinariaRecursiva_aux(const char* lista[], const char* item, int inicio, int fim);

// Função auxiliar para imprimir os resultados de forma organizada
void imprimirResultado(const char* nomeDaBusca, const char* item, int resultado);


// --- FUNÇÃO PRINCIPAL ---
int main() {
  setlocale(LC_ALL, "Portuguese");
  //  IMPORTANTE: Para a busca binária funcionar, a lista precisa estar ordenada, neste caso alfabeticamente.
  const char* listaDeCompras[] = {
    "arroz",
    "batata",
    "cebola",
    "detergente",
    "feijão",
    "leite",
    "macarrão",
    "óleo",
    "sal",
    "tomate",

  };

  // Calcula o número de itens na lista.
  // sizeof(listaDeCompras) -> tamanho total do array em bytes.
  // sizeof(listaDeCompras[0]) -> tamanho de um elemento (um ponteiro char*) em bytes.
  // A divisão nos dá o número de elementos.
  int tamanhoDaLista = sizeof(listaDeCompras) / sizeof(listaDeCompras[0]);

  // Itens que vamos procurar para demonstrar os algoritmos.
  const char* itemExistente = "leite";
  const char* itemInexistente = "queijo";

  printf("--- DEMONSTRAÇÃO DE ALGORITMOS DE BUSCA EM LISTA DE TEXTO ---\n");
  printf("Lista utilizada: [arroz, batata, cebola, detergente, feijão, leite, macarrâo, óleo, sal, tomate]\n");
  printf("----------------------------------------------------------------\n\n");
  
  // --- Testando a Busca Squencial ---
  printf("--- 1. Busca Sequencial ---\n");
  // a) Versão Iterativa
  int res1 = buscaSequencialIterativa(listaDeCompras, tamanhoDaLista, itemExistente);
  imprimirResultado("Sequencial Iterativa", itemExistente, res1);
  
  int res2 = buscaSequencialIterativa(listaDeCompras,tamanhoDaLista, itemInexistente);
  imprimirResultado("Sequencial Iterativa", itemInexistente, res2);
  
  // b) Versão Recursiva
  int res3 = buscaSequencialRecursiva(listaDeCompras, tamanhoDaLista, itemExistente);
  imprimirResultado("Sequencial Recursiva", itemExistente, res3);
  
  int res4 = buscaSequencialRecursiva(listaDeCompras, tamanhoDaLista, itemInexistente);
  imprimirResultado("Sequencial Recursiva", itemInexistente, res4);
  printf("----------------------------------------------------------------\n\n");
  
  // --- Testando a Busca Binária ---
  printf("--- 2. Busca Binária (requer lista ordenada) ---\n");
  // a) Versão Iterativa
  int res5 = buscaBinariaIterativa(listaDeCompras, tamanhoDaLista, itemExistente);
  imprimirResultado("Binária Iterativa", itemExistente, res5);
  
  int res6 = buscaBinariaIterativa(listaDeCompras, tamanhoDaLista, itemInexistente);
  imprimirResultado("Binária Iterativa", itemInexistente, res6);
  
  // b) Versão Recursiva
  int res7 = buscaBinariaRecursiva(listaDeCompras, tamanhoDaLista, itemExistente);
  imprimirResultado("Binária Recursiva", itemExistente, res7);
  
  int res8 = buscaBinariaRecursiva(listaDeCompras, tamanhoDaLista, itemInexistente);
  imprimirResultado("Binária Recursiva", itemInexistente, res8);
  printf("----------------------------------------------------------------\n\n");

  return 0; // Indica que o programa terminou com sucesso.
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES ---

// 1. BUSCA SEQUENCIAL

/**
 * @brief Busca sequencial usando um laço (iteração).
 * @param lista Oarray de strings onde a busca será feita.
 * @param item A string que está sendo procurada.
 * @return O índice do item se encontrado, ou -1 caso contrário.
 */
int buscaSequencialIterativa(const char* lista[], int tamanho, const char* item) {
  for (int i = 0; i < tamanho; i++) {
    // strcpm(str1, str2) compara duas strings.
    // Retorna 0 se elas forem idênticas.
    if (strcmp(lista[i], item) == 0) {
      // Se forem iguais, encontramos o ítem!
      return i;
    }
  }
  // Se o laço terminar e não tivermos retornado nada,
  // significa que o ítem não está na lista.
  return -1;
}

/**
 * @brief Função "invólucro" (wrapper) para a busca sequencial recursiva.
 * Ela esconde a complexidade do parâmetro 'índice' do usuário.
 */
int buscaSequencialRecursiva(const char* lista[], int tamanho, const char* item) {
  // A lógica recursiva real está na função auxiliar.
  // Começamos a busca a partir do índice 0.
  return buscaSequencialRecursiva_aux(lista, tamanho, item, 0);
}

/**
 * @brief Função auxiliar que implementa a lógica recursiva da busca sequencial.
 * @paramindice O índice do elemento atual a ser verificado.
 * @return Oíndice do item se encontrado, ou -1 caso contrário.
 */
int buscaSequencialRecursiva_aux(const char* lista[], int tamanho, const char* item, int indice) {
  // CASO BASE 1: FALHA (Fim da lista)
  // Se o índice atual for igual ou maior que o tamanho da lista,
  // significa que já percorremos todos os elementos sem sucesso.
  if (indice >= tamanho) {
    return -1;
  }

  // CASO BASE 2: SUCESSO
  // Compara o item na posição 'indice' atual com o item procurado.
  if (strcmp(lista[indice], item) == 0) {
    return indice; // Índice encontrado! Retorna o índice.
  }
  // PASSO RECURSIVO
  // Se não for nenhum dos casos base, o item ainda pode estarr no resto da lista.
  // Chamamos a função novamente, ams agora para o próximo índice (índice +1).
  // O retorno desta chamada será propagado para a chamada anterior.
  return buscaSequencialRecursiva_aux(lista, tamanho, item, indice + 1);
}

// 2. BUSCA BINÁRIA

/**
 * @brief Busca binária usando um laço (iteração).
 * @return O índice do item se encontrado, ou -1 caso contrário.
 */
int buscaBinariaIterativa(const char* lista[], int tamanho, const char* item) {
  int inicio = 0;
  int fim = tamanho;
  int meio;

  // O laço continua enquanto a sub-lista for válida (início não ultrapassou o fim).
  while (inicio <= fim) {
    // Calculla o índice do meio.
    // Usar início +(fim - inicio) / 2 evita overflow para listas muito grandes.
    meio = inicio + (fim - inicio) / 2;

    // Compara a string do meio com o item procurado.
    int comparacao = strcmp(lista[meio], item);

    if (comparacao == 0) { // Encontrou!
      return meio;
    }
    else if (comparacao > 0) {
      // O item do meio vem DEPOIS do item procurado (ex: "leite" > "feijão").
      // Portanto, o item só pode estar na metade esquerda.
      // Descartamos a metade direita, ajustando o 'fim'.
      fim = meio -1;
    }
    else { // comparacao < 0
      // O item do meio vem ANTES do item procurado (ex: "leite" < "sal").
      // Portanto, o item só pode estar na metade direita.
      // Descartamos a metade esquerda, ajustando o 'inicio'.
      inicio = meio + 1;
    }
  }

  // Se o laço 'while' terminar, significa que 'inicio' ultrapassou o 'fim',
  // o espaço de busca se esgotou e o item não foi encontrado.
  return -1;
}

/**
 * @brief Função "invólucro" (wrapper) para a busca binária recursiva.
 */
int buscaBinariaRecursiva(const char* lista[], int tamanho, const char* item) {
  // Inicia a busca recursiva em toda a lista, do índice 0 até 'tamanho - 1'.
  return buscaBinariaRecursiva_aux(lista, item, 0, tamanho - 1);
}

/**
 * @brief Função auxiliar que implementa a lógica recursiva da busca binária.
 * @param inicio O índice inicial da sub-lista atual.
 * @param fim O índice final da sub-lista atual.
 * @return O índice do item se encontrado, ou -1 caso contrário.
 */
int buscaBinariaRecursiva_aux(const char* lista[], const char* item, int inicio, int fim) {
  // CASO BASE 1: FALHA (Espaço de busca inválido)
  // Se o 'inicio' ultrapassar o 'fim', a sub-lista é vazia, o item não está aqui.
  if (inicio > fim) {
    return -1;
  }

  // PASSO RECURSIVO E CASO BASE DE SUCESSO
  int meio = inicio + (fim - inicio) / 2;
  int comparacao = strcmp(lista[meio], item);

  if (comparacao == 0) {
    // CASO BASE 2: SUCESSO
    return meio; // Encontramos o item!
  }
  else if (comparacao > 0) {
    // O item está na metade esquerda.
    // Chamamos a função novamente, mas com um novo 'fim'.
  return buscaBinariaRecursiva_aux(lista, item, inicio, meio - 1);  
  }
  else { // comparacao < 0
    // O itemestá na metade direita.
    // Chamamos a função novamente, mas com um novo 'inicio'.
    return buscaBinariaRecursiva_aux(lista, item, meio + 1, fim);
  }
}

// FUNÇÃO AUXILIAR DE IMPRESSÃO

/**
 * @brief Formata e imprime o resultado de uma busca.
 * @param nomeDaBusca O nome do algoritmo utilizado.
 * @param item O item que foi procurado.
 * @param resultado O resultado da busca (índice ou -1).
 */

void imprimirResultado(const char* nomeDaBusca, const char* item, int resultado) {
  printf("[%s] Buscando por \"%s\"... \n", nomeDaBusca, item);
  if (resultado != -1) {
    printf("    -> Resultado: Item encontrado no índice %d.\n", resultado);
  } else {
    printf("    -> Resultado: Item não encontrado na lista.\n\n");
  }
}