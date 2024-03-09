#include <stdio.h>
#include <math.h>

/*5. Escrever um programa em C para ler o raio de um círculo e exibir em
  tela a área desse (círculo) usando a fórmula: Área = π . raio2 .Usar um
  módulo/função para cálculo da área, outro módulo/função para cálculo do
  quadrado. E usar uma constante para definição de π. Recomenda-se o
  uso de função e/ou constante nativa, se houver.*/

const float π = 3.14;

int quadrado (int N){

  int quadrado = N*N;
   return quadrado;
}

float areaCirculo(float raio){

  float calculoArea = π * quadrado (raio);
  return calculoArea;
}

int main (){

  float raio;
  printf ("Digite o raio do círculo:");
  scanf  ("%f" , &raio);
  printf ("A area do circulo é : %.2f m²", areaCirculo (raio));
  return 0;
}