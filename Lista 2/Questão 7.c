#include <stdio.h>

/* 7.Escrever um programa em C sobre investimento. Deve ser efetuada a
leitura do valor inicial investido, do valor investido mensalmente e do tempo
de investimento (desconsiderar juros) e retornar o valor final (montante) e o
valor do rendimento (montante – valor inicial investido). Deve ser aplicado
um módulo(função) com dois parâmetros de saída.*/


// rendimento e montate sendo definidos como ponteiros ou seja armazenamento de endereços de memoria, atraves do uso do '*' .

float calcularInvestimento(float valorInicial, float valorMensal, int tempo, float *montante, float *rendimento) {
    *montante = valorInicial + (valorMensal * tempo);
    *rendimento = *montante - valorInicial;
    return *montante;
    return *rendimento;
  
} // Na função acima, *montante e *rendimento são usados para acessar os valores apontados pelos ponteiros montante e rendimento, permitindo a atribuição dos resultados diretamente às variáveis na função.

int main() {
  
  float valorInicial, valorMensal, tempo;
  float montanteResultado, rendimentoResultado;

  printf("Digite o valor inicial investido: ");
    scanf("%f", &valorInicial);
  printf("Digite o valor mensal investido: ");
    scanf("%f", &valorMensal);
  printf("Digite o tempo de investimento: ");
    scanf("%f", &tempo);

 
calcularInvestimento(valorInicial, valorMensal, tempo, &montanteResultado, &rendimentoResultado);
  
// Ao chamar a função 'calcularIvestimento', os endereços de memória (&montanteResultado e &rendimentoResultado) são passados como argumentos. Dessa forma, a função atualiza diretamente as variáveis na função usando os ponteiros.
  
  printf("O valor do montante é %.2f e o rendimento é de %.2f", montanteResultado, rendimentoResultado);

  return 0;
}