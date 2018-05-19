#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vds_swap.h>

void vds_swap_byte(void * a, void * b, void * t) {
  *((char *) t) = *((char *) a);
  *((char *) a) = *((char *) b);
  *((char *) b) = *((char *) t);
}

void vds_swap_bytes(void * a, void * b, size_t const s) {
  char * const t = malloc(sizeof (char));
  if (t == NULL) {
    exit(EXIT_FAILURE);
  }
  for (unsigned long long i = 0; i < s; i++) {
    vds_swap_byte(a, b, t);
    a = ((char *) a) + 1;
    b = ((char *) b) + 1;
  }
  free(t);
}

void vds_swap_word(void * const a, void * const b, size_t const s, void * const t) {
  memcpy(t, a, s);
  memcpy(a, b, s);
  memcpy(b, t, s);
}

void vds_swap_words(void * a, void * b, size_t const s, size_t const c) {
  void * const t = malloc(s);
  if (t == NULL) {
    exit(EXIT_FAILURE);
  }
  for (unsigned long long i = 0; i < c; i++) {
    vds_swap_word(a, b, s, t);
    a = ((char *) a) + s;
    b = ((char *) b) + s;
  }
  free(t);
}

void vds_swap_block(void * const a, void * const b, size_t const s) {
  size_t const word_s = sizeof (long);
  size_t const word_c = s / word_s;
  if (word_c > 0LLU) {
    vds_swap_words(a, b, word_s, word_c);
  }
  size_t const byte_c = s % word_s;
  if (byte_c > 0LLU) {
    vds_swap_bytes(a, b, byte_c);
  }
}
