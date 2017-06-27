/*----------------------------------------------------------------
|   Author: Christian Callau Romero
|   e-mail: id.32@outlook.com
|   Date: July 2017                 Version: 2.0
|-----------------------------------------------------------------|
|	Project name: BattleShip
|	Name: main.c
|   File description:   Main.
| ----------------------------------------------------------------*/

#include "types.h"
#include "functions.h"

int main() {

  srand((unsigned)time(NULL));
  system("color 1f");

  Game_t game;
  Scores_t scores;

  game.game = false;
  bool exit = false;

  if (!load_scores(&scores)) {
    scores.num = 0;
  }

  while (!exit) {
    switch (main_menu(game.game)) {
    case 1:
      new_game(&game);
      break;
    case 2:
      system("cls");
      if (load_game(&game)) printf("\n  Game loaded!\n");
      else printf("\n  No game was found.\n");
      pause();
      break;
    case 3:
      play_game(&game, &scores);
      break;
    case 4:
      system("cls");
      if (save_game(game)) printf("\n  Game saved!\n");
      else printf("\n  Error while saving the game.\n");
      pause();
      break;
    case 5:
      scoreboard(scores);
      break;
    case 6:
      exit = true;
      break;
    default:
      break;
    }
  }

  return 0;
}