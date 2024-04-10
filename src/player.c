#include "inc/player.h"

void initialize_player(struct Player *player) {
  player->health = 100.0f;
  player->move_speed = 1.25f;
  player->jump_strength = 1.25f;
  memset(&player->player_rect, 0, sizeof(player->player_rect));
}
