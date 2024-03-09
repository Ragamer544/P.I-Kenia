#include <stdio.h>

/* Escrever programa para ler as três notas de um aluno, calcular a média deste (média ponderada: primeira nota com peso 1, segunda nota com peso 2 e terceira nota com peso 3) e determinar a situação do aluno: APROVADO – se média igual ou superior a 7; EM RECUPERAÇÃO – se não aprovado e com média igual ou superior a 5; REPROVADO – quando média inferior a 5. */

int main() {
  
float nota1, nota2, nota3, nota4 , media;

 printf("Digite a primeira nota: ");
 scanf("%f", &nota1);

 printf("Digite a segunda nota: ");
 scanf("%f", &nota2);

 printf("Digite a terceira nota: ");
 scanf("%f", &nota3);

  printf("Digite a terceira nota: ");
  scanf("%f", &nota4);

media = (nota1 * 1 + nota2 * 2 + nota3 * 3 + nota4 * 4) / 10;
  
if (media >= 7) {
  
 printf("APROVADO\n");
  
} else if (media >= 5) {
  
 printf("EM RECUPERACAO\n");
  
} else {
  
 printf("REPROVADO\n");
}

return 0;
}


