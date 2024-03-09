#include <stdio.h>

int main() {

 int n;

 printf("Informe um valor para n (1 <= n <= 40): ");
 scanf("%d", &n);

if (n < 1 || n > 40) {
  
 printf("Valor de n fora do intervalo permitido.\n");
  
 return 0;  
 }

for (int i = 1; i <= n; i++) {
    
  for (int j = 1; j <= i; j++) {
            
 printf("%d ", j);

 printf("\n");
 }
return 0;
}
  }



/* int main () {

  printf("Informe um valor para n (1 <= n <= 40): ");
  
  int n;

  scanf ("%d", &n);

  int i, j = 1;

  do{

    i = 1 ;
    do {
      printf ("%d", i);
      i++ ;
    } while (i <= j);
     printf ("\n");
    j++;
  } while (j <= n);
  
  return 0;
} */
