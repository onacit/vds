#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vds_utils.h>

#define compare(a, b) \
  _Generic((a), \
           long *: comparel, \
           unsigned long *: comparelu \
           long long *: comparel \
           unsigned long long *: comparellu \
           )(a, b)

int comparel(long const a, long const b) {
  return a < b ? -1 : (a == b ? 0 : 1);
}

int comparelp(long * const a, long * const b) {
  return comparel(*a, *b);
}

void swap_byte(char * a, char * b, char * t) {
  *t = *a;
  *a = *b;
  *b = *t;
}

void swap_block(void * const a, void * const b, size_t const s) {
  char * const t = malloc(sizeof (char));
  if (t == NULL) {
    exit(EXIT_FAILURE);
  }
  char * q = a;
  char * p = b;
  for (unsigned long long i = 0; i < s; i++) {
    swap_byte(p++, q++, t);
  }
  free(t);
}

void swap_block_w(void * const a, void * const b, size_t const s) {
  char * p = a;
  char * q = b;
  size_t const word_bytes = sizeof (long);
  size_t const word_count = s / word_bytes;
  if (word_count > 0) {
    char * const t = malloc(word_bytes);
    if (t == NULL) {
      exit(EXIT_FAILURE);
    }
    for (unsigned long long i = 0; i < word_count; i++) {
      memmove(t, p, word_bytes);
      memmove(p, q, word_bytes);
      memmove(q, t, word_bytes);
      p += word_bytes;
      q += word_bytes;
    }
    free(t);
  }
  size_t const byte_count = s % word_bytes;
  if (byte_count > 0) {
    char * const t = malloc(sizeof (char));
    if (t == NULL) {
      exit(EXIT_FAILURE);
    }
    for (unsigned long long i = 0; i < byte_count; i++) {
      swap_byte(p++, q++, t);
    }
    free(t);
  }
}
