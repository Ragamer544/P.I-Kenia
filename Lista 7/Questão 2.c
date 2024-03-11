/*Ajustar o módulo de saída do cliente, calculando e exibindo o valor
a pagar, lendo o valor pago e calculando o troco. Vocês podem fazer uma proposta
de cálculo de valor a pagar considerando horas completas e minutos extras (inferior
a 1 hora)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char Estaciona[30][14];
float Valor;
char Responsavel[21], Iniciou = 0;

void AbrirCaixa() {
    system("cls");
    system("color 80");
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>>  Largas Vagas  <<< \n");
    printf("\n     ABRINDO  CAIXA \n");
    for (int i = 0; i < 30; i++)
        strcpy(Estaciona[i], "LIVRE");
    printf("\nQual o valor do estacionamento por hora de uso? ");
    scanf("%f", &Valor);
    fflush(stdin);
    printf("Qual o nome do responsavel? ");
    scanf("%20s", Responsavel);
    Iniciou = 1;
}

void ClienteChega() {
    int Vaga;
    char Placa[8], Hora[5], Entrada[14];
    system("cls");
    system("color 80");
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>>  Largas Vagas  <<< \n");
    printf("\n   CHEGADA DE CLIENTE \n");
    if (Iniciou) {
        printf("\n CAIXA ABERTO   Valor/h: %.2f", Valor);
        printf("\n Responsavel: %s\n\n", Responsavel);
        printf("Qual a vaga ocupada? ");
        scanf("%d", &Vaga);
        fflush(stdin);
        printf("Qual a placa do veiculo [7 digitos]? ");
        scanf("%s", Placa);
        strcpy(Entrada, Placa);
        fflush(stdin);
        printf("Qual a hora de entrada [formato nn:nn]? ");
        scanf("%s", Hora);
        strcat(Entrada, "+");
        strcat(Entrada, Hora);
        strcpy(Estaciona[Vaga - 1], Entrada);
        printf("Chegada registrada com sucesso!\n");
    } else {
        printf("\nERRO: Antes eh preciso abrir o caixa!\n");
    }
    system("pause");
}

void ClienteSai() {
    int Vaga;
    char Placa[8], Entrada[14], Hora[3], Min[3];
    int H, M, HoraSaida, MinSaida; // hora, minuto e segundo
    float TotalPagar, Pago, Troco;
    system("cls");
    system("color 80");
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>>  Largas Vagas  <<< \n");
    printf("\n    SAIDA DE CLIENTE \n");
    if (Iniciou) {
        printf("\n CAIXA ABERTO   Valor/h: %.2f", Valor);
        printf("\n Responsavel: %s\n\n", Responsavel);
        printf("Qual a vaga ocupada? ");
        scanf("%d", &Vaga);

        strcpy(Entrada, Estaciona[Vaga - 1]);

        Hora[0] = Entrada[8];
        Hora[1] = Entrada[9];
        Hora[2] = '\0';
        H = atoi(Hora);
        Min[0] = Entrada[11];
        Min[1] = Entrada[12];
        Min[2] = '\0';
        M = atoi(Min);

        printf("\nHorario de entrada: %d:%d\n", H, M);

        printf("Qual o horario de saida [formato nn:nn]? ");
        scanf("%d:%d", &HoraSaida, &MinSaida);

        int TempoEstacionado = (HoraSaida - H) * 60 + (MinSaida - M);

        int HorasCompletas = TempoEstacionado / 60;
        int MinutosExtras = TempoEstacionado % 60;

        TotalPagar = Valor * HorasCompletas;
        if (MinutosExtras > 0) {
            TotalPagar += Valor; // Adiciona uma hora extra se houver minutos extras
        }

        printf("\nTotal a pagar: %.2f\n", TotalPagar);

        printf("Qual o valor pago? ");
        scanf("%f", &Pago);

        Troco = Pago - TotalPagar;

        printf("\nTroco: %.2f\n", Troco);

    } else {
        printf("\nERRO: Antes eh preciso abrir o caixa!\n");
    }
    system("pause");
}

void FecharCaixa() {
}

int main() {
    int Op;
    do {
        system("cls");
        system("color 70");
        printf("\n >>> Estacionamento <<< \n");
        printf(" >>>  Largas Vagas  <<< \n");
        printf("\n 1 - Abrir Caixa");
        printf("\n 2 - Chegada de Cliente");
        printf("\n 3 - Saida de Cliente");
        printf("\n 4 - Fechar Caixa");
        printf("\n\n Qual a opcao desejada? ");
        do {
            scanf("%d", &Op);
            if ((Op < 1) || (Op > 4)) {
                printf("\n ERRO: Opcao invalida!");
                printf("\n Qual a opcao desejada? ");
            } else {
                break;
            }
        } while (1);
        switch (Op) {
            case 1:
                AbrirCaixa();
                break;
            case 2:
                ClienteChega();
                break;
            case 3:
                ClienteSai();
                break;
            case 4:
                FecharCaixa();
                break;
        }
    } while (Op != 4);

    return 0;
}