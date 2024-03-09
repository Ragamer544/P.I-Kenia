#include <stdio.h>
#include <math.h>

/* Escrever programa para: (a) exibir menu: 1 – area, 2 – perímetro e 3 – diagonal; (d) ler medida de lado de um quadrado; (c) exibir a informação solicitada pelo usuário conforme opção de menu selecionada. Deve haver mensagem de erro para o caso do usuário selecionar opção não existente. Deve ser modularizado. */

int calcularArea(int lado);
int calcularPerimetro(int lado);
float calcularDiagonal(int lado);

int calcularArea(int lado) {
    return lado * lado;
}

int calcularPerimetro(int lado) {
    return lado * 4;
}

float calcularDiagonal(int lado) {
    return lado * sqrt(2);
}
int main(){
    
  int lado;
  printf("Qual o lado do Quadrado? ");
    
  scanf("%d", &lado);
    
  int Operador;
  printf("Qual operacao realizar? \n");
  printf("1 - Area\n");
  printf("2 - perímetro \n");
  printf("3 - diagonal \n");
  scanf("%d", &Operador);
    
  switch (Operador){
  case 1: printf("A area é: %d m² \n",calcularArea(lado)); break;
  case 2: printf("O perimetro é: %d m \n",calcularPerimetro(lado)); break;
  case 3: printf("A diagonal é : %.2f \n",calcularDiagonal(lado)); break;
  default:
  printf("A opção desejada não existe. \n"); break;
  }
    return 0;
  }