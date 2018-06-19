#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vdsic_util.h>

void vdsic_accept_int_println(void * const p) {
  printf("%d\n", *((int *) p));
}

int vdsic_compare_int_natural(void * restrict const a,
                              void * restrict const b) {
  int const p = *((int *) a);
  int const q = *((int *) b);
  return p < q ? -1 : p == q ? 0 : 1;
}

int vdsic_compare_int_reverse(void * restrict const a,
                              void * restrict const b) {
  return vdsic_compare_int_natural(b, a);
}

long vdsic_hash_int(void * const a) {
  return *((int *) a);
}

long vdsic_hash_long(void * const a) {
  return *((long *) a);
}

void vdsic_swap_byte(char * restrict a, char * restrict b, char * restrict t) {
  *t = *a;
  *a = *b;
  *b = *t;
}

void vdsic_swap_bytes(char * restrict a, char * restrict b, size_t const c) {
  char * const t = malloc(sizeof (char));
  if (t == NULL) {
    exit(EXIT_FAILURE);
  }
  for (size_t i = 0; i < c; i++) {
    vdsic_swap_byte(a++, b++, t);
  }
  free(t);
}

void vdsic_swap_word(void * restrict const a, void * restrict const b,
                     size_t const s, void * restrict const t) {
  memcpy(t, a, s);
  memcpy(a, b, s);
  memcpy(b, t, s);
}

void vdsic_swap_words(void * restrict a, void * restrict b, size_t const s,
                      size_t const c) {
  void * const t = malloc(s);
  if (t == NULL) {
    exit(EXIT_FAILURE);
  }
  for (size_t i = 0; i < c; i++) {
    vdsic_swap_word(a, b, s, t);
    a = ((char *) a) + s;
    b = ((char *) b) + s;
  }
  free(t);
}

void vdsic_swap_block(void * restrict a, void * restrict b, size_t const s) {
  size_t const word_s = sizeof (long);
  size_t const word_c = s / word_s;
  if (word_c > 0) {
    vdsic_swap_words(a, b, word_s, word_c);
  }
  size_t const byte_c = s % word_s;
  if (byte_c > 0) {
    a = ((char *) a) + (word_s * word_c);
    b = ((char *) b) + (word_s * word_c);
    vdsic_swap_bytes(a, b, byte_c);
  }
}