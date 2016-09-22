#ifndef BOAT
#define BOAT

const int SQUARE_WIDTH = 30;
const int SQUARE_HEIGHT = 30;

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 660;

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
    void handle_input(SDL_Event event);
    //Movimentos do barco
    void move(SDL_Surface * image);
    //Mostrar o Barco
    void show(SDL_Surface * image,SDL_Surface * screen);
    //Verifica se o barco irá bater no labirinto
    bool check_colision();
};

#endif
