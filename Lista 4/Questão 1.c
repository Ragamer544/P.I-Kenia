#include <stdio.h>

void ValidaCompra(float *L, int numeroCompra) {
  
float debito;
  
 printf("Debito da compra %d: ", numeroCompra);
 scanf("%f", &debito);

if (*L - debito >= 0) {

 printf("Compra %d possivel! \n", numeroCompra);
 *L = *L - debito;
  
} else {
  
 printf("Compra %d estourara o cartao! \n", numeroCompra);  
}
 printf("Limite restante: %.2f \n\n", *L);
}

int main() {
  
float Limite;
  
 printf("Limite do cartao: ");
 scanf("%f", &Limite);

int numeroCompra = 1; 

while (Limite > 0) {
  ValidaCompra(&Limite, numeroCompra);
   numeroCompra++; 
}

 printf("Seu limite de compras acabou!");
  
 return 0;
}
