#include <stdio.h>

/* Maria está fazendo a “Dieta de Saturno” para emagrecimento e a previsão é de
 * que a perda de peso seja de 5 kg mensais. Ajustar programa em C para ler o
 * peso inicial e o peso almejado, exibir o peso alcançado (em teoria) a cada
 * mês, conforme o que prevê a dieta, e corrigir os erros que ocorrem quando o
 * peso almejado não é múltiplo de 5, bem como quando o peso inicial é menor que
 * o peso almejado. Aplicar for.*/

int main() {
    float peso_inicial, peso_almejado;
    int mes;
  
    // Ler o peso inicial e o peso almejado
    printf("Digite o peso inicial (em kg): ");
    scanf("%f", &peso_inicial);
    printf("Digite o peso almejado: ");
    scanf("%f", &peso_almejado);

  // Verificar se o peso inicial é menor que o peso almejado
  if (peso_inicial < peso_almejado) {
      printf("Erro: O peso inicial deve ser maior ou igual ao peso almejado.\n");
      return 0; 
  }
  
    // Calcular e exibir o progresso da dieta
    printf("\nProgresso da Dieta de Saturno:\n");
    for (mes = 0; peso_inicial >= peso_almejado; mes++) {
        printf("Peso no mês %d: %.1f kg\n", mes, peso_inicial);
        peso_inicial -= 5; // Perda de peso de 5 kg por mês
    }

    if (peso_almejado > 0 && ((int) peso_almejado %  5 ) > 0)
    // Exibir peso almejado alcançado
    printf("Peso no mês (imcompleto) %d: %.1f kg\n", mes , peso_almejado);
    
    return 0;
}

