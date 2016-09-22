#include <SDL/SDL.h>
#include "map.hpp"
#include "maze.hpp"

void Maze::draw_maze( SDL_Surface * image, SDL_Surface * screen, SDL_Rect dest){

  for(int i=0;i<18;i++){
    for(int j=0;j<11;j++){
      if(init_stage[i][j]){
        dest.x = i*60; // Ponto de destino no eixo X
        dest.y = j*60; // Ponto de destino no exito Y
        //Definindo a parede do labirinto
        wall.push_back(make_pair(dest.x,dest.y));

        //Monta o labirinto
        SDL_BlitSurface(image, NULL, screen, &dest); // Joga a imagem no screen em dest
      }
    }
  }

  SDL_UpdateRect(screen, 0,0,0,0); // Atualiza o screen com a imagem blitada
}

Maze::Maze(){
  wall.clear();
}
