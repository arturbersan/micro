#include <SDL/SDL.h>
#include "boat.hpp"
#include "map.hpp"

bool Boat::check_colision()
{
  //The sides of the rectangles
  int leftA, leftB,rightA, rightB,topA, topB,bottomA, bottomB;
  //Calculate the sides of rect A
  leftA = box.x;
  rightA = box.x + box.w;
  topA = box.y;
  bottomA = box.y + box.h;
  //If any of the sides from A are outside of B
  // int i = (box.x)/SQUARE_WIDTH, j = (box.y)/SQUARE_HEIGHT;
  // if(init_stage[i][j]){
    // printf("i = %d\nj = %d\n",i,j);
    // //Calculate the sides of rect B
    // leftB = i*60;
    // rightB = i*60 + 60;
    // topB = j*60;
    // bottomB = j*60+60;
    //
    // if( bottomA <= 60 )
    //   return false;
    // if( topA >= 60 )
    //   return false;
    // if( rightA <= 60 )
    //   return false;
    // if( leftA >= 60)
    //   return false;
  // }
  //If none of the sides from A are outside B
  return true;
}

Boat::Boat()
{
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
      case SDLK_UP: yVel -= 5; break;
      case SDLK_DOWN: yVel += 5; break;
      case SDLK_LEFT: xVel -= 5; break;
      case SDLK_RIGHT: xVel += 5; break;
    }
  }
  //If a key was released
  else if( event.type == SDL_KEYUP )
  {
    //Adjust the velocity
    switch( event.key.keysym.sym )
    {
      case SDLK_UP: yVel += 5; break;
      case SDLK_DOWN: yVel -= 5; break;
      case SDLK_LEFT: xVel += 5; break;
      case SDLK_RIGHT: xVel -= 5; break;
    }
  }
}

void Boat::move(SDL_Surface * image)
{
  printf("Posição (%d,%d)\n",box.x,box.y);
  //Move the square left or right
  box.x += xVel;
  //If the square went too far to the left or right or has collided with the wall
  if( ( box.x < 0 ) || ( box.x + SQUARE_WIDTH > SCREEN_WIDTH ) )
  {
    //Move back
    box.x -= xVel;
  }
  //Move the square up or down
  box.y += yVel;
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
