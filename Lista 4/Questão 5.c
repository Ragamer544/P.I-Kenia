#include <stdio.h>

void analisar_pH(float pH) {
  
if (pH < 7) {
  
 printf("\nACIDA");
  
} else if (pH > 7) {
  
 printf("\nBASICA");
  
} else {
  
 printf("\nNEUTRA");
  
} }

int main() {
  
float entrada;
char continuar;
  
 while (1) {
   
   printf ("Voce deseja encerrar o programa? ( s - sim ou n - nao");
   scanf (" %c", &continuar);
   }
   scanf("%f", &entrada);
   
    analisar_pH(entrada);

   if (continuar == 's' || continuar == 'S') {  break ;

  

}  
  return 0;
  
} 

