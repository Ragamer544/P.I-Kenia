#include <stdio.h>

/* Na disciplina “Programação Imperativa” há 50 alunos e 12 avaliações. Para obtenção de aprovação o aluno deve ter no mínimo 5 notas maior ou igual a 7. Escrever programa para ler notas de cada um dos 50 alunos e identificar se foi aprovado.*/


int main() {
    int alunos_aprovados = 0;

    // Loop para cada aluno
    for (int aluno = 1; aluno <= 50; aluno++) {
        int notas_acima_de_sete = 0;

        // Loop para cada avaliação
        for (int avaliacao = 1; avaliacao <= 12; avaliacao++) {
            float nota;
            printf("Digite a nota do aluno %d na avaliação %d: ", aluno, avaliacao);
            scanf("%f", &nota);

            if (nota >= 7.0) {
                notas_acima_de_sete++;
            }
        }

        // Verifica se o aluno foi aprovado
        if (notas_acima_de_sete >= 5) {
            printf("O aluno %d foi aprovado!\n", aluno);
            alunos_aprovados++;
        } else {
            printf("O aluno %d foi reprovado.\n", aluno);
        }
    }

    printf("\nTotal de alunos aprovados: %d\n", alunos_aprovados);

    return 0;
}
