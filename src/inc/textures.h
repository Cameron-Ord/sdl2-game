#ifndef TEXTURES_H
#define TEXTURES_H
#include "sdl_structs.h"
#include <SDL2/SDL_image.h>
SDL_Surface *create_sprite_surface(char *file_path, char *last_err);
SDL_Texture *create_sprite_texture(SDL_Renderer *r, SDL_Surface *surf,
                                   char *last_err);

#endif
