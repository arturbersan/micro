#include <SDL/SDL.h>
#include "maze.hpp"
#include "boat.hpp"

int main()
{
  SDL_Init(SDL_INIT_VIDEO); // Inicializa o SDL e o sistema de vídeo
  SDL_Surface * screen; // A janela principal
  SDL_Surface * image; // A imagem
  SDL_Surface * image_texture; // A imagem
  SDL_Event event; // Evento teclado
  SDL_Rect dest; // Destino da imagem
  Boat myBoat;
  Maze myMaze;

  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 16, SDL_SWSURFACE); // Cria a janela
  image = SDL_LoadBMP("barco_a_vela.bmp"); // Carrega a imagem no formato BMP
  image_texture = SDL_LoadBMP("texture.bmp"); // Carrega a imagem no formato BMP

  // Verifica se carregou a imagem corretamente
  if (image == NULL)
  {
    printf("Não foi possivel abrir ball.bmp\n");
    return 1;
  }

  bool done = 0;
  while(done==0){
    while(SDL_PollEvent(&event)){
        myBoat.handle_input(event);
      }
      if (event.type == SDL_QUIT) // Se o usuário clicou para fechar a janela
        done = 1;
      myMaze.draw_maze(image_texture,screen,dest);
      myBoat.move(image_texture);
      SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 12, 159, 230));
      myBoat.show(image,screen);
      // SDL_UpdateRect(screen, 0,0,0,0); // Atualiza o screen com a imagem blitada
  }

  SDL_Quit(); // Fecha o SDL

  return 0;
}
