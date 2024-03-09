#include <stdio.h>

/* (Adaptado do 3o Exercício Resolvido – Cap. 5 – Fund. Da Prog. De Computadores) Faça um programa para ler N números inteiros e positivos e de cada um desses apresente o fatorial. O cálculo do fatorial deve ser efetuado por meio de função elaborada pelo programador. */

// Função para calcular o fatorial de um número
int calcular_fatorial(int num) {
    int fatorial = 1;

    // Loop para calcular o fatorial
    for (int i = 1; i <= num; i++) {
        fatorial *= i;
    }

    return fatorial;
}

int main() {
    int N;

    // Solicita o número de valores a serem lidos
    printf("Quantos números inteiros e positivos deseja inserir? ");
    scanf("%d", &N);

    // Loop para ler e calcular o fatorial de cada número
    for (int ind = 0; ind < N; ind++) {
        int num;
        printf("Digite o número %d: ", ind + 1);
        scanf("%d", &num);

        // Verifica se o número é positivo
        if (num < 0) {
            printf("O número deve ser positivo.\n");
        } else {
            // Calcula o fatorial usando a função personalizada
            int fatorial = calcular_fatorial(num);
           printf("O fatorial de %d é: %d\n", num, fatorial);
        }
    }

    return 0;
}
