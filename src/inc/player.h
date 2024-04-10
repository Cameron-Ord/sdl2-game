#ifndef PLAYER_H
#define PLAYER_H
#include "player_structs.h"
void initialize_player(struct Player *player);

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
