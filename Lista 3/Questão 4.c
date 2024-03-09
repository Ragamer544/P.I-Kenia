#include <stdio.h>

/* Faça um programa para ler um número inteiro, positivo de três dígitos, e gerar outro
número formado pelos dígitos invertidos do número lido. (Ex: Numero Lido = 123; Numero Gerado = 321) Em seguida informar: NÚMERO GERADO MAIOR QUE NÚMERO LIDO ou NÚMERO LIDO MAIOR QUE NÚMERO GERADO, ou ainda, NÚMERO GERADO IGUAL AO NÚMERO LIDO.*/

int main() {
  
int numeroLido, numeroOriginal, numeroGerado = 0, digito;

 printf("Digite um numero inteiro positivo de tres digitos: ");
 scanf("%d", &numeroLido);

numeroOriginal = numeroLido;

 digito = numeroLido % 10;
 numeroGerado = digito * 100;
 numeroLido /= 10;

 digito = numeroLido % 10;
 numeroGerado = numeroGerado + digito * 10;
 numeroLido /= 10;

 digito = numeroLido % 10;
 numeroGerado = numeroGerado + digito;

 printf("Numero Gerado: %d\n", numeroGerado);

if (numeroGerado > numeroOriginal) {
  
      printf("Numero Gerado Maior Que Numero Lido\n");
  
} else if (numeroOriginal > numeroGerado) {
  
 printf("Numero Lido Maior Que Numero Gerado\n");
  
} else {
  
 printf("Numero Gerado Igual Ao Numero Lido\n");
  
}

return 0;
}
