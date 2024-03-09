#include <stdio.h>

/* D. Maria tem um ônibus que faz diariamente, das 8 as 18 horas, o trajeto Rosa Elze – Atalaia. É feita 1 viagem por hora e D. Maria registra o número de passageiros de cada uma para identificar o horário com maior número de passageiros. Para tanto foi implementado e discutido em sala um programa em C. Efetuar ajustes nesse de forma que seja identificado o horário com menor número de passageiros, exibir o número médio de passageiros, a soma de passageiros do dia e o montante recebido por D. Maria, considerando que a passagem custa R$22,00. Aplicar for e pelo menos 1 função. */

// Função para registrar o número de passageiros e encontrar o horário com o menor número de passageiros
void registrar_passageiros(int *total_passageiros, float *montante, int *hora_menor_passageiros) {
    *hora_menor_passageiros = 8;
    int menor_passageiros = -1; // Inicializando com um valor impossível

    for (int hora = 8; hora <= 18; hora++) {
        int NumPassageiros;
        printf("Passageiros às %d horas: ", hora);
        scanf("%d", &NumPassageiros);

        *total_passageiros += NumPassageiros;
        *montante += NumPassageiros * 22.0; // Passagem custa R$22.00

        if (menor_passageiros == -1 || NumPassageiros < menor_passageiros) {
            menor_passageiros = NumPassageiros;
            *hora_menor_passageiros = hora;
        }
    }
}

int main() {
    int total_passageiros = 0;
    float montante = 0.0;
    int hora_menor_passageiros = 0;

    printf("Registro de passageiros do ônibus de D. Maria:\n");

    registrar_passageiros(&total_passageiros, &montante, &hora_menor_passageiros);

    float media_passageiros = (float)total_passageiros / 11.0;

    printf("\nHorário com menor número de passageiros: %d horas\n", hora_menor_passageiros);
    printf("Número médio de passageiros: %.2f\n", media_passageiros);
    printf("Soma de passageiros do dia: %d\n", total_passageiros);
    printf("Montante recebido por D. Maria: R$%.2f\n", montante);

    return 0;
}


