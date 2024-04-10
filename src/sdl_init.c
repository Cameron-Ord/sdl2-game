#include "inc/errors.h"
#include "inc/init.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

int start_sdl(struct SdlData *sdlptr) {

  int status = 0;
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    print_SDL_err(SDL_GetError());
    return -1;
  }

  float init_time = SDL_GetTicks64();
  printf("SDL INITIALIZED IN : %3.f ms\n", init_time);

  initialize_variables(sdlptr);

  status = create_window_context(&sdlptr->w);
  if (status < 0) {
    return status;
  }

  status = create_render_context(&sdlptr->w, &sdlptr->r);
  if (status < 0) {
    return status;
  }

  float win_time = SDL_GetTicks64();
  printf("SDL CONTEXTS CREATED IN: %3.f ms\n", win_time);

  sdlptr->running = 1;
  return (0);
}

void initialize_variables(struct SdlData *sdlptr) {
  sdlptr->w = NULL;
  sdlptr->r = NULL;
  sdlptr->dev = 0;
  sdlptr->spec.freq = 0;
  sdlptr->spec.size = 0;
  sdlptr->spec.format = AUDIO_F32;
  sdlptr->spec.padding = 0;
  sdlptr->spec.samples = AUDIO_SAMPLES;
  sdlptr->spec.silence = 0;
  sdlptr->spec.channels = 0;
  sdlptr->spec.userdata = NULL;
  sdlptr->spec.callback = callback;
  sdlptr->TICKS_PER_FRAME = 1000.0 / 60.0;
  sdlptr->running = 0;
  sdlptr->w_width = BASE_WIDTH;
  sdlptr->w_height = BASE_HEIGHT;
  memset(sdlptr->state, '\0', sizeof(sdlptr->state));
}

int create_window_context(SDL_Window **w) {
  *w = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                        BASE_WIDTH, BASE_HEIGHT, 0);

  if (!*w) {
    print_SDL_err(SDL_GetError());
    return (-1);
  }

  SDL_SetWindowResizable(*w, SDL_TRUE);
  return (0);
}

int create_render_context(SDL_Window **w, SDL_Renderer **r) {
  int status = 0;
  *r = SDL_CreateRenderer(*w, -1,
                          SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!*r) {
    print_SDL_err(SDL_GetError());
    return (-1);
  }
  return (0);
}
