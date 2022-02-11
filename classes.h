class GameObject {
private:
    int row_;
    int column_;
    char displayChar_;

public:
    int getRow() { return row_;};
    int getColumn() { return column_;};
    char getDisplayChar() { return displayChar_;};
    void setRow(int newRow);
    void setColumn(int newColumn);
    void setDisplayChar(char letter);
};

class Map {
private:
    GameObject* gameArray[10][10];
    GameObject* player = new GameObject;
    GameObject* z1 = new GameObject;
    GameObject* z2 = new GameObject;
    GameObject* z3 = new GameObject;
    GameObject* z4 = new GameObject;
    GameObject* z5 = new GameObject;
    GameObject* goal = new GameObject;

public:
    void setMap();
    void place(GameObject *go);
    void draw();
    bool movePlayer(char direction);
    bool moveZombies(GameObject *go);
    char getSpaceInfo(int row, int column);
    bool setPlayerStatus(char objectType);
    bool setZombieStatus(char objectType);
    void setNewSpace(GameObject* go, int row, int column);
    GameObject* getPlayer(){ return player;};
    GameObject* getZombie1(){ return z1;};
    GameObject* getZombie2(){ return z2;};
    GameObject* getZombie3(){ return z3;};
    GameObject* getZombie4(){ return z4;};
    GameObject* getZombie5(){ return z5;};
    GameObject* getGoal(){ return goal;};
};
