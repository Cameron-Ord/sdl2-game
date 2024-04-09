#ifndef ERRORS_H
#define ERRORS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_SDL_err(const char *msg, char *last_err);
void print_last_err(char *last_err);

#endif
