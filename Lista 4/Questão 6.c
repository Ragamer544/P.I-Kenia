#include <stdio.h>

int main() {
  int acertos_portugues, acertos_matematica,candidatos_aprovados = 0;
  float nota_redacao;

while (1) {
  
 printf("Informe a quantidade de acertos em português (ou um valor negativo para encerrar):");
 scanf("%d", &acertos_portugues);
      
if (acertos_portugues < 0) { break;}

 printf("Informe a quantidade de acertos em matemática: ");
 scanf("%d", &acertos_matematica);

 printf("Informe a nota na redação: ");
 scanf("%f", &nota_redacao);

if (acertos_portugues >= 0.8 * 50 && acertos_matematica >= 0.6 * 35 && nota_redacao >= 7) {
candidatos_aprovados++;
}
}
  
 printf("Número de candidatos aprovados: %d\n", candidatos_aprovados);

return 0;
}
