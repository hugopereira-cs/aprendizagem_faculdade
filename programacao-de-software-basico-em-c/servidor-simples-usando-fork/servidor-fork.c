#include <stdio.h> // Para entrada e saída padrão
#include <stdlib.h> // Para funções de alocação de memória, controle de processos, etc.
#include <string.h> // Para manipulação de strings
#include <unistd.h> // Para funções de sistema, como fork(), close(), read(), write()
#include <sys/types.h> // Para tipos de dados usados em chamadas de sistema
#include <sys/socket.h> // Para funções de socket
#include <netinet/in.h> // Para estruturas de endereço de internet

// Função para lidar com mensagens de erro
void error(const char *msg) {
    perror(msg); // Exibe a mensagem de erro associada ao último comando executado
    exit(1); // Encerra o programa com código de erro
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    pid_t pid;

    // Verifica se o número da porta foi fornecido como argumento
    if (argc < 2) {
        fprintf(stderr, "ERRO, porta não fornecida\n");
        exit(1); // Encerra o programa se a porta não for fornecida
    }

    // Criação do socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERRO ao abrir o socket");
    }

    // Zera a estrutura do endereço do servidor (boa prática)
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]); // Converte o número da porta de string para inteiro

    serv_addr.sin_family = AF_INET; // Define a família de endereços
    serv_addr.sin_addr.s_addr = INADDR_ANY; // Aceita conexões de qualquer endereço IP
    serv_addr.sin_port = htons(portno); // Define o número da porta

    // Associa o socket a um endereço (IP e porta)
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERRO ao associar");
    }

    // Escuta por conexões, com uma fila de espera de até 5 conexões
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // Loop infinito para aceitar conexões
    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            error("ERRO na aceitação");
        }
        // Criação de um novo processo para cada conexão
        pid = fork();
        if (pid < 0) {
            error("ERRO na criação do fork");
        }
        // Processo-filho
        if (pid == 0) {
            close(sockfd); // Fecha o socket original no processo-filho
            char buffer[256];
            bzero(buffer, 256); // Zera o buffer
            read(newsockfd, buffer, 255); // Lê dados do socket
            printf("Aqui está a mensagem: %s\n", buffer); // Exibe a mensagem recebida
            write(newsockfd, "Recebi sua mensagem", 18); // Envia resposta para o cliente
            close(newsockfd); // Fecha o novo socket
            exit(0); // Encerra o processo-filho
        } else {
            close(newsockfd); // Processo-pai fecha o novo socket
        }
    }
    close(sockfd); // Fecha o socket original
    return 0;
} 