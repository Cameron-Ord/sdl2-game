#ifndef PLAYER_STRUCTS_H
#define PLAYER_STRUCTS_H
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
struct Player {
  char *sprite_path;
  SDL_Surface *player_surface;
  SDL_Texture *player_texture;
  SDL_Rect player_rect;
  float health;
  float move_speed;
  float jump_strength;
};

#endif
