#include <stdio.h>
#include <ctype.h>
/* Sabendo-se que Y=toupper(X) corresponde a
função em C (biblioteca ctype.h) que atribui à
variável Y do tipo char o valor da variável X
(também do tipo char) em maiúsculo.

Escrever programa para ler uma palavra com até 20
caracteres e exibi-la com letras maiúsculas.
Exemplos: dado brasileiro, retorna BRASILEIRO.
Dado Nordeste, retorna NORDESTE. */


int main() {
    char palavra[21]; // Array para armazenar a palavra (20 caracteres + 1 para o caractere nulo)

    // Solicita ao usuário que insira a palavra
    printf("Digite uma palavra com até 20 caracteres: ");
    scanf("%20s", palavra); // Lê a palavra (no máximo 20 caracteres)

    // Converte cada caractere da palavra para maiúsculo
    for(int i = 0; palavra[i] != '\0'; i++) {
        palavra[i] = toupper(palavra[i]);
    }

    // Exibe a palavra em maiúsculas
    printf("Palavra em maiúsculas: %s\n", palavra);

    return 0;
}

