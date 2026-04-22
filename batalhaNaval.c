#include <stdio.h>

// Desafio Batalha Naval - MateCheck

int main() {

  char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
  int tabuleiro [10][10];
  int navio  = 3;


  // Criar tabuleiro
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      tabuleiro [i][j] = 0;
    }
  }

  // Navio 1
  tabuleiro[0][4] = navio;
  tabuleiro[0][5] = navio;
  tabuleiro[0][6] = navio;
  
  // Navio 2
  tabuleiro[5][6] = navio;
  tabuleiro[6][6] = navio;
  tabuleiro[7][6] = navio;


  // Visualiazação Tabuleiro
  printf("*** Batalha Naval ***\n");
  printf("   ");
  for (int i = 0; i < 10; i++)
  {
    printf("%c ", letras[i]);
  }
  printf("\n");

  for (int i = 0; i < 10; i++)
  {
    printf("%2d ", i + 1);
    for (int j = 0; j < 10; j++)
    {
      printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
