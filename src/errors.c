#include "inc/errors.h"

char last_err[1024];

void print_SDL_err(const char *msg) {
  fprintf(stderr, "%s\n", msg);
  memset(last_err, '\0', sizeof(last_err));
  strcpy(last_err, msg);
}

void print_last_err() { fprintf(stderr, "%s\n", last_err); }

void print_mem_err(char *msg, char *type) {
  fprintf(stderr, "A %s error has occured: %s\n", type, msg);
  memset(last_err, '\0', sizeof(last_err));
  char combined[1024];
  snprintf(combined, 1024, "Error of %s : %s", type, msg);
  strcpy(last_err, combined);
}
