#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

int main() {
  int MAXJogadores = 10;
  int quantidadeJogadores;
  char nomesJogadores[MAXJogadores][50];

  printf("Bem ao jogo de Truco!\n");
  
  printf("Digite a quantidade de jogadores de 1 a 10: ");
  scanf("%d", &quantidadeJogadores);
  if(quantidadeJogadores > MAXJogadores || quantidadeJogadores < 1){
    printf("\nQuantidade de jogadores inválida!\n");
    return 0;
  }
  
  printf("\nDigite o nome dos jogadores:\n");
  for(int i = 0; i < quantidadeJogadores; i++)
    scanf(" %[^\n]s", nomesJogadores[i]);
  
  int cartasJogadores[quantidadeJogadores][7];
  bool cartasJogadas[quantidadeJogadores][7];

  srand(time(NULL));

  for (int i = 0; i < 7; i++) {
    for(int j = 0; j < quantidadeJogadores; j++){
    cartasJogadores[j][i] = rand() % 13 + 1;
    }
  }

  int escolhaJogadores[quantidadeJogadores];
  int maiorCarta = 0;
  char nomeVencedor[50];
  int rodada = 1;
  int pontosJogadores[quantidadeJogadores];
  bool maiorCartaJogadores[quantidadeJogadores];
  int countEmpate = 0;
  for(int i=0; i<quantidadeJogadores; i++)
    pontosJogadores[i] = 0;
  for(int i = 0; i < quantidadeJogadores; i++){
    for(int j = 0; j < 7; j++)
    cartasJogadas[i][j] = false;
  }

  //INICIO DO LOOP

  do {
    maiorCarta = 0;
    countEmpate = 0;
    for(int i = 0; i < quantidadeJogadores; i++){
      maiorCartaJogadores[i] = false;
    }
    

  //Escolha das cartas
  printf("\n----------------------------------------\nRodada %d\n", rodada);
  for (int i = 0; i < quantidadeJogadores; i++){
    while(1){
      printf("O jogador %s faça sua escolha: ", nomesJogadores[i]);
      scanf("%d", &escolhaJogadores[i]);
      if(cartasJogadas[i][escolhaJogadores[i]] == true){
        printf("Essa carta já foi escolhida, escolha outra!\n");
      }
      if(escolhaJogadores[i] > 7 || escolhaJogadores[i] < 1 || cartasJogadas[i][escolhaJogadores[i]] == true){
        printf("\nEscolha inválida!\n");
        continue;
      }
      else break;
      
    }
  }

  //Carta maior
  for(int i = 0; i < quantidadeJogadores; i++){
    if(cartasJogadores[i][escolhaJogadores[i]] > maiorCarta){
      maiorCarta = cartasJogadores[i][escolhaJogadores[i]];
      strcpy(nomeVencedor, nomesJogadores[i]);
    }
    cartasJogadas[i][escolhaJogadores[i]] = true;
    printf("\nO carta do jogador %s é %d", nomesJogadores[i], 
      cartasJogadores[i][escolhaJogadores[i]]);
  }

  //Pontuação
  for(int i = 0; i < quantidadeJogadores; i++){
    if(cartasJogadores[i][escolhaJogadores[i]] == maiorCarta){
      pontosJogadores[i] += 3;
      maiorCartaJogadores[i] = true;
      countEmpate++;
    }
  }

  //Verificação empate
    if(countEmpate >= 2)
      for(int i = 0; i < quantidadeJogadores; i++){
        if(maiorCartaJogadores[i])
          pontosJogadores[i] -= 2;
      }

  //Imprime resultado
  printf("\n\nO vencedor é %s pela maior carta %d\n\nPontuações:", nomeVencedor, maiorCarta);
  for(int i =0; i < quantidadeJogadores; i++)
    printf("\nPontuação Jogador %s é %d",nomesJogadores[i] ,pontosJogadores[i]);
  printf("\n");

  //Jogador vencedor
  for(int i = 0; i < quantidadeJogadores; i++){
    if(pontosJogadores[i] >= 15){
      printf("\nO jogador %s venceu o jogo!", nomesJogadores[i]);
      return 0;
    }
  }
    
  rodada++;
  } while(1);
  
  return 0;
}
