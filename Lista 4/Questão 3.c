#include <stdio.h>


/* Ler notas de alunos e identificar se cada foi aprovado. Considerar como sistema de avaliação: em princípio, 3 notas; são aprovados os alunos com média 7; para os alunos com média acima de 3, é possibilitado fazer 4a avaliação, então a média passa a ser 5 para obtenção da aprovação. Após a identificação de que um aluno foi aprovado, ou não; deve ser questionado se o usuário (do programa) deseja verificar a situação de outro aluno.*/

int main() {
  char continuar;

do {

 float nota1, nota2, nota3, media;
 printf("Digite a primeira nota: ");
 scanf("%f", &nota1);

 printf("Digite a segunda nota: ");
 scanf("%f", &nota2);

 printf("Digite a terceira nota: ");
 scanf("%f", &nota3);

media = (nota1 + nota2 + nota3) / 3;

if (media >= 7) {
  printf("Aluno aprovado!\n");
  
} else if (media > 3) {
  
  char realizarQuartaAvaliacao;
  printf("Aluno pode fazer a quarta avaliacao. Deseja realiza-la? (s/n): ");
  scanf(" %c", &realizarQuartaAvaliacao);
            
if (realizarQuartaAvaliacao == 's' || realizarQuartaAvaliacao == 'S') {
  
  float nota4;
  printf("Digite a quarta nota: ");
  scanf("%f", &nota4);
              
media = (nota1 + nota2 + nota3 + nota4) / 4;

if (media >= 5) {
    
  printf("Aluno aprovado!\n");
  
} else {
  
  printf("Aluno reprovado. Media final: %.2f\n", media);
  
} } }
  printf("Deseja verificar a situacao de outro aluno? (s/n): ");
  scanf(" %c", &continuar);

} while (continuar == 's' || continuar == 'S');

return 0;
}
