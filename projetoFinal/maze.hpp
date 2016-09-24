#ifndef MAZE
#define MAZE
#include <vector>
#include <utility>
#include <iostream>
using namespace std;
const int SQUARE = 60;

class Maze{
  public:
    vector < pair<int,int> > wall;
    //Desenha o labirinto
    void draw_maze(SDL_Surface * image, SDL_Surface * screen, SDL_Rect dest);
    //Construtor
    Maze();
};

#endif
