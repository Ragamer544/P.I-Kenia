#include <stdio.h>

// 5) Escrever programa em C para solicitar ao usuário a distância que ele
// pretende correr e sua velocidade média esperada. Exibir o tempo estimado de
// exercício (corrida).

int main() {
  float distanciaEmKm, velocidadeMedia,
      tempoEmMinutos ;
  printf("Me informe a distancia que voce pretende percorrer abaixo : \n ");
  scanf("%f", &distanciaEmKm);
  printf("Me informe a velocidade media esperada abaixo : \n");
  scanf("%f", &velocidadeMedia);
  printf("O tempo em minutos estimado para o seu exercicio é : %.2f",
         tempoEmMinutos= ((distanciaEmKm / velocidadeMedia) * 60));
  return 0;
}