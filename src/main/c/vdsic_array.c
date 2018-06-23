#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vdsic_array.h>
#include <vdsic_util.h>

/*
void vdsic_array_args_ints(unsigned int const argc, char * * const argv,
                           unsigned int intc, int * intv) {
  int const count = fmin(argc, intc + 1);
  for (int i = 1; i < count; i++) {
    if (sscanf(argv[i], "%i", intv++) != 1) {
      fprintf(stderr, "failed to parse argument at %d\n", i);
    }
  }
 }
 */

void vdsic_array_args_ints(unsigned int const argc, char * * const argv,
                           int * intv) {
  for (unsigned int i = 1; i < argc; i++) {
    if (sscanf(argv[i], "%i", intv++) != 1) {
      fprintf(stderr, "failed to parse argument at %d\n", i);
    }
  }
}

void vdsic_array_args_longs(unsigned int const argc, char * * const argv,
                            unsigned int longc, long * longv) {
  int const count = fmin(argc, longc + 1);
  for (int i = 1; i < count; i++) {
    *(longv++) = strtol(argv[i], NULL, 0);
  }
}

/*
int vdsic_array_validate(void * restrict const offset, size_t const count,
                         size_t const size) {
  if (offset == NULL) {
    return -1;
  }
  if (count == 0) {
    return -1;
  }
  if (size == 0) {
    return -1;
  }
  return 0;
}
 */

void * vdsic_array_limit(void * restrict const offset, size_t const size,
                         size_t const count) {
  return (char *) offset + (size * count);
}

void vdsic_array_get(void * restrict const offset, size_t const size,
                     size_t const count, size_t const index,
                     void * const value) {
  if (index >= count) {
    return;
  }
  memcpy(value, (char*) offset + (size * index), size);
}

void vdsic_array_get_set(void * restrict const offset, size_t const size,
                         size_t const count, size_t const index,
                         void * restrict const old, void * restrict const new) {
  if (index >= count) {
    return;
  }
  if (old != NULL) {
    vdsic_array_get(offset, size, count, index, old);
  }
  memcpy(((char *) offset) + (size * index), new, size);
}

void vdsic_array_set(void * restrict const offset, size_t const size,
                     size_t const count, size_t const index,
                     void * restrict const value) {
  if (index >= count) {
    return;
  }
  vdsic_array_get_set(offset, size, count, index, NULL, value);
}

void vdsic_array_iterate_natural(void * const offset, size_t const size,
                                 size_t const count, void (* accept)(void *)) {
  char * const limit = (char *) offset + size * count;
  for (char * i = (char *) offset; i < limit; i += size) {
    accept(i);
  }
}

void vdsic_array_iterate_reverse(void * const offset, size_t const size,
                                 size_t const count, void (* accept)(void *)) {
  char * const limit = (char *) offset + size * count;
  for (char * i = limit - size; i >= (char *) offset; i -= size) {
    accept(i);
  }
}

void vdsic_array_shift_l(void * const offset, size_t const size,
                         size_t const count) {
  char * const limit = vdsic_array_limit(offset, size, count);
  char * s2 = offset;
  char * s1 = s2 + size;
  for (; s1 < limit; s1 += size) {
    s2 = ((char*) memcpy(s2, s1, size)) + size;
  }
}

void vdsic_array_shift_r(void * const offset, size_t const size,
                         size_t const count) {
  char * const limit = vdsic_array_limit(offset, size, count);
  char * s2 = limit - size;
  char * s1 = s2 - size;
  for (; s1 >= (char *) offset; s1 -= size) {
    s2 = ((char *) memcpy(s2, s1, size)) - size;
  }
}

/*
void vdsic_array_delete(void * const offset, size_t const size,
                        size_t const count, size_t const index) {
  char * const limit = (char *) offset + size * count;
  for (char * i = (char *) offset + index * size; i < limit; i += size) {
    memcpy(i - size, i, size);
  }
}
 */

void vdsic_array_delete_l(void * const offset, size_t const size,
                          size_t const count, size_t const index,
                          void * const old) {
  if (index >= count) {
    return;
  }
  if (old != NULL) {
    vdsic_array_get(offset, size, count, index, old);
  }
  vdsic_array_shift_l(((char *) offset) + (size * index), size, count - idex);
}

void vdsic_array_delete_r(void * const offset, size_t const size,
                          size_t count, size_t const index, void * const old) {
  if (old != NULL) {
    vdsic_array_get(offset, size, count, index, old);
  }
  count = index + 1;
  vdsic_array_shift_r(offset, size, count);
}

void vdsic_array_insert(void * const offset, size_t const size,
                        size_t const count, size_t const index,
                        void * const value) {
  char * const p = (char *) offset + size * index;
  for (char * i = (char *) offset + size * (count - 2); i >= p; i -= size) {
    memcpy(i + size, i, size);
  }
  memcpy(p, value, size);
}



//void vdsic_array_reduce_natural(void * const offset, size_t const count, size_t const size, void * restrict identity, void (* const accumulate) (void *, void *)) {
//  void * reduced = NULL;
//}

long vdsic_array_hash_o(void * array, size_t const count, size_t const size,
                        long (* const hash) (void *)) {
  long result = 7L;
  void * const limit = ((char *) array) + (count * size);
  for (; array < limit; array = ((char *) array) + size) {
    result = result * 31 + hash(array);
  }
  return result;
}

long vdsic_array_hash_u(void * array, size_t const count, size_t const size,
                        long (* const hash) (void *)) {
  long result = 0L;
  void * const limit = ((char *) array) + (count * size);
  for (; array < limit; array = ((char *) array) + size) {
    result += vdsic_array_hash_o(array, 1LLU, size, hash);
  }
  return result;
}

long vdsic_array_hash_o_int(void * const array, size_t const count,
                            size_t const size) {
  return vdsic_array_hash_o(array, count, size, &vdsic_hash_int);
}

long vdsic_array_hash_u_int(void * const array, size_t const count,
                            size_t const size) {
  return vdsic_array_hash_u(array, count, size, &vdsic_hash_int);
}

long vdsic_array_hash_o_long(void * const array, size_t const count,
                             size_t const size) {
  return vdsic_array_hash_o(array, count, size, &vdsic_hash_long);
}

long vdsic_array_hash_u_long(void * const array, size_t const count,
                             size_t const size) {
  return vdsic_array_hash_u(array, count, size, &vdsic_hash_long);
}



//void vdsic_array_insert(void * offset, size_t const count, size_t const size, size_t index, void * value) {
//}

void vdsic_array_sort_insertion(void * const offset, size_t const count,
                                size_t const size,
                                int (* const compare) (void *, void *)) {
  char * const limit = ((char *) offset) + (count * size);
  for (char * i = ((char *) offset) + size; i < limit; i += size) {
    for (char * j = i - size; j >= (char *) offset; j -= size) {
      if (compare(j, j + size) <= 0) {
        break;
      }
      vdsic_swap_block(j + size, j, size);
    }
  }
}

void vdsic_array_sort_insertion_t(void * const offset, size_t const length,
                                  size_t const size,
                                  int (* const compare) (void *, void *)) {
  void * t = malloc(size);
  if (t == NULL) {
    exit(EXIT_FAILURE);
  }
  char * const limit = ((char *) offset) + (length * size);
  for (char * i = ((char *) offset) + size; i < limit; i += size) {
    memcpy(t, i, size);
    for (char * j = i - size; j >= (char *) offset; j -= size) {
      if (compare(j, t) <= 0) {
        memmove(j + size, t, size);
        break;
      }
      memcpy(j + size, j, size);
    }
  }
  free(t);
}

void vdsic_array_sort_selection(void * const offset, size_t const count,
                                size_t const size,
                                int (* const compare) (void *, void *)) {
  char * const limit = ((char *) offset) + (count * size);
  for (char * i = offset; i < (limit - size); i += size) {
    void * minimum = i;
    for (char * j = i + size; j < limit; j += size) {
      if (compare(minimum, j) > 0) {
        minimum = j;
      }
    }
    if (minimum != i) {
      vdsic_swap_block(i, minimum, size);
    }
  }
}

void vdsic_array_sort_merge_td_t(void * const array, size_t const count,
                                 size_t const size,
                                 int (* const compare) (void *, void *),
                                 void * space) {
  if (count == 1) {
    return;
  }
  char * array_l = array;
  size_t const count_l = count / 2;
  vdsic_array_sort_merge_td_t(array_l, count_l, size, compare, space);
  char * array_r = ((char*) array) + count_l * size;
  size_t const count_r = count - count_l;
  vdsic_array_sort_merge_td_t(array_r, count_r, size, compare, space);
  memcpy(space, array_l, count_l * size);
  array_l = space;
  char * const limit_l = array_l + count_l * size;
  char * const limit_r = array_r + count_r * size;
  char * const limit = limit_r;
  for (char * i = array; i < limit; i += size) {
    void * const l = array_l < limit_l ? array_l : NULL;
    void * const r = array_r < limit_r ? array_r : NULL;
    assert(l != NULL || r != NULL);
    if (r == NULL || (l != NULL && compare(l, r) < 0)) {
      memcpy(i, l, size);
      array_l += size;
    } else { // r != NULL && (l == NULL || compare(l, r) >= 0)
      memcpy(i, r, size);
      array_r += size;
    }
  }
}

void vdsic_array_sort_merge_td(void * const array, size_t const count,
                               size_t const size,
                               int (* const compare) (void *, void *)) {
  void * const space = malloc((count / 2) * size);
  if (space == NULL) {
    exit(EXIT_FAILURE);
  }
  vdsic_array_sort_merge_td_t(array, count, size, compare, space);
  free(space);
}

void * vdsic_array_search_linear(void * const offset, size_t const count,
                                 size_t const size, void * const target,
                                 int (* compare)(void *, void *)) {
  char * const limit = (char *) offset + (count * size);
  size_t index = 0;
  for (char * pointer = offset; pointer < limit; pointer += size) {
    if (compare(pointer, target) == 0) {
      return pointer;
    }
    index++;
  }
  return NULL;
}

void * vdsic_array_search_binary(void * const offset, size_t const count,
                                 size_t const size, void * const target,
                                 int (* compare)(void *, void *)) {
  char * left = offset;
  char * right = (char *) offset + ((count - 1) * size);
  char * middle;
  int compared;
  while (left <= right) {
    middle = left + (right - left) / 2;
    compared = compare(middle, target);
    if (compared < 0) {
      left = middle + size;
    } else if (compared > 0) {
      right = middle - size;
    } else {
      return middle;
    }
  }
  return NULL;
}

