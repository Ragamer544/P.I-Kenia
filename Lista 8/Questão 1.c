#include <stdio.h>
#include <stdlib.h>

float M[4][6] = {
    {385, 534, 309, 546, 503, 477},
    {12, 121, 12, 3, 24, 12},
    {35.9, 72.1, 46.2, 74.3, 78, 90},
    {-28, -18, -18, -18, -22, -18}
};

int Frz, Crc;

void ExibeMatriz(float Matriz[][6], int L, int C) {
    printf("                      Deia   Sul  NSul  Frio   Fri   Lux \n");
    for (int i = 0; i < L; i++) {
        if (i == 0) printf("Capacidade (litros) ");
        if (i == 1) printf("Garantia (meses)    ");
        if (i == 2) printf("Economia (KWh/mes)  ");
        if (i == 3) printf("Temperatura Min (C) ");
        for (int j = 0; j < C; j++)
            printf("%6.1f", Matriz[i][j]);
        printf("\n");
    }
}

void ExibeColuna(float Matriz[][6], int L, int C) {
    for (int i = 0; i < L; i++) {
        if (i == 0) printf("Capacidade (litros) ");
        if (i == 1) printf("Garantia (meses)    ");
        if (i == 2) printf("Economia (KWh/mes)  ");
        if (i == 3) printf("Temperatura Min (C) ");
        printf("%6.1f\n", Matriz[i][C]);
    }
}

void ExibeLinha(float Matriz[][6], int L, int C) {
    printf("Deia   Sul  NSul  Frio   Fri   Lux \n");
    for (int i = 0; i < C; i++)
        printf("%.1f ", Matriz[L][i]);
    printf("\n");
}

void SelecionaFreezer(float Matriz[][6], int *F) {
    printf("Selecione o freezer desejado:\n");
    printf("1 - Deia\n");
    printf("2 - Sul\n");
    printf("3 - NSul\n");
    printf("4 - Frio\n");
    printf("5 - Fri\n");
    printf("6 - Lux\n\n");
    printf("Opcao: ");
    int Op;
    scanf("%d", &Op);
    *F = Op - 1;
}

void SelecionaCaracteristica(float Matriz[][6], int *C) {
    printf("Caracteristica desejada:\n");
    printf("1 - Capacidade (litros)\n");
    printf("2 - Garantia (meses)\n");
    printf("3 - Economia (KWh/mes)\n");
    printf("4 - Temperatura Minima (Celsius)\n");
    printf("Opcao: ");
    int Op;
    scanf("%d", &Op);
    *C = Op - 1;
}

void AlterarDado(float Matriz[][6], int L, int C) {
    int linha, coluna;
    float novoValor;
    printf("Digite a linha e a coluna para alterar (linha coluna): ");
    scanf("%d %d", &linha, &coluna);
    printf("Digite o novo valor: ");
    scanf("%f", &novoValor);
    Matriz[linha - 1][coluna - 1] = novoValor;
    printf("Dado alterado com sucesso!\n");
}

void MelhorFreezerCapacidade(float Matriz[][6], int L, int C) {
    float maxCapacidade = -1;
    int freezerIndex = -1;
    for (int i = 0; i < L; i++) {
        if (Matriz[i][0] > maxCapacidade) {
            maxCapacidade = Matriz[i][0];
            freezerIndex = i;
        }
    }
    printf("Melhor freezer em capacidade: %.1f (Freezer %d)\n", maxCapacidade, freezerIndex + 1);
}

void MelhorFreezerGarantia(float Matriz[][6], int L, int C) {
    float maxGarantia = -1;
    int freezerIndex = -1;
    for (int i = 0; i < L; i++) {
        if (Matriz[i][1] > maxGarantia) {
            maxGarantia = Matriz[i][1];
            freezerIndex = i;
        }
    }
    printf("Melhor freezer em garantia: %.0f meses (Freezer %d)\n", maxGarantia, freezerIndex + 1);
}

void MelhorFreezerEconomia(float Matriz[][6], int L, int C) {
    float maxEconomia = -1;
    int freezerIndex = -1;
    for (int i = 0; i < L; i++) {
        if (Matriz[i][2] > maxEconomia) {
            maxEconomia = Matriz[i][2];
            freezerIndex = i;
        }
    }
    printf("Melhor freezer em economia: %.1f kWh/mes (Freezer %d)\n", maxEconomia, freezerIndex + 1);
}

void MelhorFreezerTemperatura(float Matriz[][6], int L, int C) {
    float minTemperatura = 999;
    int freezerIndex = -1;
    for (int i = 0; i < L; i++) {
        if (Matriz[i][3] < minTemperatura) {
            minTemperatura = Matriz[i][3];
            freezerIndex = i;
        }
    }
    printf("Melhor freezer em temperatura: %.1f C (Freezer %d)\n", minTemperatura, freezerIndex + 1);
}

int main() {
    int Op;
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
        scanf("%d", &Op);
        switch (Op) {
            case 1:
                ExibeMatriz(M, 4, 6);
                system("pause");
                break;
            case 2:
                SelecionaFreezer(M, &Frz);
                ExibeColuna(M, 4, Frz);
                system("pause");
                break;
            case 3:
                SelecionaCaracteristica(M, &Crc);
                ExibeLinha(M, Crc, 6);
                system("pause");
                break;
            case 4:
                AlterarDado(M, 4, 6);
                system("pause");
                break;
            case 5:
                MelhorFreezerCapacidade(M, 4, 6);
                system("pause");
                break;
            case 6:
                MelhorFreezerGarantia(M, 4, 6);
                system("pause");
                break;
            case 7:
                MelhorFreezerEconomia(M, 4, 6);
                system("pause");
                break;
            case 8:
                MelhorFreezerTemperatura(M, 4, 6);
                system("pause");
                break;
            case 9:
                break;
        }
    } while (Op != 9);
    return 0;
}
