#include <stdio.h>
#include <ctype.h>

/* Escrever programa para ler uma palavra P qualquer
com até 20 caracteres e identificar quantas vogais P
apresenta. Aplicar função definida pelo programador
Efetuar essa operação para tantas strings quantas o usuário
desejar. */

// Função para contar vogais em uma string
int contarVogais(char palavra[]) {
    int vogais = 0;

    // Itera sobre cada caractere da palavra
    for(int i = 0; palavra[i] != '\0'; i++) {
        char caractere = tolower(palavra[i]);
      
        if(caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u') 
            vogais++;
        
    }
    return vogais;
}

int main() {
    char palavra[21]; 
    char continuar; 

    do {
        printf("Digite uma palavra com até 20 caracteres: ");
        scanf("%20s", palavra); 

        int numVogais = contarVogais(palavra);

        printf("A palavra '%s' possui %d vogais.\n", palavra, numVogais);

        printf("Deseja verificar outra palavra? (s/n): ");
        scanf(" %c", &continuar);
    } while(continuar == 's' || continuar == 'S');

    return 0;
}