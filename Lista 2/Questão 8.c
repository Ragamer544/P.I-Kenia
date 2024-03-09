#include <stdio.h>

/* 8.Escrever um programa em C para ler um valor V em reais, taxa de
câmbio fixa de dólar e taxa de câmbio fixa de euro e exibir em tela os
correspondentes a V em dólar e em euro. Para tanto, criar função F em que
dados valor e taxa de câmbio, retorna o valor convertido. Criar módulo com
aplicação de F, parâmetros de entrada e dois parâmetros de saída: valor em
dólar e valor em euro. */



float converterMoeda (float real ,float taxaDolar,float taxaEuro,float *dolar , float *euro){

  *dolar = real / taxaDolar;
  *euro  = real / taxaEuro;

  return *dolar;
  return *euro;
}

int main () {

 float real, dolar, euro, taxaDolar, taxaEuro;

  printf  ("Digite o valor em reais:");
    scanf ("%f", &real);
  printf  ("Qual a taxa de cambio do dolar? ");
    scanf ("%f", &taxaDolar);
  printf  ("Qual a taxa de cambio do euro :");
    scanf ("%f", &taxaEuro);

  converterMoeda(real,taxaDolar, taxaEuro,&dolar, &euro);
  
  printf ("O valor em dolar é %.2f em euros é %.2f", dolar, euro );

  return 0;
}