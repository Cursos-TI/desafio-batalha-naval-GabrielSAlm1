#include <stdio.h>

// Desafio Batalha Naval - MateCheck

#define LINHA 10
#define COLUNA 10
#define TAM_HAB 5 // Tamanho matriz habilidade 5x5

int main() {

  char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
  int tabuleiro [LINHA][COLUNA];
  int navio  = 3;

  // Criar tabuleiro
  for (int i = 0; i < LINHA; i++)
  {
    for (int j = 0; j < COLUNA; j++)
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

  // As duas diagonais preenchidas
  // for (int i = 0; i < 10; i++)
  // {
  //   for (int j = 0; j < 10; j++)
  //   {
  //     if (i == j || i + j == 9)
  //     {
  //       tabuleiro[i][j] = navio;
  //     }
      
  //   }
    
  // }

  // Navios na diagonal
  for (int i = 0; i < 3; i++) // [i < 3 = tamanho do navio]
  {
    tabuleiro[2 + i][2 + i] = navio; // [2 + i = posição do navio]
    for (int j = 0; j < 3; j++) // [j < 3 = tamanho do navio]
    {
      tabuleiro[6 + j][3 - j] = navio; // [6 + j = posição do navio linha] [3 - j = posição do navio coluna]
    }
    
  }

  // Criando a matriz das habilidades
  // 0 = agua 
  // 1 = área afetada
  int cone[TAM_HAB][TAM_HAB] = {0};
  int cruz[TAM_HAB][TAM_HAB] = {0};
  int octaedro[TAM_HAB][TAM_HAB] = {0};  

  // Matriz cone
  for (int i = 0; i < TAM_HAB; i++) {
    for (int j = 0; j < TAM_HAB; j++)
    {
      if (i == 0 && j == 2) cone[i][j] = 1;
      if (i == 1 && j >= 1 && j <= 3) cone[i][j] = 1;
      if (i == 2) cone[i][j] = 1;
    }    
  }

  // Matriz cruz
  for (int i = 0; i < TAM_HAB; i++) {
    for (int j = 0; j < TAM_HAB; j++) {
      if (i == 2 || j == 2) cruz[i][j] = 1;
    }
  }

  // Criando a matriz OCTAEDRO (Losango)
  for(int i = 0; i < TAM_HAB; i++) {
    for(int j = 0; j < TAM_HAB; j++) {
      if((i == 2 && j >= 1 && j <= 3) || (j == 2 && i >= 1 && i <= 3)) octaedro[i][j] = 1;
    }
  }

  

  int origemConeLinha = 2, origemConeColuna = 2;
  int origemCruzLinha = 6, origemCruzColuna = 5;
  int origemOctaedroLinha = 1, origemOctaColuna = 8;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++)
    {
      // Cone
      int l = origemConeLinha + i - 2, c = origemConeColuna + j - 2;
      // Quando i = 0 (topo do molde), a linha no tabuleiro será: 2 + 0 - 2 = 0
      // Quando i = 2 (meio do molde), a linha no tabuleiro será: 2 + 2 - 2 = 2
      // Quando i = 4 (fim do molde), a linha no tabuleiro será: 2 + 4 - 2 = 4

      if(l >= 0 && l < LINHA && c >= 0 && c < COLUNA && cone[i][j] == 1) tabuleiro[l][c] = 5;
      // l >= 0 && l < LINHA A linha calculada existe no tabuleiro? (Não é negativa nem maior que 9?)
      // c >= 0 && c < COLUNA: A coluna calculada existe no tabuleiro?
      // cone[i][j] == 1: No meu carimbo de molde, esse quadradinho está "pintado"?

      // Cruz
      l = origemCruzLinha + i - 2, c = origemCruzColuna + j - 2;
      if(l >= 0 && l < LINHA && c >= 0 && c < COLUNA && cruz[i][j] == 1) tabuleiro[l][c] = 5;

      // Octaedro
      l = origemOctaedroLinha + i - 2, c = origemOctaColuna + j - 2;
      if(l >= 0 && l < LINHA && c >= 0 && c < COLUNA && octaedro[i][j] == 1) tabuleiro[l][c] = 5;
    }
  }
    


  // Visualiazação Tabuleiro
  printf("*** Batalha Naval ***\n");
  printf("\n");
  printf("   ");
  for (int i = 0; i < LINHA; i++)
  {
    printf("%c ", letras[i]);
  }
  printf("\n");

  for (int i = 0; i < LINHA; i++)
  {
    printf("%2d ", i + 1);
    for (int j = 0; j < COLUNA; j++)
    {
      printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
