#include <stdio.h>

/* Na loja de Sr. Zé compras acima de R$300,00 podem ser parceladas em
até 10 vezes, para tanto são aplicados juros simples de 10% ao mês,
conforme o número de meses. Dado valor da compra, exibir o valor total
e o valor das parcelas. Aplicar for e função.

Exemplo:
Compra R$1.000,00
Pagamento em 1 mês – Juros: R$100,00 – Total: R$1.100 – Parcela1 x R$ 1.100,00
Pagamento em 2 meses – Juros: R$100,00 – Total – R$1.200 – Parcela 2 x R$600,00
Pagamento em 3 meses – Juros: R$100,00 – Total – R$1.300 – Parcela 3 x R$433,33
Pagamento em 4 meses – Juros: R$100,00 –Total – R$1.400 – Parcela 4 x R$350,33
...
Pagamento em 10 meses – Juros: R$100,00 –Total – R$2.000 – Parcela 10 x R$200,00 */


float calculaJuros(float valor, int meses) {
    return valor * 0.10 * meses;
}

float calculaTotal(float valor_compra, float juros) {
    return valor_compra + juros;
}

float calculaParcela(float total, int meses) {
    return total / meses;
}

int main() {
    float valorCompra;
    int meses;

    printf("Digite o valor da compra: ");
    scanf("%f", &valorCompra);

    printf("Compra R$%.2f\n", valorCompra);
 if (valorCompra > 300){ 
    for (meses = 1; meses <= 10; meses++) {
        float juros = calculaJuros(valorCompra, meses);
        float total = calculaTotal(valorCompra, juros);
        float parcela = calculaParcela(total, meses);
        printf("Pagamento em %d mes(es) - Juros: R$%.2f - Total: R$%.2f - Parcela %d x R$%.2f\n", 
                meses, juros, total, meses, parcela);
    }
 } else {
    printf("A parcela só está disponivel para valores acima de R$300,00.\n");
 }
    return 0;
}