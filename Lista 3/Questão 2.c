#include <stdio.h>

/* Para conter o crescimento da quantidade de gatos abandonados na UFS, e seus consequentes prejuízos, surgiu o projeto "CastraçãoSolidária", a partir do qual 4 veterinários experientes e 1 recém formado decidiram efetuar capturas e castrações todos os dias úteis, sendo os animais capturados divididos igualitariamente entre os veterinários experientes, e havendo sobras (não sendo possível uma divisão exata), o restante fica sob a responsabilidade do 5o veterinário – recém formado. Por exemplo, se capturados 22 gatos, cada veterinário experiente fica com 5 castrações, e o recém formado fica com 2. Se capturados 19, os experientes ficam  com 4 e o formado recentemente fica com 3. Escrever programa em C para ler número de gatos capturados e exibir a distribuição das castrações entre os veterinários. Vale esclarecer que se capturados 4 ou menos gatos, as castrações ficam sob a responsabilidade de todos os veterinários, em conjunto. */

int main() {

int numGatosCapturados, castracoesExperientes, castracoesRecemFormado, conjuntoDeVeterinarios;
  
  printf("Digite o número de gatos capturados: ");
  scanf("%d", &numGatosCapturados);
  
if (numGatosCapturados <= 4) {
  
  conjuntoDeVeterinarios = numGatosCapturados ;
  
  printf ("As castrações serão feitas em conjuto por todos os veterinarios");

} else {
    
   castracoesExperientes = numGatosCapturados / 4;
   castracoesRecemFormado = numGatosCapturados % 4;

  printf("Distribuição das castrações:\n");
  printf("Veterinários experientes: %d castrações cada\n", castracoesExperientes);
  printf("Veterinário recém formado: %d castrações\n", castracoesRecemFormado);

}
return 0;
}