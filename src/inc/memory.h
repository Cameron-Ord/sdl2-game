#ifndef MEMORY_H
#define MEMORY_H
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

void *realloc_block(void *ptr, size_t size);
void *malloc_block(void *ptr, size_t size);
void *calloc_block(void *ptr, size_t size, size_t byte_size);
int free_ptr(void *ptr);
void set_mem_zeroed(void *ptr, size_t size);

#endif
