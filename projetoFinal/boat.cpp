#include <SDL/SDL.h>
#include "boat.hpp"

Boat::Boat(){
  //Inicializando a posição inicial
  box.x = 0;
  box.y = 0;
  //Inicializando a dimensão
  box.w = SQUARE_WIDTH;
  box.h = SQUARE_HEIGHT;

  //Inicializando a velocidade
  xVel = 0;
  yVel = 0;
}

void Boat::handle_input(SDL_Event event)
{
  //If a key was pressed
  if( event.type == SDL_KEYDOWN )
  {
    //Adjust the velocity
    switch( event.key.keysym.sym )
    {
      case SDLK_UP: yVel -= SQUARE_HEIGHT / 2; break;
      case SDLK_DOWN: yVel += SQUARE_HEIGHT / 2; break;
      case SDLK_LEFT: xVel -= SQUARE_WIDTH / 2; break;
      case SDLK_RIGHT: xVel += SQUARE_WIDTH / 2; break;
    }
  }
  //If a key was released
  else if( event.type == SDL_KEYUP )
  {
    //Adjust the velocity
    switch( event.key.keysym.sym )
    {
      case SDLK_UP: yVel += SQUARE_HEIGHT / 2; break;
      case SDLK_DOWN: yVel -= SQUARE_HEIGHT / 2; break;
      case SDLK_LEFT: xVel += SQUARE_WIDTH / 2; break;
      case SDLK_RIGHT: xVel -= SQUARE_WIDTH / 2; break;
    }
  }
}

void Boat::move()
{
  //Move the square left or right
  box.x += xVel;
  printf("BoxX = %d\n", box.x);

  //If the square went too far to the left or right or has collided with the wall
  if( ( box.x < 0 ) || ( box.x + SQUARE_WIDTH > SCREEN_WIDTH ) )
  {
    //Move back
    box.x -= xVel;
  }

  //Move the square up or down
  box.y += yVel;
  printf("BoxY = %d\n", box.y);

  //If the square went too far up or down or has collided with the wall
  if( ( box.y < 0 ) || ( box.y + SQUARE_HEIGHT > SCREEN_HEIGHT ) )
  {
    //Move back
    box.y -= yVel;
  }
}

void Boat::show(SDL_Surface * image,SDL_Surface * screen)
{
  SDL_Rect dest;

  dest.x = box.x;
  dest.y = box.y;
  //Mostra o Barco
  SDL_BlitSurface(image, NULL, screen, &dest);
}
