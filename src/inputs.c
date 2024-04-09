#include "inc/inputs.h"

void poll_events(struct SdlData *sdlptr) {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    switch (e.type) {

    default: {
      break;
    }

    case SDL_KEYDOWN: {
      switch (e.key.keysym.sym) {

      default: {
        break;
      }

      case SDLK_q: {
        sdlptr->running = 0;
        break;
      }
      }
    }
    }
  }
}
