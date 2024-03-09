#include <stdio.h>

// 7) Criar um programa em C que converta a temperatura de Celsius para
// Fahrenheit. Solicite ao usuário a temperatura em Celsius e exiba o resultado
// em Fahrenheit. Pesquise e escreva, como comentário, a regra de conversão
// usada.

int main() {
  float temperaturaEmCelsius;
  printf("Me informe a temperatura em Celsius: \n");
  scanf("%f", &temperaturaEmCelsius);

  float temperaturaEmFahrenheit =
      ((temperaturaEmCelsius * 1.8) +
       32); /* <- a conversão ocorre pegando o valor dado pelo usuário e o
               multiplicando por 1.8, logo apos isso o valor é somado com 32, e
               o resultado é armazenado na variavel "temperaturaEmFahrenheit" e
               dps é colocado no terminal com a mensagem "A temperatura em
               Fahrenheit é:"*/

  printf("A temperatura em graus Fahrenheit é: %f", temperaturaEmFahrenheit);
  return 0;
}