#include "inc/errors.h"

#define MAX_ERR_LEN 256
#define MAX_ERR_MESSAGES 15
int err_index = 0;
char last_err[MAX_ERR_MESSAGES][MAX_ERR_LEN];

void clear_err_buffer() { memset(last_err, '\0', sizeof(last_err)); }

void print_SDL_err(const char *msg) {
  fprintf(stderr, "SDL ERR: %s\n", msg);
  strcpy(last_err[err_index], msg);
  err_index = (err_index + 1) % MAX_ERR_MESSAGES - 1;
}

void print_last_err() { fprintf(stderr, "%s\n", last_err[err_index]); }

void print_mem_err(char *msg, char *type) {
  fprintf(stderr, "A %s error has occured: %s\n", type, msg);
  char combined[1024];
  snprintf(combined, 1024, "Error of %s : %s", type, msg);
  strcpy(last_err[err_index], combined);
  err_index = (err_index + 1) % MAX_ERR_MESSAGES;
}
