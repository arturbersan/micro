#include <SDL/SDL.h>
#include "boat.hpp"

using namespace std;

bool Boat::check_collision(pair<int,int> singleWall)
{
  //The sides of the rectangles
  int leftA, leftB,rightA, rightB,topA, topB,bottomA, bottomB;
  //Calculate the sides of rect A
  printf("box(%d,%d)\n", box.x,box.y);
  leftA = box.x;
  rightA = box.x + box.w;
  topA = box.y;
  bottomA = box.y + box.h;
  // printf("leftA=%d\nrightA=%d\ntopA=%d\nbottomA=%d\n",leftA,rightA,topA,bottomA);
  leftB = singleWall.first;
  rightB = singleWall.first + SQUARE;
  topB = singleWall.second;
  bottomB = singleWall.second + SQUARE;

  //Calculate the sides of rect B
  if( bottomA <= topB ){
    return false;
  }
  if( topA >= bottomB ){
    return false;
  }
  if( rightA <= leftB ){
    return false;
  }
  if( leftA >= rightB ){
    return false;
  }
  //If none of the sides from A are outside B
  return true;
}

Boat::Boat()
{
  //Inicializando a posição inicial
  box.x = 0;
  box.y = 0;
  //Inicializando a dimensão
  box.w = BOAT_WIDTH;
  box.h = BOAT_HEIGHT;
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

void Boat::move(SDL_Surface * image, Maze myMaze)
{
  //Move the square left or right
  box.x += xVel;
  for(int i = 0;i<90;i++){
    if(check_collision(myMaze.wall[i]))
      box.x -= xVel;
  }
  if( ( box.x < 0 ) || ( box.x + BOAT_WIDTH > SCREEN_WIDTH ))
  {
    for(int i = 0;i<90;i++){
      if(check_collision(myMaze.wall[i]))
        box.x -= xVel;
    }
    //Move back
    box.x -= xVel;
  }
  //Move the square up or down
  box.y += yVel;
  //If the square went too far up or down or has collided with the wall
  if( ( box.y < 0 ) || ( box.y + BOAT_HEIGHT > SCREEN_HEIGHT ) )
  {
    //Move back
    box.y -= yVel;
  }
  for(int i = 0;i<90;i++){
    if(check_collision(myMaze.wall[i]))
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
