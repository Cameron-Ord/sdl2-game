#ifndef ERRORS_H
#define ERRORS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_err_buffer();
void print_SDL_err(const char *msg);
void print_last_err();
void print_mem_err(char *msg, char *type);

#endif
