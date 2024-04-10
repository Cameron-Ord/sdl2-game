#ifndef PLAYER_STRUCTS_H
#define PLAYER_STRUCTS_H
#include <SDL2/SDL_rect.h>
struct Player {
  SDL_Rect player_rect;
  float health;
  float move_speed;
  float jump_strength;
};

#endif
