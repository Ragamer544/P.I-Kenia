#include <stdio.h>

int main() {
  int acertos_portugues, acertos_matematica,candidatos_aprovados = 0;
  float nota_redacao;
  char continuar;

do {
  
 printf("Informe a quantidade de acertos em português : ");
 scanf("%d", &acertos_portugues);

if (acertos_portugues < 0) 
  
  break; 
  
 printf("Informe a quantidade de acertos em matemática: ");
 scanf("%d", &acertos_matematica);

 printf("Informe a nota na redação: ");
 scanf("%f", &nota_redacao);

  if (acertos_portugues >= 0.8 * 50 && acertos_matematica >= 0.6 * 35 && nota_redacao >= 7) {
  candidatos_aprovados++;
    
 printf("Candidato APROVADO!\n");
    
} else {
  printf("Candidato REPROVADO.\n");
}
 printf("Deseja continuar (s - Sim, n - Não): ");
 scanf(" %c", &continuar);

} while (continuar == 'S' || continuar == 's');

 printf("Número total de candidatos aprovados: %d\n", candidatos_aprovados);

return 0;  
}