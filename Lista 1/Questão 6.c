#include <stdio.h>

// 6) Escrever programa em C para solicitar ao usuário um número e exibir a
// tabuada (de multiplicação) desse número até 10.

int main() {
  int numero, acum;
  printf("Digite um numero: ");
  scanf("%d", &numero);
  printf("Tabuada de %d:\n", numero);
  for (acum = 0; acum <= 10;
       acum++) { // for (inicialização;condição;transformador)
    printf("%d x %d = %d\n", numero, acum, numero * acum);
  }
  return 0;
}