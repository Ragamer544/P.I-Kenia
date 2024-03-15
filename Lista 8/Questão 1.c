#include <stdio.h>
#include <stdlib.h>

float M[4][6] = {
    {385, 534, 309, 546, 503, 477},
    {12, 12, 12, 3, 24, 12},
    {35.9, 72.1, 46.2, 74.3, 78, 90},
    {-28, -18, -18, -18, -22, -18}
};
char *NomeFreezers[] = {"Deia", "Sul", "NSul", "Frio", "Fri", "Lux"};

int Frez, Carac; // Variáveis globais para armazenar o freezer e a característica selecionados

// Função para encontrar o maior valor em uma linha da matriz
void ExibirMaiorValorEmLinha(float Matriz[][6], int L, int C, float *maiorValor, int *index) {
    *maiorValor = Matriz[L][0];
    *index = 0;

    for(int i = 1; i < C; i++) {
        if(Matriz[L][i] > *maiorValor) {
            *maiorValor = Matriz[L][i];
            *index = i;
        }
    }
}

// Função para encontrar o menor valor em uma linha da matriz
void ExibirMenorValorEmLinha(float Matriz[][6], int L, int C, float *menorValor, int *index) {
    *menorValor = Matriz[L][0];
    *index = 0;

    for(int i = 1; i < C; i++) {
        if(Matriz[L][i] < *menorValor) {
            *menorValor = Matriz[L][i];
            *index = i;
        }
    }
}

// Função para exibir a matriz
void ExibeMatriz(float Matriz[][6], int L, int C) {
    printf("                      Deia   Sul  NSul  Frio   Fri   Lux \n");
    for(int i = 0; i < L; i++) {
        if (i == 0) printf("Capacidade (litros) ");
        if (i == 1) printf("Garantia (meses)    ");
        if (i == 2) printf("Economia (KWh/mes)  ");
        if (i == 3) printf("Temperatura Min (C) ");
        for (int j = 0; j < C; j++)
            printf("%6.1f", Matriz[i][j]);
        printf("\n");
    }
}

// Função para exibir uma coluna da matriz
void ExibeColuna(float Matriz[][6], int L, int C) {
    for(int i = 0; i < L; i++) {
        if (i == 0) printf("Capacidade (litros) ");
        if (i == 1) printf("Garantia (meses)    ");
        if (i == 2) printf("Economia (KWh/mes)  ");
        if (i == 3) printf("Temperatura Min (C) ");
        printf("%6.1f\n", Matriz[i][C]);
    }
}

// Função para exibir uma linha da matriz
void ExibeLinha(float Matriz[][6], int L, int C) {
    printf("Deia   Sul  NSul  Frio   Fri   Lux \n");
    for(int i = 0; i < C; i++)
        printf("%6.1f ", Matriz[L][i]);
    printf("\n");
}

// Função para selecionar um freezer
int SelecionaFreezer() {
    int Op;
    printf("Selecione o freezer desejado:\n");
    printf("1 - Deia\n");
    printf("2 - Sul\n");
    printf("3 - NSul\n");
    printf("4 - Frio\n");
    printf("5 - Fri\n");
    printf("6 - Lux\n\n");
    printf("Opcao: ");
    scanf("%d", &Op);
    return Op - 1;
}

// Função para selecionar uma característica
int SelecionaCaracteristica() {
    int Op;
    printf("Caracteristica desejada:\n");
    printf("1 - Capacidade (litros)\n");
    printf("2 - Garantia (meses)\n");
    printf("3 - Economia (KWh/mes)\n");
    printf("4 - Temperatura Minima (Celsius)\n");
    printf("Opcao: ");
    scanf("%d", &Op);
    return Op - 1;
}

// Função para alterar um valor na matriz
void AlterarValor(float Matriz[][6], int Freezer, int Caract) {
    float NovoValor;
    printf("Digite o novo valor: ");
    scanf("%f", &NovoValor);

    Matriz[Freezer][Caract] = NovoValor;

    printf("Valor alterado com sucesso!\n");
}

// Função para encontrar o freezer com a melhor capacidade
void MelhorCapacidade(float Matriz[][6], int L, int C) {
    float max;
    int index;

    ExibirMaiorValorEmLinha(Matriz, L, C, &max, &index);

    printf("Melhor capacidade: %.1f (%s)\n", max, NomeFreezers[index]);
}

// Função para encontrar o freezer com a melhor garantia
void MelhorGarantia(float Matriz[][6], int L, int C) {
    float max;
    int index;

    ExibirMaiorValorEmLinha(Matriz, L, C, &max, &index);

    printf("Melhor garantia: %.1f (%s)\n", max, NomeFreezers[index]);
}

// Função para encontrar o freezer com a melhor economia
void MelhorEconomia(float Matriz[][6], int L, int C) {
    float min;
    int index;

    ExibirMenorValorEmLinha(Matriz, L, C, &min, &index);

    printf("Melhor economia: %.1f (%s)\n", min, NomeFreezers[index]);
}

// Função para encontrar o freezer com a melhor temperatura
void MelhorTemperatura(float Matriz[][6], int L, int C) {
    float min;
    int index;

    ExibirMenorValorEmLinha(Matriz, L, C, &min, &index);

    printf("Melhor temperatura: %.1f (%s) \n", min, NomeFreezers[index]);
}

// Função principal
int main() {

    // Loop principal do programa
    do {
        system("cls");
        printf(">>> Pesquisa Freezer <<<\n\n");
        printf("Selecione a opcao desejada:\n");
        printf("1 - Exibir Levantamento\n");
        printf("2 - Dados de um Freezer\n");
        printf("3 - Dados de uma Caracteristica\n");
        printf("4 - Alterar Dado\n");
        printf("5 - Melhor Freezer em Capacidade\n");
        printf("6 - Melhor Freezer em Garantia\n");
        printf("7 - Melhor Freezer em Economia\n");
        printf("8 - Melhor Freezer em Temperatura\n");
        printf("9 - Sair\n");
        int Op;
        scanf("%d", &Op);

        switch (Op) {
            case 1: ExibeMatriz(M, 4, 6);
                    system("pause");
                    break;
            case 2: Frez = SelecionaFreezer(); // Seleciona o freezer desejado
                    ExibeColuna(M, 4, Frez); // Exibe os dados do freezer selecionado
                    system("pause");
                    break;
            case 3: Carac = SelecionaCaracteristica(); // Seleciona a característica desejada
                    ExibeLinha(M, Carac, 6); // Exibe os dados da característica selecionada
                    system("pause");
                    break;
            case 4: Frez = SelecionaFreezer(); // Seleciona o freezer desejado
                    Carac = SelecionaCaracteristica(); // Seleciona a característica desejada
                    AlterarValor(M, Frez, Carac); // Altera o valor na matriz
                    system("pause");
                    break;
            case 5: MelhorCapacidade(M, 0, 6); // Encontra o freezer com melhor capacidade
                    system("pause");
                    break;
            case 6: MelhorGarantia(M, 1, 6); // Encontra o freezer com melhor garantia
                    system("pause");
                    break;
            case 7: MelhorEconomia(M, 2, 6); // Encontra o freezer com melhor economia
                    system("pause");
                    break;
            case 8: MelhorTemperatura(M, 3, 6); // Encontra o freezer com melhor temperatura
                    system("pause");
                    break;
            case 9: break; // Sai do loop
        }
        if (Op == 9)
            break;
    } while (1);

    return 0;
}
