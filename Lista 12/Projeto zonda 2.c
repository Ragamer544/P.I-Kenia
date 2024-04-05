#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_MOTOS 50
#define MAX_HISTORICO 100

struct RegMoto {
    char Nome[20];
    char Modelo[10];
    char Placa[8];
    char Defeito[50];
    char Status;
    float Preco;
};

typedef struct RegMoto TpRegMoto;

struct HistoricoFinanceiro {
    char data[11];
    float valorRecebido;
};

typedef struct HistoricoFinanceiro TpHistoricoFinanceiro;

TpRegMoto VZonda[MAX_MOTOS];
char placasUtilizadas[MAX_MOTOS][8]; // Vetor para armazenar as placas já utilizadas
int Quant = 0;

void SolicitaServico() {
    char Sair;
    do {
        if (Quant < MAX_MOTOS) {
            printf("\n\n >>> Motos Zonda <<< \n\n");
            printf("Qual o nome do cliente? ");
            scanf(" %[^\n]s", VZonda[Quant].Nome);
            VZonda[Quant].Nome[0] = toupper(VZonda[Quant].Nome[0]);
            for (int i = 1; VZonda[Quant].Nome[i] != '\0'; i++) {
                VZonda[Quant].Nome[i] = tolower(VZonda[Quant].Nome[i]);
            }
            printf("Qual o modelo da moto? ");
            scanf(" %[^\n]s", VZonda[Quant].Modelo);
            int placaRepetida;
            do {
                printf("Qual a placa da moto? ");
                scanf(" %[^\n]s", VZonda[Quant].Placa);
                placaRepetida = 0; // Inicializa como falso
                // Verificar se a placa já está em uso
                for (int i = 0; i < Quant; i++) {
                    if (strcmp(VZonda[i].Placa, VZonda[Quant].Placa) == 0) {
                        placaRepetida = 1; // Placa repetida encontrada
                        break;
                    }
                }
                if (placaRepetida) {
                    printf("Placa já está em uso. Por favor, insira outra placa.\n");
                }
            } while (placaRepetida); // Repetir até que uma placa única seja inserida
            strcpy(placasUtilizadas[Quant], VZonda[Quant].Placa); // Armazenar a placa utilizada
            printf("Qual o defeito da moto? ");
            scanf(" %[^\n]s", VZonda[Quant].Defeito);
            VZonda[Quant].Status = '0';
            VZonda[Quant].Preco = 0;
            Quant++;
        } else {
            printf("Limite de solicitações atingido.\n");
            break;
        }
        printf("\n\n Deseja inserir novo servico? S|N ");
        scanf(" %c", &Sair);
        Sair = toupper(Sair);
    } while (Sair != 'N');
}

// Função para iniciar um serviço
void IniciaServico() {
    char P[8]; // Corrigido para 8 para acomodar os 7 caracteres da placa e o caractere nulo '\0'
    printf("Placa da moto para iniciar serviço: ");
    scanf(" %[^\n]s", P);
    for (int i = 0; i < Quant; i++) {
        if (strcmp(VZonda[i].Placa, P) == 0) {
            VZonda[i].Status = '1'; // Define o status como '1' indicando serviço iniciado
            printf("Serviço iniciado com sucesso para a moto de placa %s.\n", VZonda[i].Placa);
            return;
        }
    }
    printf("Moto não cadastrada!");
}

// Função para remover uma solicitação de serviço
void RemoverSolicitacao() {
    char P[8]; // Corrigido para 8 para acomodar os 7 caracteres da placa e o caractere nulo '\0'
    printf("Placa da moto para remover solicitação: ");
    scanf(" %[^\n]s", P);
    for (int i = 0; i < Quant; i++) {
        if (strcmp(VZonda[i].Placa, P) == 0) {
            if (VZonda[i].Status == '0') {
                VZonda[i].Status = '2'; // Define o status como '2' (serviço removido)
                printf("Solicitação removida com sucesso para a moto de placa %s.\n", VZonda[i].Placa);
                return;
            } else {
                printf("Não é possível remover a solicitação. O serviço já foi iniciado.\n");
                return;
            }
        }
    }
    printf("Moto não cadastrada!");
}

// Função para consultar as solicitações de serviço cadastradas
void ConsultarSolicitacoes() {
    printf("\n\n >>> Motos Zonda <<< \n\n");

    if (Quant == 0) {
        printf("Não há serviços não concluídos.\n");
        return;
    }

    printf("Solicitações de Serviço Não Concluídas:\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < Quant; i++) {
        if (VZonda[i].Status != '3') { // Verifica se o serviço não está concluído
            printf("Cliente: %s\n", VZonda[i].Nome);
            printf("Modelo: %s\n", VZonda[i].Modelo);
            printf("Defeito: %s\n", VZonda[i].Defeito);
            printf("Placa: %s\n", VZonda[i].Placa);
            printf("Status: %c\n", VZonda[i].Status);
            printf("Preço: %.2f\n", VZonda[i].Preco);
            printf("----------------------------------------\n");
        }
    }
}


// Função para concluir um serviço
void ConcluirServico() {
    char P[8]; // Corrigido para 8 para acomodar os 7 caracteres da placa e o caractere nulo '\0'
    printf("Placa da moto para concluir serviço: ");
    scanf(" %[^\n]s", P);
    for (int i = 0; i < Quant; i++) {
        if (strcmp(VZonda[i].Placa, P) == 0) {
            if (VZonda[i].Status == '1') {
                printf("Digite o preço final do serviço: ");
                scanf("%f", &VZonda[i].Preco);
                VZonda[i].Status = '3'; // Define o status como '3' (serviço concluído)
                printf("Serviço concluído com sucesso para a moto de placa %s.\n", VZonda[i].Placa);
                return;
            } else {
                printf("Não é possível concluir o serviço. O serviço não foi iniciado.\n");
                return;
            }
        }
    }
    printf("Moto não cadastrada!");
}
// Função para atualizar o histórico financeiro com os dados do expediente atual
void AtualizarHistoricoFinanceiro(TpHistoricoFinanceiro historico[], int *numRegistros, float totalRecebido) {
    // Verificar se já existe registro no histórico
    if (*numRegistros > 0) {
        // Somar o valor recebido ao último registro
        historico[*numRegistros - 1].valorRecebido += totalRecebido;
    } else {
        // Caso contrário, criar um novo registro
        // Obtém o tempo atual
        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);

        // Formata a data no formato dd/mm/aaaa
        strftime(historico[*numRegistros].data, sizeof(historico[*numRegistros].data), "%d/%m/%Y", timeinfo);
        historico[*numRegistros].valorRecebido = totalRecebido;
        (*numRegistros)++;
    }
}


void EncerrarExpediente(TpHistoricoFinanceiro historicoFinanceiro[], int *numRegistrosHistorico) {
    float totalRecebido = 0; // Variável para armazenar o total recebido
    // Abrir arquivo auxiliar para guardar os dados das motos não concluídas
    FILE *arquivoAuxiliar = fopen("motos_nao_concluidas.txt", "w");
    if (arquivoAuxiliar == NULL) {
        printf("Erro ao abrir o arquivo auxiliar.\n");
        return;
    }

    int motosNaoConcluidas = 0; // Variável para verificar se há motos não concluídas

    // Guardar os dados das motos não concluídas no arquivo auxiliar e calcular o total recebido
    for (int i = 0; i < Quant; i++) {
        if (VZonda[i].Status != '3') { // Se o serviço não estiver concluído
            fprintf(arquivoAuxiliar, "%s\n%s\n%s\n%s\n%c\n%.2f\n", VZonda[i].Nome, VZonda[i].Modelo, VZonda[i].Placa,
                    VZonda[i].Defeito, VZonda[i].Status, VZonda[i].Preco);
            motosNaoConcluidas = 1; // Indica que há pelo menos uma moto não concluída
        } else {
            totalRecebido += VZonda[i].Preco; // Incrementa o total recebido
        }
    }

    fclose(arquivoAuxiliar);

    if (motosNaoConcluidas) { // Se houver motos não concluídas
        printf("Expediente encerrado. Dados das motos não concluídas foram salvos.\n");
    } else {
        remove("motos_nao_concluidas.txt");
        printf("O arquivo de motos não concluídas foi removido pois não há serviços pendentes.\n");
    }

    // Atualizar o histórico financeiro com os dados do expediente atual
    AtualizarHistoricoFinanceiro(historicoFinanceiro, numRegistrosHistorico, totalRecebido);
}

// Função para exibir o histórico financeiro
void ExibirHistoricoFinanceiro(TpHistoricoFinanceiro historico[], int numRegistros) {
    float total = 0;
    float maiorValor = 0;
    char dataMaiorValor[11]; // Data correspondente ao maior valor
    for (int i = 0; i < numRegistros; i++) {
        printf("Data: %s | Valor: %.2f\n", historico[i].data, historico[i].valorRecebido);
        total += historico[i].valorRecebido;
        if (historico[i].valorRecebido > maiorValor) {
            maiorValor = historico[i].valorRecebido;
            strcpy(dataMaiorValor, historico[i].data);
        }
    }
    printf("Total Recebido: %.2f\n", total);
    printf("Data com Maior Valor: %s\n", dataMaiorValor);
}

void CarregarMotosNaoConcluidas() {
FILE *arquivoAuxiliar = fopen("motos_nao_concluidas.txt", "r");
if (arquivoAuxiliar == NULL) {
  printf("Nenhum arquivo de motos não concluídas encontrado.\n");
  return;
}

while (fscanf(arquivoAuxiliar, " %19[^\n] %9[^\n] %7[^\n] %49[^\n] %c %f",
              VZonda[Quant].Nome, VZonda[Quant].Modelo, VZonda[Quant].Placa,
              VZonda[Quant].Defeito, &VZonda[Quant].Status, &VZonda[Quant].Preco) != EOF) {
  strcpy(placasUtilizadas[Quant], VZonda[Quant].Placa);
  Quant++;
  if (Quant >= MAX_MOTOS) {
    break;
  }
}
}


int main() {
    int Opcao;
    TpHistoricoFinanceiro historicoFinanceiro[MAX_HISTORICO];
    int numRegistrosHistorico = 0;

    // Carregar motos não concluídas do arquivo auxiliar
    CarregarMotosNaoConcluidas();

    // Inicializar o histórico financeiro com os dados salvos no arquivo auxiliar
    FILE *arquivoHistorico = fopen("historico_financeiro.txt", "r");
    if (arquivoHistorico != NULL) {
        while (fscanf(arquivoHistorico, "%s %f", historicoFinanceiro[numRegistrosHistorico].data,
                      &historicoFinanceiro[numRegistrosHistorico].valorRecebido) != EOF) {
            numRegistrosHistorico++;
        }
        fclose(arquivoHistorico);
    }

    // Loop principal do programa
    do {
        // Exibição do menu e leitura da opção escolhida pelo usuário
        printf("\n\n >>> Motos Zonda <<< \n\n");
        printf("1 - Solicitar Servico \n");
        printf("2 - Iniciar Servico \n");
        printf("3 - Remover Solicitacao \n");
        printf("4 - Consultar Solicitacoes \n");
        printf("5 - Concluir Servico \n");
        printf("6 - Encerrar Expediente \n");
        printf("7 - Histórico Financeiro \n");
        printf("8 - Sair \n\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &Opcao);
        // Switch para executar a opção escolhida pelo usuário
        switch (Opcao) {
            case 1:
                SolicitaServico();
                break;
            case 2:
                IniciaServico();
                break;
            case 3:
                RemoverSolicitacao();
                break;
            case 4:
                ConsultarSolicitacoes();
                break;
            case 5:
                ConcluirServico();
                break;
            case 6:
                EncerrarExpediente(historicoFinanceiro, &numRegistrosHistorico);
                break;
            case 7:
                printf("\n\n >>> Histórico Financeiro <<< \n\n");
                ExibirHistoricoFinanceiro(historicoFinanceiro, numRegistrosHistorico);
                break;
            case 8:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida! Por favor, tente novamente.\n");
        }
    } while (Opcao != 8); // Continua executando até que o usuário escolha sair
    return 0;
}
