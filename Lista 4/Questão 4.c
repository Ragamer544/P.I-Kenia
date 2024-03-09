#include <stdio.h>

/*Escrever programa , sem aplicar resto de divisão (%) e valor do quociente (/), para calcular a quantidade de meses contidos numa dada quantidade de dias. Considerar que todos os meses são compostos por 30 dias e desprezar o montante de dias que não formam pelo menos um mês completo (resto). */

int main() {
  
int dias, meses = 0;

 printf("Digite a quantidade de dias: "); 
 scanf("%d", &dias);

while (dias >= 30) {
  dias = dias - 30;
  meses = meses + 1;
}

 printf("A quantidade de meses correspondente é: %d", meses);

return 0;
}
