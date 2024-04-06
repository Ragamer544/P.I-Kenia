#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Definição da estrutura TpFarma para representar os dados de um medicamento
struct TpFarma{
    char Nome[21];
    float Preco;
    int QEstoque;
    int Ativo; // Novo campo para exclusão lógica
};

typedef struct TpFarma TpFARMA;

FILE *ArqFarma; // Ponteiro para o arquivo de dados

float totalVendido = 0;

// Variável global que representa o tamanho de cada registro no arquivo
long int Tamanho=21*sizeof(char)+sizeof(float)+sizeof(int)*2; // Alterado para incluir o novo campo Ativo

// Função para formatar o nome do medicamento (primeira letra de cada palavra maiúscula, restante minúscula)
void FormatarNome(char *nome) {
    int i = 0;
    while (nome[i] != '\0') {
        nome[i] = tolower(nome[i]); // Converte para minúsculas
        if (i == 0 || (i > 0 && nome[i - 1] == ' ')) {
            nome[i] = toupper(nome[i]); // Capitaliza a primeira letra de cada palavra
        }
        i++;
    }
}

// Função para verificar se um medicamento já está cadastrado
int VerificarExistencia(const char *nome) {
    TpFARMA RgFarma; // Variável local

    fseek(ArqFarma, 0, SEEK_SET);
    while (fread(&RgFarma, Tamanho, 1, ArqFarma) == 1) {
        if (strcmp(RgFarma.Nome, nome) == 0 && RgFarma.Ativo) {
            return 1; // Já existe
        }
    }
    return 0; // Não existe
}

// Função para incluir um novo medicamento
void Incluir() {
    TpFARMA RgFarma; // Variável local
    char R;
    do {
        printf("*** inclusao ***\n\n");
        printf("Nome: ");
        scanf("%s",RgFarma.Nome);

        // Formatando o nome do medicamento
        FormatarNome(RgFarma.Nome);

        if (VerificarExistencia(RgFarma.Nome)) {
            printf("Este fármaco já está cadastrado!\n");
        } else {
            printf("Preco: ");
            scanf("%f",&RgFarma.Preco);
            printf("Estoque: ");
            scanf("%d",&RgFarma.QEstoque);
            RgFarma.Ativo = 1; // Define como ativo
            fseek(ArqFarma,0,2);
            fwrite(&RgFarma,Tamanho,1,ArqFarma);
        }

        printf("\nNova inclusao? S/N ");
        scanf(" %c",&R);
        R=toupper(R);
    } while (R!='N');
}

// Função para marcar um medicamento como inativo (exclusão lógica)
void Excluir() {
    TpFARMA RgFarma; // Variável local
    printf("*** exclusao ***\n\n");
    printf("Nome do fármaco a excluir: ");
    char Farmaco[21];
    scanf("%s", Farmaco);

    // Formatando o nome do medicamento
    FormatarNome(Farmaco);

    FILE *ArqTemp = fopen("temp.dat", "w+b"); // Arquivo temporário para escrever os medicamentos ativos
    if (ArqTemp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        return;
    }

    fseek(ArqFarma, 0, SEEK_SET);
    int Achou = 0;
    while (fread(&RgFarma, Tamanho, 1, ArqFarma) == 1) {
        if (strcmp(RgFarma.Nome, Farmaco) == 0 && RgFarma.Ativo) {
            RgFarma.Ativo = 0; // Marca como inativo
            Achou = 1;
        }
        fwrite(&RgFarma, Tamanho, 1, ArqTemp); // Escreve os dados no arquivo temporário
    }

    fclose(ArqFarma);
    fclose(ArqTemp);

    remove("Farmacos.dat"); // Remove o arquivo original
    rename("temp.dat", "Farmacos.dat"); // Renomeia o arquivo temporário para o nome original

    if (Achou) {
        printf("Fármaco excluído com sucesso!\n");
    } else {
        printf("Fármaco não encontrado ou já está excluído.\n");
    }

    ArqFarma = fopen("Farmacos.dat", "a+b"); // Reabre o arquivo principal em modo de adição
}

// Função para consultar os detalhes de um medicamento
void Consultar() {
    TpFARMA RgFarma; // Variável local
    printf("*** consulta ***\n\n");
    printf("Nome do fármaco: ");
    char Farmaco[21];
    scanf("%s", Farmaco);

    // Formatando o nome do medicamento
    FormatarNome(Farmaco);

    fseek(ArqFarma, 0, SEEK_SET);
    int Achou = 0;
    while (fread(&RgFarma, Tamanho, 1, ArqFarma) == 1) {
        if (strcmp(RgFarma.Nome, Farmaco) == 0 && RgFarma.Ativo) {
            printf("Nome: %s\n", RgFarma.Nome);
            printf("Preço: R$%.2f\n", RgFarma.Preco);
            printf("Estoque: %d\n", RgFarma.QEstoque);
            Achou = 1;
            break;
        }
    }

    if (!Achou) {
        printf("Fármaco não encontrado ou já está excluído.\n");
    }
}

// Função para listar todos os medicamentos ativos
void ListarTodos() {
    TpFARMA RgFarma; // Variável local
    printf("*** lista todos ***\n\n");

    fseek(ArqFarma, 0, SEEK_SET);
    while (fread(&RgFarma, Tamanho, 1, ArqFarma) == 1) {
        if (RgFarma.Ativo) { // Verifica se o medicamento está ativo
            printf("Nome: %s\n", RgFarma.Nome);
            printf("Preço: R$%.2f\n", RgFarma.Preco);
            printf("Estoque: %d\n", RgFarma.QEstoque);
            printf("***\n\n");
        }
    }
}

// Função auxiliar para verificar se um medicamento está correto
int VerificarMedicamento(const char *nome) {
    TpFARMA RgFarma; // Variável local

    fseek(ArqFarma, 0, SEEK_SET);
    while (fread(&RgFarma, Tamanho, 1, ArqFarma) == 1) {
        if (strcmp(RgFarma.Nome, nome) == 0 && RgFarma.Ativo) {
            return 1; // Medicamento encontrado e ativo
        }
    }
    return 0; // Medicamento não encontrado ou inativo
}
// Função para atualizar o estoque com base nos medicamentos e quantidades especificados
void AtualizarEstoque(char medicamentos[][21], int quantidades[], int numMedicamentos) {
    TpFARMA RgFarma; // Variável local
    FILE *ArqTemp = fopen("temp.dat", "w+b"); // Arquivo temporário para armazenar os medicamentos atualizados
    if (ArqTemp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        return;
    }

    fseek(ArqFarma, 0, SEEK_SET);
    while (fread(&RgFarma, Tamanho, 1, ArqFarma) == 1) {
        for (int i = 0; i < numMedicamentos; i++) {
            if (strcmp(RgFarma.Nome, medicamentos[i]) == 0 && RgFarma.Ativo) {
                RgFarma.QEstoque += quantidades[i]; // Atualizar o estoque
                break; // Avança para o próximo medicamento
            }
        }
        fwrite(&RgFarma, Tamanho, 1, ArqTemp); // Escreve os dados no arquivo temporário
    }

    fclose(ArqFarma);
    fclose(ArqTemp);

    // Remover o arquivo original
    remove("Farmacos.dat");
    // Renomear o arquivo temporário para o nome original
    rename("temp.dat", "Farmacos.dat");

    printf("Estoque atualizado com sucesso.\n");
}

// Função para comprar a quantidade de fármacos de acordo com os medicamentos escolhidos pelo usuário
void ComprarQuantidade() {
    TpFARMA RgFarma; // Variável local
    printf("*** Comparar Quantidade ***\n\n");
    printf("Quantos medicamentos deseja comprar? ");
    int numMedicamentos;
    scanf("%d", &numMedicamentos);
    char medicamentos[numMedicamentos][21];
    int quantidades[numMedicamentos];

    // Solicitar ao usuário os nomes dos medicamentos e as quantidades desejadas
    for (int i = 0; i < numMedicamentos; i++) {
        do {
            printf("Nome do medicamento %d: ", i + 1);
            scanf("%s", medicamentos[i]);

            // Formatando o nome do medicamento
            FormatarNome(medicamentos[i]);

            if (!VerificarMedicamento(medicamentos[i])) {
                printf("Medicamento não encontrado ou inativo. Por favor, digite novamente.\n");
            }
        } while (!VerificarMedicamento(medicamentos[i]));

        printf("Quantidade desejada: ");
        scanf("%d", &quantidades[i]);
    }

    // Verificar se a quantidade desejada está disponível em estoque
    int faltaEstoque = 0; // Flag para indicar se falta estoque de algum medicamento
    float valorTotal = 0; // Variável para calcular o valor total da compra

    FILE *ArqTemp = fopen("temp.dat", "w+b"); // Arquivo temporário para armazenar os medicamentos atualizados
    if (ArqTemp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        return;
    }

    fseek(ArqFarma, 0, SEEK_SET);
    while (fread(&RgFarma, Tamanho, 1, ArqFarma) == 1) {
        for (int i = 0; i < numMedicamentos; i++) {
            if (strcmp(RgFarma.Nome, medicamentos[i]) == 0 && RgFarma.Ativo) {
                if (RgFarma.QEstoque < quantidades[i]) {
                    faltaEstoque = 1;
                    printf("Alerta: Estoque insuficiente para o medicamento %s\n", medicamentos[i]);
                } else {
                    valorTotal += RgFarma.Preco * quantidades[i];
                    RgFarma.QEstoque -= quantidades[i]; // Atualizar o estoque
                }
                break; // Avança para o próximo medicamento
            }
        }
        fwrite(&RgFarma, Tamanho, 1, ArqTemp); // Escreve os dados no arquivo temporário
    }

    fclose(ArqTemp);

    if (!faltaEstoque) {
        printf("Todos os medicamentos selecionados estão disponíveis em estoque.\n");
        printf("Valor total da compra: R$%.2f\n", valorTotal);

        // Solicitar o valor pago pelo usuário
        float valorPago;
        printf("Informe o valor pago: ");
        scanf("%f", &valorPago);

        // Calcular o troco
        float troco = valorPago - valorTotal;
        if (troco >= 0) {
            printf("Troco: R$%.2f\n", troco);
           totalVendido += valorTotal;
            // Remover o arquivo original
            remove("Farmacos.dat");
            // Renomear o arquivo temporário para o nome original
            rename("temp.dat", "Farmacos.dat");

            printf("Estoque atualizado com sucesso.\n");
        } else {
            printf("Valor pago insuficiente. A compra não pode ser concluída.\n");
        }
    }
}



// Função principal
int main() {
    ArqFarma=fopen("Farmacos.dat","a+b");
    char Opcao;
    do{
        printf("\n\n> > > Pague Pouco < < < \n\n");
        printf("Que deseja fazer? \n\n");
        printf("I - Incluir \n");  
        printf("E - Excluir \n");
        printf("C - Consultar \n");
        printf("T - Listar Todos \n");
        printf("Q - Comprar Quantidade \n");
        printf("U - Atualizar Estoque\n"); // Opção para atualizar o estoque
        printf("S - Sair \n\n");
        scanf(" %c", &Opcao);
        Opcao=toupper(Opcao);
        switch (Opcao){
            case 'I': Incluir(); break; 
            case 'E': Excluir(); break; 
            case 'C': Consultar(); break; 
            case 'T': ListarTodos(); break; 
            case 'Q': ComprarQuantidade(); break;
            case 'U': {
                int numMedicamentos;
                printf("Quantos medicamentos deseja atualizar? ");
                scanf("%d", &numMedicamentos);
                char medicamentos[numMedicamentos][21];
                int quantidades[numMedicamentos];
                for (int i = 0; i < numMedicamentos; i++) {
                    printf("Nome do medicamento %d: ", i + 1);
                    scanf("%s", medicamentos[i]);
                    FormatarNome(medicamentos[i]);
                    printf("Quantidade a adicionar: ");
                    scanf("%d", &quantidades[i]);
                }
                AtualizarEstoque(medicamentos, quantidades, numMedicamentos);
                break;
            }
        } 
    } while (Opcao != 'S');
    printf("Total vendido no dia: R$%.2f\n", totalVendido);
    fclose(ArqFarma);
    return 0;
}
