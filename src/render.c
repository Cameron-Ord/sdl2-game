#include "inc/render.h"

void clear_renderer(SDL_Renderer *r) { SDL_RenderClear(r); }

void render_bg(SDL_Renderer *r) { SDL_SetRenderDrawColor(r, 0, 0, 0, 0); }

void render_present(SDL_Renderer *r) { SDL_RenderPresent(r); }
