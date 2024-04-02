/*(04) implementá-lo aplicando a vetor composto por 25 palavras (previamente definidas e desordenadas).*/

#include <stdio.h>
#include <string.h>

// Função para trocar duas strings de posição em um vetor
void trocar(char *a, char *b) {
    char temp[30]; // Array temporário para armazenar uma das strings durante a troca
    strcpy(temp, a); // Copia o conteúdo da string 'a' para 'temp'
    strcpy(a, b); // Copia o conteúdo da string 'b' para 'a'
    strcpy(b, temp); // Copia o conteúdo de 'temp' (que originalmente era 'a') para 'b'
}

// Função para particionar o vetor de strings para o algoritmo Quick Sort
// Retorna o índice do pivô
int particionar(char vetor[][30], int inicio, int fim) {
    char pivo[30]; // String que servirá como pivô para a comparação
    strcpy(pivo, vetor[fim]); // Define o pivô como o último elemento do vetor
    int i = (inicio - 1); // Inicializa o índice do elemento menor que o pivô

    // Percorre o vetor da posição inicial até a posição final - 1
    for (int j = inicio; j <= fim - 1; j++) {
        // Se a string atual for menor que o pivô
        if (strcmp(vetor[j], pivo) < 0) {
            i++; // Incrementa o índice do elemento menor
            trocar(vetor[i], vetor[j]); // Troca as strings de posição
        }
    }
    trocar(vetor[i + 1], vetor[fim]); // Troca o pivô com o elemento seguinte ao último menor
    return (i + 1); // Retorna o índice do pivô
}

// Função recursiva para realizar o Quick Sort em um vetor de strings
void quick_sort_recursivo(char vetor[][30], int inicio, int fim) {
    if (inicio < fim) {
        int pi = particionar(vetor, inicio, fim); // Particiona o vetor e obtém o índice do pivô
        // Chama recursivamente o Quick Sort para as sub-listas à esquerda e à direita do pivô
        quick_sort_recursivo(vetor, inicio, pi - 1);
        quick_sort_recursivo(vetor, pi + 1, fim);
    }
}

// Função principal que chama o Quick Sort para ordenar um vetor de strings
void quick_sort(char vetor[][30], int tamanho) {
    quick_sort_recursivo(vetor, 0, tamanho - 1); // Chama a função recursiva do Quick Sort
}

int main() {
    // Vetor de strings desordenadas
    char palavras[25][30] = {
        "banana", "laranja", "abacaxi", "uva", "limao",
        "morango", "pera", "melancia", "maça", "abacate",
        "kiwi", "manga", "cereja", "goiaba", "melao",
        "abacate", "tangerina", "ameixa", "caqui", "pêssego",
        "framboesa", "jabuticaba", "coco", "figo"
    };

    int tamanho = sizeof(palavras) / sizeof(palavras[0]); // Calcula o tamanho do vetor

    // Imprime as palavras desordenadas
    printf("Palavras desordenadas:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s ", palavras[i]);
    }
    printf("\n");

    // Chama o Quick Sort para ordenar as palavras
    quick_sort(palavras, tamanho);

    // Imprime as palavras ordenadas
    printf("Palavras ordenadas:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s ", palavras[i]);
    }
    printf("\n");

    return 0;
}
