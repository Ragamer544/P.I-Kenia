#include <stdio.h>

int main() {
  
float Meta, Doacao, Soma = 0;
    
 printf("Meta da vaquinha: ");
 scanf("%f", &Meta);

do {
  
 printf("Valor da doacao: ");
 scanf("%f", &Doacao);
 Soma = Soma + Doacao;

 printf("Valor parcial alcancado: %.2f\n", Soma);
  

} while (Soma > Meta);

if (Soma == Meta) {
    
 printf("Parabens! A meta da vaquinha foi alcancada!");
    
} else {
    
 printf("Uau! A meta da vaquinha foi ultrapassada! Total arrecadado: %.2f", Soma);
    
}
return 0;
}
