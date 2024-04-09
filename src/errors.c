#include "inc/errors.h"

void print_SDL_err(const char *msg, char *last_err) {
  fprintf(stderr, "%s\n", msg);
  memset(last_err, '\0', sizeof(*last_err));
  strcpy(last_err, msg);
}

void print_last_err(char *last_err) { fprintf(stderr, "%s\n", last_err); }
