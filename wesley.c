#include <stdio.h>
#include <math.h>

short int somatorio(short int num) {
  if (num <= 0)
    return 0;

  return num + somatorio(num - 1);
}

void dataGenerator(short int *dia, short int *mes, short int *ano) {
  switch (*mes) {
  case 2:
    (*dia)++;
    if (((*ano % 4 == 0 && *ano % 100 != 0) || *ano % 400 == 0) &&
        (*dia > 29)) {
      *dia -= 29;
      (*mes)++;
    } else if (*dia > 28) {
      *dia -= 28;
      (*mes)++;
    }
  case 4:
  case 6:
  case 9:
  case 11:
    (*dia)++;
    if (*dia > 30) {
      *dia -= 30;
      (*mes)++;
    }
    break;
  default:
    (*dia)++;
    if (*dia > 31) {
      *dia -= 31;
      (*mes)++;
    }
    if (*mes > 12) {
      (*mes) -= 12;
      (*ano)++;
    }
    break;
  }
}

void wesley_safadao(short int dia, short int mes, short int ano) {
  double safadeza = fmod(somatorio(mes) + (ano / 100.0) * (50 - dia), 100);
  printf("Data: %d/%d/%d - \t", dia, mes, ano);
  printf("sou %.1f%% anjo, mas aqueles %.1f%% é vagabundo\n", 100 - safadeza,
         safadeza);
}

int main(int argc, char const *argv[]) {
  /* code */
  short int dia = 1, mes = 1, ano = 1900;
  while (ano < 2100) {
    wesley_safadao(dia, mes, ano);
    dataGenerator(&dia, &mes, &ano);
  }
  return 0;
}
