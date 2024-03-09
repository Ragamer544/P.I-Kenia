#include <stdio.h>
#include <math.h>

/* 6.Escrever um programa em C para ler peso em kg e altura em m. Calcular
e exibir o IMC da pessoa considerando IMC = peso / altura2. Para cálculo
de IMC usar função, e nessa aplicar função de cálculo da potência (seja
definida pelo programação ou nativa).*/

float quadrado (float N){

 float calculaQuadrado = N * N;

  return calculaQuadrado;

}

float IMC (float peso , float altura){

 float calculaIMC = peso/(quadrado(altura));
  
  return calculaIMC;
}

int main () {

float peso , altura ;

  printf("Qual o seu peso em Kg? : ");
   scanf ("%f" , &peso);
  printf ("Qual sua altura em m? : ");
   scanf ( "%f" , &altura);
  printf ("Seu IMC é : %.2f" , IMC(peso,altura));
  return 0;
}