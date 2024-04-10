#ifndef INIT_H
#define INIT_H
#include "sdl_structs.h"

#define AUDIO_SAMPLES 1024
#define BASE_WIDTH 600
#define BASE_HEIGHT 400
#define ARR_LEN(x) (sizeof(x) / sizeof(x[0]))

// initialization

int start_sdl(struct SdlData *sdlptr);
int create_window_context(SDL_Window **w);
int create_render_context(SDL_Window **w, SDL_Renderer **r);
void initialize_variables(struct SdlData *sdlptr);

// audio
void callback(void *userdata, Uint8 *stream, int len);

// Window
void get_sdl_window_size(SDL_Window *w, int *width, int *height);
#endif
