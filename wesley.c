#include <stdio.h>

int somatorio(int num) {
  if (num <= 0)
    return 0;

  return num + somatorio(num - 1);
}

void wesley_safadao(float dia, float mes, float ano) {
  double safadeza = somatorio(mes) + (double)(ano / 100.0) * (50 - dia);
  printf("Sou %.2f%% anjo, mas aqueles %.2f%% é vagabundo\n", 100 - safadeza,
         safadeza);
}

int main(int argc, char const *argv[]) {
  /* code */
  float dia, mes, ano;
  scanf("%f %f %f", &dia, &mes, &ano);
  wesley_safadao(dia, mes, ano);
  return 0;
}
