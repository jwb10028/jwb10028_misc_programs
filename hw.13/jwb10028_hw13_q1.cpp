#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int WorldSize = 20;
const int init_ant_amount = 100;
const int init_bugs_amount = 5;
const int bugID = 1;
const int antID = 2;
const int ant_breed_time = 3;
const int doodle_breed_time = 8;
const int doodle_starve_time = 3;
const char ant_char = 'o';
const char doodle_char = 'x';
class Organism;

//World Class:
class World {
    //Declaring friend classes:
    friend class Organism;
    friend class Doodlebug;
    friend class Ant;
public:
    //Constructor:
    World();
    
    //Destructor:
    ~World();

    //get an organism's organismCoordArr position:
    Organism* getPos(int x, int y);

    //set an organism's organismCoordArr position:
    void setPos(int x, int y, Organism* input_organism);

    //displayFrame worldview
    void displayFrame();

    //simulate one time step:
    void simulateFrame();


private:
    Organism* worldCoord[WorldSize][WorldSize];
};
//Organism Class:
class Organism {
    //declaring friend classes
    friend class World;
public:
    //declaring default constructor:
    Organism();

    //declaring parameterized constructor:
    Organism(World* organismCoordArr, int x, int y);

    //declaring destructor:
    ~Organism();

    //Pure Virtual Functions:
    //declaration of breed function:
    virtual void breed() = 0;

    //declaration of move function:
    virtual void move() = 0;

    //declaration of starved function:
    virtual bool starved() = 0;

    //declaration of getType:
    virtual int getType() = 0;
protected:
    //declaration of organism member variables/protected so that derived class member functions are able to access
    int x, y;
    bool moved;
    int breedCount;
    World* organismCoordArr;
};
//Ant Class:
class Ant : public Organism {
    friend class World;
public:
    //declaring default constructor:
    Ant();

    //decalring parameterized constructor:
    Ant(World* organismCoordArr, int x, int y);

    //delcairng breed function:
    void breed();

    //declaring move function:
    void move();

    //declaring getType function:
    int getType();

    //declaring starved function:
    bool starved(){return false;}

};
//Doodlebug Class:
class Doodlebug : public Organism {
    friend class World;
public:
    //default constructor:
    Doodlebug();

    //default parameterized constructor:
    Doodlebug(World* organismCoordArr, int x, int y);

    //breed function:
    void breed();

    //move function:
    void move();

    //getType function:
    int getType();

    //starved function:
    bool starved();
private:
    int starveCount;
};

//extra helper functions:
void seedAnts(World& input_board);
void seedDoodles(World& input_board);

int main(){
    string input_string; int frameCount = 0;
    srand(time(NULL));
    World init_board;
    seedDoodles(init_board);
    seedAnts(init_board);
    
    while (true){
        cout << "World frame: " << frameCount;
        
        init_board.displayFrame();
        init_board.simulateFrame();


        cout << endl << "Press enter to step forward in time one frame: " << endl;
        getline(cin, input_string);
        frameCount++;
    }   
    return 0;
}

/*World Functions*/
//default constructor:
World::World(){
    int i, j;
    for (i = 0; i < WorldSize; i++){
        for (j = 0; j < WorldSize; j++){
            worldCoord[i][j] = NULL;
        }
    }
}
//default destructor:
World::~World(){
    int i, j;
    for (i = 0; i < WorldSize; i++){
        for (j = 0; j < WorldSize; j++){
            if (worldCoord[i][j] != NULL){
                delete (worldCoord[i][j]);
            }
        }
    }
}
//get an organism's position:
Organism* World::getPos(int x, int y){
    int bound1 = 0; int bound2 = WorldSize;
    //if in frame return x,y coordinates
    if ((x >= bound1) && (x < bound2) && (y >= bound1) && (y < bound2)){
        return worldCoord[x][y];
    }
    else {
        return NULL;
    }
}
//set an organism's position: 
void World::setPos(int x, int y, Organism* input_organism){
    int bound1 = 0; int bound2 = WorldSize;
    if ((x >= bound1) && (x < bound2) && (y >= bound1) && (y < bound2)){
        worldCoord[x][y] = input_organism;
    }   
}
//show function:
void World::displayFrame(){
    int i, j;
    cout << endl << endl;
    for (i = 0; i < WorldSize; i++){
        for (j = 0; j < WorldSize; j++){
            if (worldCoord[i][j] == NULL) 
                cout << "- ";
            else if (worldCoord[i][j]->getType() == antID)
                cout << ant_char << " ";
            else
                cout << doodle_char << " ";
        }
        cout << endl;
    }
    cout << endl;
}
//simulate one timestep, or one "frame" forward:
void World::simulateFrame(){
    int i, j;
    //resetting all organisms moved status
    for (i = 0; i < WorldSize; i++){
        for (j = 0; j < WorldSize; j++){
            if (worldCoord[i][j] != NULL){
                worldCoord[i][j]->moved = false;
            }
        }
    }

    //moving bugs
    for (i = 0; i < WorldSize; i++){
        for (j = 0; j < WorldSize; j++){
            if ((worldCoord[i][j] != NULL) && (worldCoord[i][j]->getType() == bugID)){
                if (worldCoord[i][j]->moved == false){
                    worldCoord[i][j]->moved = true;
                    worldCoord[i][j]->move();
                }
            }
        }
    }

    //check bugs breedability, breed if possible
    for (i = 0; i < WorldSize; i++){
        for (j = 0; j < WorldSize; j++){
            if ((worldCoord[i][j] != NULL) && (worldCoord[i][j]->moved == true) && (worldCoord[i][j]->getType() == bugID)){
                worldCoord[i][j]->breed();
            }
        }
    }

    //killing the starved bugs
    for (i = 0; i < WorldSize; i++){
        for (j = 0; j < WorldSize; j++){
            if ((worldCoord[i][j] != NULL) && (worldCoord[i][j]->getType() == bugID)){
                if (worldCoord[i][j]->starved() == true){
                    delete (worldCoord[i][j]);
                    worldCoord[i][j] = NULL;
                }
            }
        }
    }

    //moving ants
    for (i = 0; i < WorldSize; i++){
        for (j = 0; j < WorldSize; j++){
            if ((worldCoord[i][j] != NULL) && (worldCoord[i][j]->getType() == antID)){
                if (worldCoord[i][j]->moved == false){
                    worldCoord[i][j]->moved = true;
                    worldCoord[i][j]->move();
                }
            }
        }
    }

    //check ants breedability, breed if possible
    for (i = 0; i < WorldSize; i++){
        for (j = 0; j < WorldSize; j++){
            if ((worldCoord[i][j] != NULL) && (worldCoord[i][j]->moved == true) && (worldCoord[i][j]->getType() == antID)){
                worldCoord[i][j]->breed();
            }
        }
    }
}

/*Organism Functions*/
//default constructor:
Organism::Organism(){
    organismCoordArr = NULL;
    moved = false;
    breedCount = 0;
    x = 0;
    y = 0;
}
//default parameterized constructor:
Organism::Organism(World* inputCoordArr, int x, int y){
    this->organismCoordArr = inputCoordArr;
    moved = false;
    breedCount = 0;
    this->x = x;
    this->y = y;
    inputCoordArr->setPos(x,y,this);
}
//default destructor:
Organism::~Organism(){}

/*Ant Functions*/
//default constructor:
Ant::Ant() : Organism(){}
//default paramterized constructor:
Ant::Ant(World* organismCoordArr, int x, int y) : Organism(organismCoordArr, x, y){}
//getType function:
int Ant::getType(){
    return antID;
}
//move function:
void Ant::move(){
    int random_direction = rand() % 4;
    
    //move coordinates
    Organism* currCell = organismCoordArr->getPos(x,y);
    Organism* cellUP = organismCoordArr->getPos(x, y - 1);
    Organism* cellDOWN = organismCoordArr->getPos(x, y + 1);
    Organism* cellLEFT = organismCoordArr->getPos(x - 1, y);
    Organism* cellRIGHT = organismCoordArr->getPos(x + 1, y);
    
    //moving ants in a random direction
    if (random_direction == 0){
        if ((y > 0) && (cellUP == NULL)){
            organismCoordArr->setPos(x, y-1, currCell);

            organismCoordArr->setPos(x,y,NULL);
            y++;
        }
    } else if (random_direction == 1){
        if ((y < WorldSize - 1) && (cellDOWN == NULL)){
            organismCoordArr->setPos(x,y+1,currCell);

            organismCoordArr->setPos(x,y,NULL);
            y++;
        }
    } else if (random_direction == 2){
        if ((x > 0) && (cellLEFT == NULL)){
            organismCoordArr->setPos(x-1, y, currCell);

            organismCoordArr->setPos(x,y,NULL);
            x--;
        }
    } else {
        if ((x < WorldSize - 1) && (cellRIGHT== NULL)){
            organismCoordArr->setPos(x+1, y, currCell);

            organismCoordArr->setPos(x,y,NULL);
            x++;
        }
    }
}
//breed function:
void Ant::breed(){
    breedCount++;

    if (breedCount == ant_breed_time){
        breedCount = 0;

        if ((y > 0) && organismCoordArr->getPos(x, y - 1) == NULL){
            Ant* newAnt = new Ant(organismCoordArr, x , y-1);
        }
        else if ((y < WorldSize - 1) && organismCoordArr->getPos(x, y + 1) == NULL){
            Ant* newAnt = new Ant(organismCoordArr, x, y + 1);
        }
        else if ((x > 0) && organismCoordArr->getPos(x-1, y) == NULL){
            Ant* newAnt = new Ant(organismCoordArr, x - 1, y);
        }
        else if ((x < WorldSize - 1) && organismCoordArr->getPos(x+1, y) == NULL) {
            Ant* newAnt = new Ant(organismCoordArr, x + 1, y);
        }
    }
}

/*Doodlebug Functions*/
//default constructor:
Doodlebug::Doodlebug() : Organism(){starveCount = 0;}
//default parameterized constructor:
Doodlebug::Doodlebug(World* organismCoordArr, int x, int y) : Organism(organismCoordArr,x,y){starveCount = 0;}
//move function:
void Doodlebug::move(){
    
    //move coordinates
    Organism* currCell = organismCoordArr->getPos(x,y);
    Organism* cellUP = organismCoordArr->getPos(x, y - 1);
    Organism* cellDOWN = organismCoordArr->getPos(x, y + 1);
    Organism* cellLEFT = organismCoordArr->getPos(x - 1, y);
    Organism* cellRIGHT = organismCoordArr->getPos(x + 1, y);
    
    //first, see if we can eat any neighboring ants, if so we do and reset the starved count
    if ((y > 0) && (cellUP != NULL) && (cellUP->getType() == antID)){
        delete (organismCoordArr->worldCoord[x][y-1]);
        organismCoordArr->worldCoord[x][y-1] = this;
        organismCoordArr->setPos(x,y,NULL);
        starveCount = 0;
        y--;  
    }
    else if ((y < WorldSize - 1) && (cellDOWN != NULL) && (cellDOWN->getType() == antID)){
        delete (organismCoordArr->worldCoord[x][y+1]);
        organismCoordArr->worldCoord[x][y+1] = this;
        organismCoordArr->setPos(x,y,NULL);
        starveCount = 0;
        y++;
    }
    else if ((x > 0) && (cellLEFT != NULL) && (cellLEFT->getType() == antID)){
        delete (organismCoordArr->worldCoord[x-1][y]);
        organismCoordArr->worldCoord[x-1][y] = this;
        organismCoordArr->setPos(x,y,NULL);
        starveCount = 0;
        x--;
    }
    else if ((x < WorldSize - 1) && (cellRIGHT != NULL) && (cellRIGHT->getType() == antID)){
        delete (organismCoordArr->worldCoord[x+1][y]);
        organismCoordArr->worldCoord[x+1][y] = this;
        organismCoordArr->setPos(x,y,NULL);
        starveCount = 0;
        x++;  
    }


    int random_direction = rand() % 4;

    //moving the bugs in a random direction
    if (random_direction == 0){
        if ((y > 0) && (cellUP == NULL)){
            organismCoordArr->setPos(x, y - 1, currCell);

            organismCoordArr->setPos(x,y,NULL);
            y--;
        }
    }
    else if (random_direction == 1){
        if ((y < WorldSize - 1) && (cellDOWN == NULL)){
            organismCoordArr->setPos(x, y + 1, currCell);

            organismCoordArr->setPos(x,y,NULL);
            y++;
        }
    }
    else if (random_direction == 2){
        if ((x > 0) && (cellLEFT == NULL)){
            organismCoordArr->setPos(x-1, y, currCell);

            organismCoordArr->setPos(x,y,NULL);
            x--;
        }
    }
    else {
        if ((x < WorldSize - 1) && (cellRIGHT == NULL)){
            organismCoordArr->setPos(x+1, y, currCell);

            organismCoordArr->setPos(x,y,NULL);
            x++;
        }
    }
    
    //in the case that a doodle bug moves, we increase the bug's starveCount
    starveCount++;
}
//getType Function;
int Doodlebug::getType(){
    return bugID;
}
//breed function
void Doodlebug::breed(){
    breedCount++;
    
    if (breedCount == doodle_breed_time){
        breedCount = 0;

        if ((y > 0) && organismCoordArr->getPos(x, y - 1) == NULL){
            Doodlebug* newDoodle = new Doodlebug(organismCoordArr, x , y-1);
        }
        else if ((y < WorldSize - 1) && organismCoordArr->getPos(x, y + 1) == NULL){
            Doodlebug* newDoodle = new Doodlebug(organismCoordArr, x, y + 1);
        }
        else if ((x > 0) && organismCoordArr->getPos(x-1, y) == NULL){
            Doodlebug* newDoodle = new Doodlebug(organismCoordArr, x - 1, y);
        }
        else if ((x < WorldSize - 1) && organismCoordArr->getPos(x+1, y) == NULL) {
            Doodlebug* newDoodle = new Doodlebug(organismCoordArr, x + 1, y);
        }
    }
}
//starved function:
bool Doodlebug::starved(){
    if (starveCount > doodle_starve_time){
        return true;
    }
    return false;
}

//extra helper functions:
//seed ants:
void seedAnts(World& input_board){
    int antCountVal = 0;
    for (int i = antCountVal; i < init_ant_amount; i++){
        int x = rand() % WorldSize;
        int y = rand() % WorldSize;

        if(input_board.getPos(x,y) == NULL){
            antCountVal++;
            Ant* build_ant = new Ant(&input_board, x, y);
        }
    }
}
//seed doodles:
void seedDoodles(World& input_board){
    int doodleCountVal = 0;
    for (int i = doodleCountVal; i < init_bugs_amount; i++){
        int x = rand() % WorldSize;
        int y = rand() % WorldSize;

        if (input_board.getPos(x,y) == NULL){
            doodleCountVal++;
            Doodlebug* build_doodle = new Doodlebug(&input_board,x,y);
        }
    }   
}

