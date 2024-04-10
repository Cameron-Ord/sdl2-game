#include "inc/textures.h"
#include "inc/errors.h"

SDL_Surface *create_sprite_surface(char *file_path, char *last_err) {

  SDL_Surface *surface = IMG_Load(file_path);
  if (!surface) {
    print_SDL_err(SDL_GetError());
    return NULL;
  }

  return surface;
}

SDL_Texture *create_sprite_texture(SDL_Renderer *r, SDL_Surface *surf,
                                   char *last_err) {

  SDL_Texture *texture = SDL_CreateTextureFromSurface(r, surf);
  if (!texture) {
    print_SDL_err(SDL_GetError());
    return NULL;
  }

  return texture;
}
