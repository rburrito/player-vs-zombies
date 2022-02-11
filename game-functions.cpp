#include <ctime>
#include <cstdlib>

void GameObject::setRow(int newRow){
  row_ = newRow;
}

void GameObject::setColumn(int newColumn){
  column_ = newColumn;
}

void GameObject::setDisplayChar(char letter){
  displayChar_ = letter;
}

void Map::setMap(){
  for (int i=0; i < 10; i++){
    for (int j=0; j < 10; j++){
      gameArray[i][j] = nullptr;
    }
  }
}

void Map::place(GameObject *go){
  int randomRow = rand() % 10;
  int randomColumn = rand() % 10;

  if (gameArray[randomRow][randomColumn]==nullptr){
    gameArray[randomRow][randomColumn] = go;
    go -> setRow(randomRow);
    go -> setColumn(randomColumn);
  } else {
    place(go);
  }

}

void Map::draw(){

  for (int i=0; i < 10; i++){
    for (int j=0; j < 10; j++){
      if (gameArray[i][j] == nullptr){
        cout << '.';
      } else {
        cout << gameArray[i][j]-> getDisplayChar();
      }
    }
    cout << endl;
  }

}

char Map::getSpaceInfo(int row, int column){
  char objectType;

  if (row < 0 || row > 9 || column < 0 || column > 9){
    objectType = 'O';
  } else if (gameArray[row][column] == nullptr){
    objectType = 'N';
  } else {
    objectType = gameArray[row][column] -> getDisplayChar();
  }

  return objectType;
}

bool Map::setPlayerStatus(char objectType){
  bool gameStatus = false;

  if (objectType == 'Z'){
    cout << "You lose!" << endl;
    gameStatus = true;
  } else if (objectType == 'G'){
    cout << "You win!" << endl;
    gameStatus = true;
  } else if (objectType == 'O'){
    cout << "You hit a wall." << endl;
  }

  return gameStatus;
}

void Map::setNewSpace(GameObject* go, int row, int column){
  gameArray[row][column]=go;

  go -> setRow(row);
  go -> setColumn(column);
}

bool Map::movePlayer(char direction){
  bool gameStatus;

  int row = player -> getRow();
  int column = player -> getColumn();
  int objectType;

  switch (direction){
    case 'n':
      objectType = getSpaceInfo(row-1, column);
      gameStatus = setPlayerStatus(objectType);
      if (objectType == 'N'){
        gameArray[row][column]= nullptr;
        setNewSpace(player, row-1, column);
      }
      break;
    case 's':
      objectType = getSpaceInfo(row+1, column);
      gameStatus = setPlayerStatus(objectType);
      if (objectType == 'N'){
        gameArray[row][column]= nullptr;
        setNewSpace(player, row+1, column);
      }
      break;
    case 'e':
      objectType = getSpaceInfo(row, column+1);
      gameStatus = setPlayerStatus(objectType);
      if (objectType == 'N'){
        gameArray[row][column]= nullptr;
        setNewSpace(player, row, column+1);
      }
      break;
    case 'w':
      objectType = getSpaceInfo(row, column-1);
      gameStatus = setPlayerStatus(objectType);
      if (objectType == 'N'){
        gameArray[row][column]= nullptr;
        setNewSpace(player, row, column-1);
      }
      break;
  }

  return gameStatus;
}

bool Map::setZombieStatus(char objectType){
  bool gameStatus = false;

  if (objectType == 'P'){
    cout << "You lose!" << endl;
    gameStatus = true;
  }

  return gameStatus;
}

bool Map::moveZombies(GameObject* go){
  int gameStatus = false;
  int row = go -> getRow();
  int column = go -> getColumn();

    int randomDirection = (rand() % 4)+1;

    // objectType: O=out-of-bounds; N=nullptr, P=player, Z=zombie, G=goal
    int objectType;

    switch (randomDirection){
       case 1: // north
        objectType = getSpaceInfo(row-1, column);
        gameStatus = setZombieStatus(objectType);
        if (objectType == 'N'){
          gameArray[row][column]= nullptr;
          setNewSpace(go, row-1, column);
        }
        break;
      case 2: // south
         objectType = getSpaceInfo(row+1, column);
         gameStatus = setZombieStatus(objectType);
         if (objectType == 'N'){
           gameArray[row][column]= nullptr;
           setNewSpace(go, row+1, column);
         }
         break;
      case 3: // east
        objectType = getSpaceInfo(row, column+1);
        gameStatus = setZombieStatus(objectType);
        if (objectType == 'N'){
         gameArray[row][column]= nullptr;
         setNewSpace(go, row, column+1);
        }
        break;
      case 4: // west
        objectType = getSpaceInfo(row, column-1);
        gameStatus = setZombieStatus(objectType);
        if (objectType == 'N'){
          gameArray[row][column]= nullptr;
          setNewSpace(go, row, column-1);
        }
        break;
     }

   return gameStatus;
}
