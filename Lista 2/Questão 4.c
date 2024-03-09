#include <math.h>
#include <stdio.h>

/* 4. Escrever um programa em C para ler uma temperatura em Celsius C e
a retornar em Fahrenheit e em Kelvin. Fórmulas de conversão para
Fahrenheit: F = (C * 9/5) + 32; para Kelvin: K = C + 273,5.
Criar uma função para cada conversão.*/

float celsiusParaFahrenheit(float celsius) {

  float conversorCPF = (celsius * 9 / 5) + 32;

  return conversorCPF;
}

float celsiusParaKelvin(float celsius) {

  float conversorCPK = celsius + 273.5;

  return conversorCPK;
}

int main() {

  float celsius;
  printf("Digite a temperatura em Celsius: ");
  scanf("%f", &celsius);
  printf("A temperatura em Fahrenheit é: %.0f graus fahrenheint \n",
         celsiusParaFahrenheit(celsius));
  printf("A temperatura em Kelvin é : %.0f graus kelvins",
         celsiusParaKelvin(celsius));
  return 0;
}