#include <stdio.h>
#include <math.h>

/* 1- Há pessoas que precisam fazer tratamento de saúde contínuo (em
comprimidos), a exemplo de reposição hormonal. Sabendo que uma
pessoa deve fazer uso de X comprimidos ao mês e que em cada caixa
desse há N unidades (comprimidos); escrever um programa em C
onde se lê X e N e é exibido o número de caixas a serem adquiridas. */

float funcao (float numerador , float denominador ){

  float funcao1 =  ceil (numerador/denominador);

  return funcao1;
}


int main () {
 float comprimidos, caixas ;
  printf("Quantos comprimidos você precisa tomar por mês? : ");
  scanf("%f",&comprimidos);
  printf("Quantos comprimidos tem em cada caixa? : ");
  scanf ("%f",&caixas);
  printf("Você precisa comprar %f caixas",funcao(comprimidos,caixas));
}