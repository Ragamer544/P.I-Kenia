#include <stdio.h>
#include <ctype.h>

/* Escrever programa para ler um nome e, independente
de como este foi escrito, exibir a inicial maiúscula e o
restante minúscula. Sendo:
● Cadeia[P] = toupper(Cadeia[P]);
Converte a letra da posição P da string
Cadeia para maiúscula, da biblioteca
ctype.h.
● Cadeia[P] = tolower(Cadeia[P]);
Converte a letra da posição P da string
Cadeia para minúscula, da biblioteca
ctype.h. */

int main () {
  char palavra[21];
  
printf ("Digite uma Palavra:");
scanf ("%20s",palavra);
  
palavra[0] = toupper(palavra[0]);

for (int i = 1 ; palavra[i] != '\0'; i++) 
  
   palavra[i] = tolower(palavra[i]);
    
  
printf ("Palavra formatada: %s\n" , palavra);
  
}