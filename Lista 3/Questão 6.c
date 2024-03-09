#include <stdio.h>

int main() {
  
float peso, altura, imc;
  
 printf("Digite o peso em kg: ");
 scanf("%f", &peso);

 printf("Digite a altura em metros: ");
 scanf("%f", &altura);

imc = peso / (altura * altura);

 printf("IMC: %.2f\n", imc);

if (imc < 18.5) {
  
 printf("Classificacao: Magreza\n");
  
} else if (imc >= 18.5 && imc <= 24.9) {
  
 printf("Classificacao: Saudavel\n");
  
} else if (imc >= 25.0 && imc <= 29.9) {
  
 printf("Classificacao: Sobrepeso\n");
  
} else if (imc >= 30.0 && imc <= 34.9) {
  
 printf("Classificacao: Obesidade Grau I\n");
  
} else if (imc >= 35.0 && imc <= 39.9) {
  
 printf("Classificacao: Obesidade Grau II (severa)\n");
  
} else {
  
 printf("Classificacao: Obesidade Grau III (morbida)\n");
  
}

return 0;
}
