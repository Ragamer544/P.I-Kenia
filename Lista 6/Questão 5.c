#include <stdio.h>

/* Na universidade “DuSabiTudu” os alunos são identificados por
matrículas compostas por 10 dígitos. Os 4 primeiros dígitos
correspondem ao ano em que o aluno entrou na instituição.
Assim, todos os alunos cujas matriculas iniciam por 2012
ingressaram no curso superior no ano de 2012. Os dígitos 5 e 6 da
matrícula correspondem ao curso; sendo: 97 para agroecologia e
99 para gerontologia. Escrever programa para ler a matricula de
100 alunos inscritos no programa “CienciasAlémDasFronteiras” e
identificar quantos alunos ingressaram num dado ano A no curso
de gerontologia. Aplicar função definida pelo programador. */

// Função para verificar se uma matrícula corresponde ao ano especificado e ao curso de gerontologia
int verificarMatricula(char matricula[], int ano) {
    // Extrai os dígitos relevantes da matrícula
    int anoMatricula = (matricula[0] - '0') * 1000 + (matricula[1] - '0') * 100 + (matricula[2] - '0') * 10 + (matricula[3] - '0');
    int curso = (matricula[4] - '0') * 10 + (matricula[5] - '0');

    // Verifica se a matrícula corresponde ao ano especificado e ao curso de gerontologia (99)
    if (anoMatricula == ano && curso == 99) {
        return 1; // Matrícula válida
    } else {
        return 0; // Matrícula inválida
    }
}

int main() {
    char matricula[11]; // Armazena a matrícula do aluno
    int ano;
    int alunosGerontologia = 0; // Inicializa o contador de alunos de gerontologia

    // Solicita ao usuário que insira o ano desejado
    printf("Digite o ano desejado: ");
    scanf("%d", &ano);

    // Solicita ao usuário que insira as matrículas dos alunos
    printf("Digite as matriculas dos 100 alunos:\n");
    for (int i = 0; i < 100; i++) {
        printf("Matricula do aluno %d: ", i + 1);
        scanf("%s", matricula);

        // Verifica se a matrícula corresponde ao ano especificado e ao curso de gerontologia
        if (verificarMatricula(matricula, ano)) {
            alunosGerontologia++; // Incrementa o contador de alunos de gerontologia
        }
    }

    // Exibe o resultado
    printf("O número de alunos que ingressaram no ano %d no curso de gerontologia é: %d\n", ano, alunosGerontologia);

    return 0;
}
