#include <stdio.h>
#include <stdlib.h>

int main() {
  int count = 0, num = 2, i;
  int N = 100; //Deseja-se encontrar o 100º número primo
  int isPrime;

  while (count < N) {
    isPrime = 1; // Assume que o número é primo
    for (i = 2; i * i <= num; i++) {
      if (num % i == 0) {
        isPrime = 0; // O número não é primo
        break;
      }
    }

    if (isPrime) {
      count++;
      if (count == N) {
        printf("%d numero primo é %d.\n", N, num);
      }
    }

    num++;
  }

  return 0;
}