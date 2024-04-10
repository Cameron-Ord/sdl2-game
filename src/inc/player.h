#ifndef PLAYER_H
#define PLAYER_H
#include "player_structs.h"
#include "sdl_structs.h"
#include <SDL2/SDL.h>

int initialize_player(struct SdlData *sdl, struct Player *player,
                      char *sprite_path);
void get_initial_position(struct SdlData *sdl, SDL_Rect *player_rect);
int create_player_surface(char *file_path, SDL_Surface **surf_ptr);
int create_player_texture(SDL_Renderer *r, SDL_Surface **surf_ptr,
                          SDL_Texture **tex_ptr);

/*
 *
 * These are not necessarily going to be named this way, just placeholder
 * functions to track out what I need to do
 *
 */

void walk();
void invertory();
void run();
void attack();
void damage_tick();

#endif
