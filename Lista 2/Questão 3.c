#include <stdio.h>
#include <math.h>

/* 3-Escrever programa em C para ler um número N e retornar N^3 (N ao cubo), aplicando função (que calcula cubo).*/

int cubo (int n){

  int calculaCubo = n*n*n;

  return calculaCubo;
}


int main (){
  int n;
   printf ("Digite um valor para N:" );
   scanf("%d" , &n);
   printf ("O cubo de N é: %d", cubo (n));
   return 0;
}