#include <SDL/SDL.h>
#include "boat.hpp"

bool Boat::check_collision(Maze myMaze)
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
  leftB = myMaze.wall[2].first;
  rightB = myMaze.wall[2].first + SQUARE;
  topB = myMaze.wall[2].second;
  bottomB = myMaze.wall[2].second + SQUARE;

  //Calculate the sides of rect B
  int size_wall = myMaze.wall.size();
  printf("tam = %d\n",size_wall);
  for(int i=0; i<size_wall;i++){
    printf("i = %d\n",i);
    // printf("maze = %d,%d\n",myMaze.wall[i].first,myMaze.wall[i].second);
    // printf("Maze (%d,%d)\n",myMaze.wall[i].first,myMaze.wall[i].second);
    // printf("myMaze.wall[i].first = %d\n",myMaze.wall[i].first);
    // printf("myMaze.wall[i].second = %d\n",myMaze.wall[i].second);
    // leftB = myMaze.wall[i].first;
    // rightB = myMaze.wall[i].first + SQUARE;
    // topB = myMaze.wall[i].second;
    // bottomB = myMaze.wall[i].second + SQUARE;
    // printf("left=%d\nright=%d\ntop=%d\nbottom=%d\n",leftB,rightB,topB,bottomB);
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
  //If the square went too far to the left or right or has collided with the wall
  // if( box.x >= xVel && (box.x + BOAT_WIDTH) <= SCREEN_WIDTH && check_collision(myMaze) )
  if(check_collision(myMaze))
    printf("Ta colidindo\n");
  else
    printf("Não ta colidindo\n");
  // SDL_Quit();

  if( ( box.x < 0 ) || ( box.x + BOAT_WIDTH > SCREEN_WIDTH ) || check_collision(myMaze) )
  {
    //Move back
    box.x -= xVel;
  }
  //Move the square up or down
  box.y += yVel;
  //If the square went too far up or down or has collided with the wall
  if( ( box.y < 0 ) || ( box.y + BOAT_HEIGHT > SCREEN_HEIGHT ) || check_collision(myMaze) )
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
