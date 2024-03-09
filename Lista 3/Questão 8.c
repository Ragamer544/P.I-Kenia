#include <stdio.h>
#include <ctype.h>

/* Escrever programa para exibir menu: U – unidade, D – dezena, C – centena, M – unidade de milhar e Z – dezena de milhar; ler um número de 0 a 99.999 e deste identificar a unidade, ou a dezena, ou a centena, ou a unidade de milhar, ou a centena de milhar; conforme a opção selecionada. Deve funcionar para o caso do usuário pressionar letras maiúsculas ou minúsculas.Deve ser aplicado switch-case. Deve haver mensagem de erro para o caso do usuário selecionar opção não existente. Deve ser modularizado.*/

int identificarUnidade(int numero) {
  
 printf("Unidade: %d\n", numero % 10);
return 0;
}

int identificarDezena(int numero) {

 printf("Dezena: %d\n", (numero / 10) % 10);
return 0;
}


int identificarCentena(int numero) {
  
 printf("Centena: %d\n", (numero / 100) % 10);
return 0;
}

int identificarUnidadeMilhar(int numero) {
  
 printf("Unidade de Milhar: %d\n", (numero / 1000) % 10);
return 0;
}

int identificarDezenaMilhar(int numero) {
  
 printf("Dezena de Milhar: %d\n", (numero / 10000) % 10);
  
return 0;
}

int main() {
  
  char opcao;
  int numero;

  printf("Digite um numero de 0 a 99.999: ");
  scanf("%d", &numero);

  printf("Qual operacao desejar ler? \n");
  printf("U - unidade\n");
  printf("D - dezena \n");
  printf("C - centema \n");
  printf("M - unidade de milhar \n");
  printf("Z - dezena de milhar \n");
  scanf(" %c", &opcao); 

  // Converte a opcao para maiuscula
  opcao = toupper(opcao);

switch (opcao) {
  
  case 'U': identificarUnidade(numero); break;
  case 'D': identificarDezena(numero); break;
  case 'C': identificarCentena(numero); break;
  case 'M': identificarUnidadeMilhar(numero); break;
  case 'Z': identificarDezenaMilhar(numero); break;
  default:
  printf("Opção inválida\n"); break;
}
return 0;
}