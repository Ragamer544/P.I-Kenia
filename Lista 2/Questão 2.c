#include <stdio.h>
#include <math.h>

/* 2- No pré-escolar “Balão Mágico” o número máximo de alunos de uma
  turma é definido anualmente, após as reformas de fim de ano e
  evolução curricular. Escrever programa em C onde se lê o número
  total de alunos matriculados, o número máximo de alunos por
  turma e exibir o número de turmas a serem formadas. */

float funcao (float numerador , float denominador ){

  float funcao1 =  ceil (numerador/denominador);

  return funcao1;
}

int main () {

 float alunos , alunosPorSala;
  printf ("Digite a quantidade de alunos: ");
  scanf  ("%f" , &alunos);
  printf ("Digite a quantidade de alunos por sala: ");
  scanf  ("%f" , &alunosPorSala);
  printf ("A quantidade de turmas será %f" , funcao (alunos , alunosPorSala));
  
}