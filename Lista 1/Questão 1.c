#include <stdio.h>

int main() {
  int a;
  printf("Me diga um numero :");
  scanf("%d\n", &a);
  printf("O numero antecessor e o sucessor , respectivamente são: %d %d\n",
         a - 1, a + 1);
  return 0;
}
