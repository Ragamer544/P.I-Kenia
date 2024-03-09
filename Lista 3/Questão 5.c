#include <stdio.h>

/* Faça um programa para verificar se determinado número inteiro lido N é divisível por A ou B, mas não simultaneamente pelos dois valores dados. São A e B, bem como N, dados pelo usuário. Atendendo a condição estabelecida, emitir mensagem “ATENDE CONDIÇÃO”; caso contrário, exibir: “NÃO ATENDE CONDIÇÃO”. */

int main() {
  
int numeroN, numeroA, numeroB;

 printf("Digite um numero inteiro N: ");
 scanf("%d", &numeroN);
 
 printf("Digite um numero inteiro A: ");
 scanf("%d", &numeroA);

 printf("Digite um numero inteiro B: ");
 scanf("%d", &numeroB);
  
if ((numeroN % numeroA == 0 && numeroN % numeroB != 0) || (numeroN % numeroB == 0 && numeroN % numeroA != 0)) {
  
 printf("ATENDE CONDICAO\n");

} else {
        
 printf("NAO ATENDE CONDICAO\n");
}

return 0;
}
