#include "inc/errors.h"
#include "inc/sdl_include.h"
#include <time.h>

int main(int argc, char *argv[]) {
  int result = 0;
  struct SdlData sdl;
  struct Player player;

  if (start_sdl(&sdl) < 0)
    return -1;

  char *sprite_path = "gfxsheet/sprites.png";

  srand(time(NULL));
  result = initialize_player(&sdl, &player, sprite_path);
  if (result < 0) {
    print_last_err();
    return 1;
  }
  printf("INITIALIZED PLAYER IN %3.f ms\n", (float)SDL_GetTicks64());

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
