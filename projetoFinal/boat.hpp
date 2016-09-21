#ifndef BOAT
#define BOAT
#include <SDL/SDL.h">

const int SQUARE_WIDTH = 60;
const int SQUARE_HEIGTH= 60;

class Boat {
  private:
    //Velocidade do barco
    int xVel, yVel;
    //Box para definir o range da colisão
    SDL_Rect box;

  public:
    //Construtor
    Boat();
    //Recuperar movimentos externos e ajusta a velocidade do barco
    void handle_input();
    //Movimentos do barco
    void move();
    //Mostrar o Barco
    void show();
};

#endif
