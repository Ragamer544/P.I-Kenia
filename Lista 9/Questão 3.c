/* (03) Pesquisar método de classificação de
dados diferente do trabalhado em sala de
aula, recursivo, e apresentar de forma
semelhante à do slide 64 */

#include <stdio.h>

// Função para trocar dois elementos de posição em um vetor
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para particionar o vetor para o algoritmo Quick Sort
// Retorna o índice do pivo
int particionar(int vetor[], int inicio, int fim) {
    // Define o pivo como o último elemento do vetor
    int pivo = vetor[fim];
    // Define o índice do elemento menor que o pivo
    int i = (inicio - 1);

    // Percorre o vetor da posição inicial até a posição final - 1
    for (int j = inicio; j <= fim - 1; j++) {
        // Se o elemento atual for menor que o pivo
        if (vetor[j] < pivo) {
            // Incrementa o índice do elemento menor
            i++;
            // Troca os elementos de posição
            trocar(&vetor[i], &vetor[j]);
        }
    }
    // Troca o pivo com o elemento seguinte ao último menor
    trocar(&vetor[i + 1], &vetor[fim]);
    // Retorna o índice do pivo
    return (i + 1);
}

// Função recursiva para realizar o Quick Sort
void quick_sort_recursivo(int vetor[], int inicio, int fim) {
    // Se o índice inicial for menor que o final
    if (inicio < fim) {
        // Particiona o vetor e obtém o índice do pivo
        int pi = particionar(vetor, inicio, fim);
        // Chama recursivamente o Quick Sort para as sub-listas à esquerda e à direita do pivo
        quick_sort_recursivo(vetor, inicio, pi - 1);
        quick_sort_recursivo(vetor, pi + 1, fim);
    }
}

// Função principal que chama o Quick Sort
void quick_sort(int vetor[], int inicio, int fim) {
    // Chama a função recursiva do Quick Sort
    quick_sort_recursivo(vetor, inicio, fim);
}

int main() {
    // Vetor de exemplo
    int vetor[] = {12, 45, 32, 6, 23, 43,23,74,11,36};
    int tamanho = 10; // Tamanho do vetor
    // Imprime o vetor original
    printf("Vetor original:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Chama a função Quick Sort para ordenar o vetor
    quick_sort(vetor, 0, tamanho - 1);

    // Imprime o vetor ordenado
    printf("Vetor ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}
