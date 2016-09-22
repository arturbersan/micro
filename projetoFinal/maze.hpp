#ifndef MAZE
#define MAZE
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

class Maze{
  private:
    vector < pair<int,int> > wall;
  public:
    //Desenha o labirinto
    void draw_maze(SDL_Surface * image, SDL_Surface * screen, SDL_Rect dest);
    //Construtor
    Maze();
};

#endif
