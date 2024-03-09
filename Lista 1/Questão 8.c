#include <stdio.h>

/* 8) Escrever um programa em C para calcular a área de um retângulo. O usuário
deve fornecer o comprimento e a largura desse. */

int main() {
  float comprimento, largura;
  printf ("DIgite a largura do retangulo:");
  scanf  ("%f", &largura);
  printf("Digite o comprimento do retangulo: ");
  scanf("%f", &comprimento);
  if (comprimento < 0 || largura < 0) {
    printf("Dados invalidos. O comprimento e/ou a largura nao podem ser "
           "negativo.\n");
    return 0;
  }
  float area = (comprimento * largura);
  printf("A area do retangulo é %0.f metros quadrados \n", area);
  return 0;
}
