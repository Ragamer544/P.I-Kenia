#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Escrever programa para ler o nome de uma pessoa,
composto por nome e sobrenome (entre nome e
sobrenome há um espaço em branco). E exibir,
sobrenome em maiúsculo, seguido de vírgula e do nome
da pessoa. Efetuar essa operação para tantas entradas quantas
o usuário desejar. */

char* quebraNome (char str[]){
    char palavra [21];
    for (int i = 0 ; ; i++)
    {
    palavra[i] = str [i];

    if (str[i] == ' ')
    {
        palavra[i] = '\0';
        strcpy(str,palavra);
        return str;
    }
    }

}

void formataNome(char nome[]) {
    // Transforma a primeira letra do nome em maiúscula
    nome[0] = toupper(nome[0]);
    // Transforma as letras restantes do nome em minúsculas
    for (int i = 1; nome[i] != '\0'; i++) {
        nome[i] = tolower(nome[i]);
    }
}

int main() {
    char continuar; 
    char nome [21];
    char sobrenome [21];

    do {
        // Solicita ao usuário que insira o nome completo

        printf("Digite o nome completo (nome sobrenome):");
        scanf("%[^\n]",nome); 

        int posicao = -1;
        for (int i = 0; nome[i] != '\0'; i++) {
            if (nome[i] == ' ') {
                posicao = i;
                break;
            }
        }

        if (posicao == -1) {
            printf("Formato inválido. Por favor, insira nome e sobrenome separados por um espaço.\n");
            continue;
        }

      // Extrai o sobrenome
      strcpy(sobrenome, &nome[posicao + 1]);

      // Converte o sobrenome para maiúsculas
      for(int i = 0; sobrenome[i] != '\0'; i++) {
          sobrenome[i] = toupper(sobrenome[i]);
      }

     // Formata o Primeiro nome
      formataNome(nome);

      // função que retira o sobrenome do nome 
      quebraNome (nome);

        // Exibe o sobrenome em maiúsculas, seguido de vírgula e do nome
        printf("%s, %s\n", sobrenome, nome);

        // Solicita ao usuário se deseja continuar
        printf("Deseja verificar outro nome? (s/n): ");
        scanf(" %c", &continuar);
        getchar();
    } while(continuar == 's' || continuar == 'S');
    return 0;
}