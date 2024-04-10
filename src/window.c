#include "inc/init.h"

void get_sdl_window_size(SDL_Window *w, int *width, int *height) {
  SDL_GetWindowSize(w, width, height);
}
