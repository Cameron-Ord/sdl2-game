#include "inc/player.h"
#include "inc/init.h"
#include "inc/textures.h"

int initialize_player(struct SdlData *sdl, struct Player *player,
                      char *sprite_path) {
  int err;
  player->sprite_path = sprite_path;
  player->player_surface = NULL;
  player->player_texture = NULL;
  player->health = 100.0f;
  player->move_speed = 1.25f;
  player->jump_strength = 1.25f;
  memset(&player->player_rect, 0, sizeof(player->player_rect));

  err = create_player_surface(sprite_path, &player->player_surface);
  if (err < 0)
    return err;

  err = create_player_texture(sdl->r, &player->player_surface,
                              &player->player_texture);
  if (err < 0)
    return err;

  get_initial_position(sdl, &player->player_rect);

  printf("PLAYER SURFACE: %p, PLAYER TEXTURE: %p\n", player->player_surface,
         player->player_texture);

  return 0;
}

void get_initial_position(struct SdlData *sdl, SDL_Rect *player_rect) {
  get_sdl_window_size(sdl->w, &sdl->w_width, &sdl->w_height);
  player_rect->x = sdl->w_width / 2;
  player_rect->y = sdl->w_height / 2;
  printf("PLAYER X: %d, PLAYER Y: %d\n", player_rect->x, player_rect->y);
}

int create_player_surface(char *file_path, SDL_Surface **surf_ptr) {
  *surf_ptr = create_sprite_surface(file_path);
  if (!*surf_ptr) {
    return -1;
  }

  return 0;
}

int create_player_texture(SDL_Renderer *r, SDL_Surface **surf_ptr,
                          SDL_Texture **tex_ptr) {

  *tex_ptr = create_sprite_texture(r, *surf_ptr);
  if (!*tex_ptr) {
    return -1;
  }
  SDL_FreeSurface(*surf_ptr);
  *surf_ptr = NULL;
  return 0;
}
