#include <stdio.h>

 int main () {
 int anoDaVacina , periodicidade ;
  printf ("Me diga o ano da primeira vacina :\n ");
  scanf  ("%d" , &anoDaVacina);
  printf ("Me diga a periodicidade da vacina : \n");
  scanf  ("%d" , &periodicidade);
   int proxAnosDeVacina1 = (anoDaVacina + periodicidade), 
       proxAnosDeVacina2 = (proxAnosDeVacina1 + periodicidade), 
       proxAnosDeVacina3 = (proxAnosDeVacina2 + periodicidade);
  printf ("As próximas Vacinas seram, respectivamente em :%d, %d, %d ",proxAnosDeVacina1, proxAnosDeVacina2, proxAnosDeVacina3); 
   return 0;
} 