#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <locale.h>

void bubbleSort(char (*V)[30], int Fim)
{
  int i, j;
  char temp[30];

  for (i = 0; i < Fim; i++)
  {
    for (j = 0; j < Fim - 1 - i; j++)
    {
      if (strcmp(V[j], V[j + 1]) > 0)
      {
        strcpy(temp, V[j]);
        strcpy(V[j], V[j + 1]);
        strcpy(V[j + 1], temp);
      }
    }
  }
}

int main()
{
  setlocale(LC_ALL, "PORTUGUESE");
  int Fim = 0, i = 0;

  printf("\n nome de quantas pessoas ? ");
  scanf("%i", &Fim);
  char V[Fim][30];

  for (i = 0; i < Fim; i++)
  {
    printf("\n   Digite o nome da %iº : ", i + 1);
    scanf("%s", V[i]);
  }
  system("cls");

  printf("ordem alfabetica");
  for (i = 0; i < Fim; i++)
  {
    bubbleSort(V, Fim);
    printf("\n %s", V[i]);
  }

  return 0;
}