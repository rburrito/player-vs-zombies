#include <iostream>
using namespace std;
#include "classes.h"

int main(){
  
  // Mapping gameboard
  Map gameboard;

  // sets map to nullptrs
  gameboard.setMap();

  srand(time(NULL));

  // places game objects in respective spots
  gameboard.place(gameboard.getPlayer());
  gameboard.place(gameboard.getZombie1());
  gameboard.place(gameboard.getZombie2());
  gameboard.place(gameboard.getZombie3());
  gameboard.place(gameboard.getZombie4());
  gameboard.place(gameboard.getZombie5());
  gameboard.place(gameboard.getGoal());

  // sets display character of corresponding game object
  gameboard.getPlayer() -> setDisplayChar('P');
  gameboard.getZombie1() -> setDisplayChar('Z');
  gameboard.getZombie2() -> setDisplayChar('Z');
  gameboard.getZombie3() -> setDisplayChar('Z');
  gameboard.getZombie4() -> setDisplayChar('Z');
  gameboard.getZombie5() -> setDisplayChar('Z');
  gameboard.getGoal() -> setDisplayChar('G');

  // draws current game board
  gameboard.draw();

  char direction;
  bool gameOver;

  while (true){
    cout << "Enter direction (n, s, e, w): ";
    cin >> direction;
    cout << endl;

    // moves player and returns game status
    gameOver = gameboard.movePlayer(direction);
    if (gameOver){
      break;
    }

    // moves zombies and returns game status
    gameOver = gameboard.moveZombies(gameboard.getZombie1());
    if (gameOver){
      break;
    }

    gameOver = gameboard.moveZombies(gameboard.getZombie2());
    if (gameOver){
      break;
    }

    gameOver = gameboard.moveZombies(gameboard.getZombie3());
    if (gameOver){
      break;
    }

    gameOver = gameboard.moveZombies(gameboard.getZombie4());
    if (gameOver){
      break;
    }

    gameOver = gameboard.moveZombies(gameboard.getZombie5());
    if (gameOver){
      break;
    }

    // draws gameboard after all pieces have moved 
    gameboard.draw();
  }

  return 0;
}
