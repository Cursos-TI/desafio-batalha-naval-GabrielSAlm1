#include <stdio.h>

// Desafio Batalha Naval - MateCheck

#define LINHAS 10
#define COLUNAS 10

int main() {

  char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
  int tabuleiro [LINHAS][COLUNAS];
  int navio  = 3, tamanho = 3;



  // Criar tabuleiro
  for (int i = 0; i < LINHAS; i++)
  {
    for (int j = 0; j < COLUNAS; j++)
    {
      tabuleiro [i][j] = 0;
    }
  }

  // Navio 1 horizontal
  tabuleiro[0][4] = navio;
  tabuleiro[0][5] = navio;
  tabuleiro[0][6] = navio;
  
  // Navio 2 vertical
  tabuleiro[5][6] = navio;
  tabuleiro[6][6] = navio;
  tabuleiro[7][6] = navio;
  
  // Navio 3 diagonal
  int linha1 = 2;
  int coluna1 = 2;

  for (int i = 0; i < tamanho; i++)
  {
    tabuleiro[linha1 + i][coluna1 + i] = navio;
  }

  // Navio 4 diagonal

  int linha2 = 6;
  int coluna2 = 3;
  
  for (int i = 0; i < tamanho; i++)
  {
    tabuleiro[linha2 + i][coluna2 - i] = navio;
  }
  

  // Visualiazação Tabuleiro
  printf("*** Batalha Naval ***\n");
  printf("   ");
  for (int i = 0; i < LINHAS; i++)
  {
    printf("%c ", letras[i]);
  }
  printf("\n");

  for (int i = 0; i < LINHAS; i++)
  {
    printf("%2d ", i + 1);
    for (int j = 0; j < COLUNAS; j++)
    {
        printf("%d ", tabuleiro[i][j]);
      }
    printf("\n");
  }
  
  return 0;
}
