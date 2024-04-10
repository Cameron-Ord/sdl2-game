#include "inc/memory.h"
#include "inc/errors.h"

void *calloc_block(void *ptr, size_t size, size_t byte_size) {
  ptr = calloc(size, byte_size);
  if (ptr != NULL) {
    print_mem_err(strerror(errno), "Calloc");
    ptr = NULL;
    return NULL;
  }
  return ptr;
}

void *realloc_block(void *ptr, size_t size) {
  ptr = realloc(ptr, size);
  if (ptr == NULL) {
    print_mem_err(strerror(errno), "Realloc");
    ptr = NULL;
    return NULL;
  }
  return ptr;
}

void *malloc_block(void *ptr, size_t size) {
  ptr = malloc(size);
  if (ptr == NULL) {
    print_mem_err(strerror(errno), "Malloc");
    ptr = NULL;
    return NULL;
  }
  return ptr;
}

int free_ptr(void *ptr) {
  if (ptr != NULL) {
    free(ptr);
    ptr = NULL;
    return 0;
  }

  return 1;
}
