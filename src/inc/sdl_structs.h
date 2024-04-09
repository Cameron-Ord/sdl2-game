#ifndef SDL_STRUCTS_H
#define SDL_STRUCTS_H
#include <SDL2/SDL.h>

struct SdlData {
  SDL_Window *w;
  SDL_Renderer *r;
  SDL_AudioDeviceID dev;
  SDL_AudioSpec spec;

  float TICKS_PER_FRAME;

  int running;

  int w_width;
  int w_height;

  char state[256];
  char last_err[256];
};

#endif
