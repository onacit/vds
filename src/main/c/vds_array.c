#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vds_array.h>
#include <vds_swap.h>

long vds_array_hash_o(void * array, size_t const size, size_t const length,
                      long (* const hash) (void *)) {
  long result = 7L;
  void * const limit = ((char *) array) + (size * length);
  for (; array < limit; array = ((char *) array) + size) {
    result = result * 31 + hash(array);
  }
  return result;
}

long vds_array_hash_u(void * array, size_t const size, size_t const length,
                      long (* const hash) (void *)) {
  long result = 0L;
  void * const limit = ((char *) array) + (size * length);
  for (; array < limit; array = ((char *) array) + size) {
    result += vds_array_hash_o(array, size, 1LLU, hash);
  }
  return result;
}

void vds_array_sort_insertion(void * const array, size_t const size,
                              size_t const length,
                              int (* const compare) (void *, void *)) {
  char * const limit = ((char *) array) + (size * length);
  for (char * i = ((char *) array) + size; i < limit; i += size) {
    for (char * j = i; j > (char *) array; j -= size) {
      if (compare(j, j - size) <= 0) {
        break;
      }
      vds_swap_block(j, j - size, size);
    }
  }
}

void vds_array_sort_insertion_f(void * const array, size_t const size,
                                size_t const length,
                                int (* compare)(void *, void *)) {
  void * t = malloc(size);
  if (t == NULL) {
    exit(EXIT_FAILURE);
  }
  char * const limit = ((char *) array) + (size * length);
  for (char * i = ((char *) array) + size; i < limit; i += size) {
    memcpy(t, i, size);
    for (char * j = i - size; j >= (char *) array; j -= size) {
      if (compare(j, t) <= 0) {
        memmove(j + size, t, size);
        break;
      }
      memcpy(j + size, j, size);
    }
  }
  free(t);
}

void vds_array_sort_selection(void * const array, size_t const size,
                              size_t const length,
                              int (* compare)(void *, void *)) {
  char * const limit = ((char *) array) + (size * length);
  for (char * i = array; i < (limit - size); i += size) {
    char * smallest = i;
    for (char * j = (i + size); j < limit; j += size) {
      if (compare(j, smallest) < 0) {
        smallest = j;
      }
    }
    if (smallest > i) {
      vds_swap_block(i, smallest, size);
    }
  }
}

void a() {
}

void vds_array_sort_merge(void * const array, size_t const size,
                          size_t const length,
                          int (* compare)(void *, void *)) {
  char * const limit = ((char *) array) + (size * length);
  for (char * i = array; i < (limit - size); i += size) {
    char * smallest = i;
    for (char * j = (i + size); j < limit; j += size) {
      if (compare(j, smallest) < 0) {
        smallest = j;
      }
    }
    if (smallest > i) {
      vds_swap_block(i, smallest, size);
    }
  }
}
