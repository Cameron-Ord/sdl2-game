#include "inc/sdl_include.h"

int main(int argc, char *argv[]) {
  struct SdlData sdl;
  if (start_sdl(&sdl) < 0)
    return -1;

  float prev_time = SDL_GetTicks64();
  float current_time, delta_time;

  while (sdl.running) {
    current_time = SDL_GetTicks64();
    delta_time = current_time - prev_time;

    poll_events(&sdl);
    clear_renderer(sdl.r);
    render_bg(sdl.r);
    // render_tiles()
    // render_player()
    // render_npcs()
    // render_other_sprites()
    // render_interactables()
    render_present(sdl.r);

    if (delta_time >= sdl.TICKS_PER_FRAME) {
      SDL_Delay(sdl.TICKS_PER_FRAME);
    }
  }

  return 0;
}
