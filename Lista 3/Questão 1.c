#include <stdio.h>

/*Os colegas do filho de Sr. Zé estão sentindo dificuldade para alugar um ônibus para levá-los ao “Museu da Gente Sergipana”. Então Sr. Zé resolveu disponibilizar sua Kombi,mas a depender do número de inscritos, serão necessárias muitas viagens, e alguns passageiros deverão ir de coletivo.Considerando que a Kombi tem capacidade para transportar 11 pessoas (fora o motorista – Sr. Zé), escrever um programa em C, para, dado o número de inscritos no passeio ao Museu, exibir o número de viagens que devem ser necessárias e o número de passagens de coletivo. Exemplos: se 22 pessoas – 2 viagens de kombi e 0 passagem em coletivo; se 37 pessoas – 3 viagens e 4 passagens em coletivo. Vale esclarecer que se o número de passageiros for inferior a 11, Sr. Zé os levará de Kombi.*/

int main() {
  
int numInscritos, viagensKombi, passagensColetivo;

  printf("Digite o número de inscritos: ");
  scanf("%d", &numInscritos);

if (numInscritos <= 11) {
  
   viagensKombi = 1;
   passagensColetivo = 0;
  
} else {
  
  viagensKombi = numInscritos / 11;
  int resto = numInscritos % 11;

if (resto > 0) {
  
  passagensColetivo = resto;
  
} else {
  
  passagensColetivo = 0;
  
    }
 }
  
  printf("Número de viagens de Kombi: %d\n", viagensKombi);
  printf("Número de passagens de coletivo: %d\n", passagensColetivo);

return 0;  
}
