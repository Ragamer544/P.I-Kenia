#include <stdio.h>

// 4) Escrever programa em C para solicitar um valor monetário em reais, o
// câmbio real - dólar, e exiba o valor em dólar.

int main() {
  float dolar, real, conversor;
  printf("Me informe o valor atual do Dólar : \n");
  scanf("%f", &dolar);
  printf("Me informe o valor em reais a ser cambiado: \n");
  scanf("%f", &real);
  printf(" O valor em Dólar é : %.2f", conversor = (real / dolar));
  return 0;
}