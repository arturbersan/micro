#include <SDL/SDL.h>
#include "map.hpp"
// #include "boat.hpp"

void draw_maze( SDL_Surface * image, SDL_Surface * screen, SDL_Rect dest){

  for(int i=0;i<18;i++){
    for(int j=0;j<11;j++){
      if(init_stage[i][j]){
        dest.x = i*60; // Ponto de destino no eixo X
        dest.y = j*60; // Ponto de destino no exito Y

        //Monta o labirinto
        SDL_BlitSurface(image, NULL, screen, &dest); // Joga a imagem no screen em dest
      }
    }
  }

  SDL_UpdateRect(screen, 0,0,0,0); // Atualiza o screen com a imagem blitada
}

int main()
{
  SDL_Init(SDL_INIT_VIDEO); // Inicializa o SDL e o sistema de vídeo
  SDL_Surface * screen; // A janela principal
  SDL_Surface * image; // A imagem
  SDL_Surface * image_texture; // A imagem
  SDL_Event event; // Evento teclado
  SDL_Rect dest; // Destino da imagem

  screen = SDL_SetVideoMode(1080, 660, 16, SDL_SWSURFACE); // Cria a janela
  image = SDL_LoadBMP("barco_a_vela.bmp"); // Carrega a imagem no formato BMP
  image_texture = SDL_LoadBMP("texture.bmp"); // Carrega a imagem no formato BMP

  // Verifica se carregou a imagem corretamente
  if (image == NULL)
  {
    printf("Não foi possivel abrir ball.bmp\n");
    return 1;
  }

  // Move a imagem para o ponto X = 0 e Y = 0
  dest.x = 0; // Ponto de destino no eixo X
  dest.y = 0; // Ponto de destino no exito Y
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 12, 159, 230));
  SDL_BlitSurface(image, NULL, screen, &dest); // Joga a imagem no screen em dest
  SDL_UpdateRect(screen, 0,0,0,0); // Atualiza o screen com a imagem blitada

  bool done = 0;
  while(done==0){
    draw_maze(image_texture,screen,dest);
    while(SDL_PollEvent(&event)){
      }
      if (event.type == SDL_QUIT) // Se o usuário clicou para fechar a janela
        done = 1;
  }

  SDL_Quit(); // Fecha o SDL

  return 0;
}