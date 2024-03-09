#include <stdio.h>


int main () {
float pesoAtual , pesoIdeal, perdaMensal, perdaDiaria ;
printf ("Me diga seu peso atual \n") ;
scanf  ("%f", &pesoAtual);
printf ("Me diga seu peso ideal \n");
scanf  ("%f", &pesoIdeal);
printf ("Me diga a quantidade de quilos que voce deseja perder por mes \n");
scanf  ("%f" , &perdaMensal);
printf ("Voce alcançara seu peso ideal em dias : %.0f " ,perdaDiaria= (((pesoAtual - pesoIdeal)/perdaMensal )*30));
return 0 ;
} 