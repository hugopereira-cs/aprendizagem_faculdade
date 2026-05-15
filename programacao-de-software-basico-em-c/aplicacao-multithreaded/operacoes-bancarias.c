/**
 * Explicação do fluxo
 *  1. Inicialização: O saldo da conta é definido como 1000 e o mutex é inicializado.
 *  2. Criação de Threads: 10 threads são criados, cada um com uma quantia específica a ser sacada.
 *  3. Execução dos Threads: Cada thread tenta realizar um saque:
 *    - Bloqueia o mutex para verificar e atualizar o saldo.
 *    - Realiza o saque se houver saldo suficiente, ou seja imprime uma mensagem de erro.
 *    - Desbloqueia o mutex.
 *  4. Finalização: O programa espera que todos os trheads terminem, imprime o saldo final da conta e destrói o mutex.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10
#define INITIAL_BALANCE 10000

/**
 * 1. Mutex:
 *    O mutex (pthread_mutex_t mutex) é utilizado para garantir que apenas um thread acesse e modifique o saldo da conta por vez, evitando condiçoes de corrida.
 */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int account_balance = INITIAL_BALANCE; // Saldo inicial da conta

// Função que será executada por cada thread para realizar um saque
void *withdraw(void *arg) {
    int amount = *(int *)arg; // Obtém a quantia a ser sacada a partir do argumento

    /**
     * 3. Sincronização:
     *  A sincronização é garantida pelo uso do mutex ao redor da verificação e atualização do saldo da conta dentro da função withdraw.
     */
    // Bloqueia o mutex para garantir acesso exclusivo à conta
    pthread_mutex_lock(&mutex);

    /**
     * 4. Consistência dos Dados: 
     *  O uso adequado do mutex assegura que o saldo da conta seja atualizado de maneira consistente,
     *  mesmo com múltiplos threads tentando realizar saques simultaneamente.
     *  A função withdraw verifica se há saldo suficiente antes de realizar o saque e atualiza o saldo de forma segura.
     */
    if (account_balance >= amount) {
        // Se o saldo for suficiente, realiza o saque
        printf("Thread %ld: Sacar %d\n", pthread_self(), amount);
        account_balance -= amount; // Atualiza o saldo da conta
        printf("Thread %ld: Novo saldo %d\n", pthread_self(), account_balance);
    } else {
        // Se o saldo for insuficiente, exibe uma mensagem de erro
        printf("Thread %ld: Fundos insuficientes para saque de %d\n", pthread_self(), amount);
    }

    // Desbloqueia o mutex
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
  /**
   * 2. Threads:
   *  As threads são criadas, cada uma representando um cliente que tenta sacar uma quantia específica da conta.
   */

    pthread_t threads[NUM_THREADS]; // Array para armazenar os identificadores dos threads
    int amounts[NUM_THREADS] = {1000, 2000, 1500, 3000, 2500, 1200, 1800, 2300, 1600, 1400}; // Quantias a serem sacadas

    // Cria os threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, withdraw, (void *)&amounts[i]);
    }

    // Espera que todos os threads completem suas operações
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Exibe o saldo final da conta
    printf("Saldo final da conta: %d\n", account_balance);
    pthread_mutex_destroy(&mutex); // Destroi o mutex
    return 0;
}
