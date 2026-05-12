#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>   /* socket, connect, send */
#include <netinet/in.h>   /* sockaddr_in, htons */
#include <arpa/inet.h>    /* inet_addr */
#include <unistd.h>       /* close */

#define BUFFER_SIZE 128        /* tamanho máximo de cada mensagem */
#define Mensagem_para_sair "#sair"

int remote_socket  = 0;  /* socket usado para se conectar ao servidor */
int message_length = 0;  /* número de bytes a enviar */

unsigned short remote_port = 0; /* porta do servidor */

char remote_ip[32];        /* IP do servidor em formato string ("192.168.0.1") */
char message[BUFFER_SIZE]; /* buffer com a mensagem a enviar */

struct sockaddr_in remote_address; /* endereço do servidor */

/* Exibe uma mensagem de erro e encerra o programa */
void msg_err_exit(char *msg)
{
    fprintf(stderr, "%s", msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
  /* Lê o IP e a porta do servidor que o cliente vai contactar */
  printf("IP do servidor: ");
  scanf("%31s", remote_ip); /* %31s limita a leitura ao tamanho do array */
  fflush(stdin);

  printf("Porta do servidor: ");
  scanf("%hu", &remote_port);
  fflush(stdin);

  /* ------------------------------------------------------------------ */
  /* 1. Criação do socket                                                */
  /* AF_INET = endereçamento IPv4 | SOCK_STREAM = conexão TCP           */
  /* ------------------------------------------------------------------ */
  remote_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (remote_socket == -1)
    msg_err_exit("socket() failed\n");

  /* ------------------------------------------------------------------ */
  /* 2. Preenchimento do endereço do servidor                           */
  /* inet_addr converte o IP em string para o formato binário de rede   */
  /* ------------------------------------------------------------------ */
  memset(&remote_address, 0, sizeof(remote_address));
  remote_address.sin_family      = AF_INET;
  remote_address.sin_addr.s_addr = inet_addr(remote_ip);
  remote_address.sin_port        = htons(remote_port); /* converte para big-endian */

  /* ------------------------------------------------------------------ */
  /* 3. Connect: estabelece a conexão TCP com o servidor                */
  /* Bloqueia até a conexão ser aceita ou falhar                        */
  /* ------------------------------------------------------------------ */
  printf("conectando ao servidor %s...\n", remote_ip);
  if (connect(remote_socket, (struct sockaddr *) &remote_address,
    sizeof(remote_address)) == -1)
  {
    close(remote_socket);
    msg_err_exit("connect() failed\n");
  }

  printf("digite as mensagens\n");

  /* ------------------------------------------------------------------ */
  /* 4. Loop de envio de mensagens                                      */
  /* Continua até o usuário digitar "#sair"                             */
  /* ------------------------------------------------------------------ */
  do
  {
    memset(&message, 0, BUFFER_SIZE); /* limpa o buffer antes de cada leitura */

    printf("Mensagem para o servidor: ");

    /* fgets lê a linha inteira com segurança, respeitando BUFFER_SIZE */
    fgets(message, BUFFER_SIZE, stdin);

    /* fgets inclui o '\n' no buffer — removemos para o strcmp funcionar */
    message[strcspn(message, "\n")] = '\0';

    message_length = strlen(message);

    /* send: envia message_length bytes do buffer para o servidor */
    if (send(remote_socket, message, message_length, 0) == -1)
    {
      close(remote_socket);
      msg_err_exit("send() failed\n");
    }
  }
  while (strcmp(message, Mensagem_para_sair)); /* repete enquanto não for "#sair" */

  /* ------------------------------------------------------------------ */
  /* 5. Encerramento: fecha o socket                                    */
  /* ------------------------------------------------------------------ */
  printf("saindo\n");
  close(remote_socket);

  return 0;
}