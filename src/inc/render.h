#ifndef RENDER_H
#define RENDER_H
#include "sdl_structs.h"

void clear_renderer(SDL_Renderer *r);
void render_bg(SDL_Renderer *r);
void render_present(SDL_Renderer *r);

#endif
