#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>   /* socket, bind, listen, accept, recv */
#include <netinet/in.h>   /* sockaddr_in, htons, htonl, INADDR_ANY */
#include <arpa/inet.h>    /* inet_ntoa */
#include <unistd.h>       /* close */

#define BACKLOG_MAX 5       /* número máximo de conexões pendentes na fila */
#define BUFFER_SIZE 128     /* tamanho máximo de cada mensagem */
#define Mensagem_para_sair "#sair"

int local_socket  = 0;  /* socket do servidor (escuta conexões) */
int remote_socket = 0;  /* socket do cliente (troca mensagens) */

int remote_length  = 0; /* tamanho da estrutura de endereço do cliente */
int message_length = 0; /* número de bytes recebidos */

unsigned short local_port = 0; /* porta em que o servidor vai escutar */

char message[BUFFER_SIZE]; /* buffer para armazenar a mensagem recebida */

struct sockaddr_in local_address;  /* endereço do servidor */
struct sockaddr_in remote_address; /* endereço do cliente (preenchido pelo accept) */

/* Exibe uma mensagem de erro e encerra o programa */
void msg_err_exit(char *msg)
{
  fprintf(stderr, "%s", msg);
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
  /* ------------------------------------------------------------------ */
  /* 1. Criação do socket                                                */
  /* AF_INET = endereçamento IPv4 | SOCK_STREAM = conexão TCP           */
  /* ------------------------------------------------------------------ */
  local_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (local_socket == -1)
    msg_err_exit("socket() failed\n");

  /* Lê a porta em que o servidor vai aguardar conexões */
  printf("Porta local: ");
  scanf("%hu", &local_port);
  fflush(stdin);

  /* ------------------------------------------------------------------ */
  /* 2. Preenchimento do endereço local                                  */
  /* INADDR_ANY = aceita conexões em qualquer interface de rede          */
  /* ------------------------------------------------------------------ */
  memset(&local_address, 0, sizeof(local_address));
  local_address.sin_family      = AF_INET;
  local_address.sin_port        = htons(local_port); /* converte para big-endian (ordem de rede) */
  local_address.sin_addr.s_addr = htonl(INADDR_ANY);

  /* ------------------------------------------------------------------ */
  /* 3. Bind: associa o socket ao endereço e porta locais               */
  /* ------------------------------------------------------------------ */
  if (bind(local_socket, (struct sockaddr *) &local_address, sizeof(local_address)) == -1)
  {
    close(local_socket);
    msg_err_exit("bind() failed\n");
  }

  /* ------------------------------------------------------------------ */
  /* 4. Listen: coloca o socket em modo de escuta                       */
  /* BACKLOG_MAX = quantas conexões podem ficar na fila de espera       */
  /* ------------------------------------------------------------------ */
  if (listen(local_socket, BACKLOG_MAX) == -1)
  {
    close(local_socket);
    msg_err_exit("listen() failed\n");
  }

  remote_length = sizeof(remote_address);
  printf("aguardando alguma conexao...\n");

  /* ------------------------------------------------------------------ */
  /* 5. Accept: bloqueia até um cliente conectar                        */
  /* Retorna um novo socket exclusivo para comunicação com esse cliente  */
  /* remote_address é preenchido automaticamente com os dados do cliente */
  /* ------------------------------------------------------------------ */
  remote_socket = accept(local_socket, (struct sockaddr *) &remote_address,
                          (socklen_t *) &remote_length);
  if (remote_socket == -1)
  {
    close(local_socket);
    msg_err_exit("accept() failed\n");
  }

  /* inet_ntoa converte o IP do cliente de binário para string legível */
  printf("conexao estabelecida com %s\n", inet_ntoa(remote_address.sin_addr));
  printf("aguardando mensagens...\n");

  /* ------------------------------------------------------------------ */
  /* 6. Loop de recepção de mensagens                                   */
  /* Continua até receber a mensagem de saída ("#sair")                 */
  /* ------------------------------------------------------------------ */
  do
  {
    memset(&message, 0, BUFFER_SIZE); /* limpa o buffer antes de cada recv */

    /* recv: lê os dados enviados pelo cliente e armazena em message  */
    /* BUFFER_SIZE - 1 garante espaço para o '\0' terminador         */
    message_length = recv(remote_socket, message, BUFFER_SIZE - 1, 0);
    if (message_length == -1)
        msg_err_exit("recv() failed\n");

    printf("%s: %s\n", inet_ntoa(remote_address.sin_addr), message);
  }
  while (strcmp(message, Mensagem_para_sair)); /* repete enquanto não for "#sair" */

  /* ------------------------------------------------------------------ */
  /* 7. Encerramento: fecha os dois sockets                             */
  /* ------------------------------------------------------------------ */
  printf("encerrando\n");
  close(local_socket);
  close(remote_socket);

  return 0;
}