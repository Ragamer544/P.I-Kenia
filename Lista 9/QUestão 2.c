#include <stdio.h>
#include <string.h>

// Função de busca binária em um vetor de strings
// Parâmetros:
//   - chave: string a ser buscada
//   - inicio: índice inicial do intervalo de busca
//   - fim: índice final do intervalo de busca
//   - vetor: vetor de strings onde a busca será realizada
// Retorna:

//   - O índice da chave no vetor, se encontrada; caso contrário, retorna -1
int bbinaria(char chave[], int inicio, int fim, char vetor[][30]) {
    // Verifica se o índice de fim é menor que o índice de início
    if (fim < inicio)
        return -1; // Chave não encontrada
    else {
        // Calcula o índice do meio do intervalo
        int meio = (inicio + fim) / 2;
        // Compara a chave com o elemento do vetor no índice do meio
        int comparacao = strcmp(vetor[meio], chave);

        // Se a comparação resultar em 0, a chave foi encontrada no meio do intervalo
        if (comparacao == 0)
            return meio;
        // Se a comparação for menor que 0, a chave está na metade direita do intervalo
        else if (comparacao < 0)
            return bbinaria(chave, meio + 1, fim, vetor); // Busca recursivamente na metade direita
        // Se a comparação for maior que 0, a chave está na metade esquerda do intervalo
        else
            return bbinaria(chave, inicio, meio - 1, vetor); // Busca recursivamente na metade esquerda
    }
}

int main() {
    // Vetor de strings ordenado
    char vetor[6][30] = {"arroz","banana","batata", "feijao","pao", "tomate"};
    // Chave a ser buscada
    char chave[] = "feijao";
    // Chama a função de busca binária passando a chave, os índices de início e fim do vetor e o vetor em si
    int posicao = bbinaria(chave, 0, 5, vetor);

    // Verifica se a chave foi encontrada
    if (posicao != -1)
        // Imprime a posição onde a chave foi encontrada
        printf("A chave \"%s\" foi encontrada na posição %d.\n", chave, posicao);
    else
        // Imprime que a chave não foi encontrada no vetor
        printf("A chave \"%s\" não foi encontrada no vetor.\n", chave);

    return 0;
}
