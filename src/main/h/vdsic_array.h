#ifndef VDSIC_ARRAY_H
#define VDSIC_ARRAY_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

  void vdsic_array_args_ints(unsigned int, char * * restrict, int * restrict);

  void vdsic_array_args_longs(unsigned int, char * *, unsigned int, long *);


  int vdsic_array_validate(void * restrict, size_t, size_t);


  // offset, size, count, index -> value
  void vdsic_array_get(void * restrict, size_t, size_t, size_t, void *);

  // offset, size, count
  void vdsic_array_get_set(void * restrict, size_t, size_t, size_t, void * restrict, void * restrict);

  // offset, count, size, index, value
  void vdsic_array_set(void * restrict, size_t, size_t, size_t, void * restrict);


  // offset, size, count
  void vdsic_array_shift_l(void * restrict, size_t, size_t);

  // offset, size, count
  void vdsic_array_shift_r(void * restrict, size_t, size_t);

  
  // offset, size, count, index
  //void vdsic_array_delete(void * restrict, size_t, size_t, size_t);

  //void vdsic_array_delete_shift_l(void * restrict, size_t, size_t, size_t, void (*)(void *));
  void vdsic_array_delete_l(void * restrict, size_t, size_t, size_t, void *);

  //void vdsic_array_delete_r(void * restrict, size_t, size_t, size_t, void (*)(void *));
  // offset, size, count, old
  void vdsic_array_delete_r(void * restrict, size_t, size_t, size_t, void *);

  // offset, size, count, index, value
  void vdsic_array_insert(void * restrict, size_t, size_t, size_t, void * restrict);


  // with: offset, count, size, accept
  void vdsic_array_iterate_natural(void *, size_t, size_t, void (*)(void *));

  // with: offset, count, size, accept
  void vdsic_array_iterate_reverse(void *, size_t, size_t, void (*)(void *));

  //offset, count, size, identity, operator
  //  void vdsic_array_reduce_natural(void * restrict, size_t, size_t, void * restrict, void (*)(void *, void *));

  //void vdsic_array_reduce(void *, size_t, size_t, void (*)(void *, void *));




  long vdsic_array_hash_o(void *, size_t, size_t, long (*)(void *));
  long vdsic_array_hash_u(void *, size_t, size_t, long (*)(void *));

  long vdsic_array_hash_o_int(void *, size_t, size_t);
  long vdsic_array_hash_u_int(void *, size_t, size_t);

  long vdsic_array_hash_o_long(void *, size_t, size_t);
  long vdsic_array_hash_u_long(void *, size_t, size_t);


  //void vdsic_array_insert(void *, size_t, size_t, size_t, void *);



  // begin, size, length, comparator
  void vdsic_array_sort_insertion(void *, size_t, size_t, int (*)(void *, void *));
  void vdsic_array_sort_insertion_t(void *, size_t, size_t, int (*)(void *, void *));

  void vdsic_array_sort_selection(void *, size_t, size_t, int (*)(void *, void *));

  void vdsic_array_sort_merge_td(void *, size_t, size_t, int (*)(void *, void *));






  // with offset, count, size, target, compare
  // returns matched pointer
  void * vdsic_array_search_linear(void *, size_t, size_t, void *,
          int (*)(void *, void *));

  // with: offset, count, size, target, compare, accept
  // returns: matched pointer
  void * vdsic_array_search_binary(void *, size_t, size_t, void *,
          int (*)(void *, void *));

#ifdef __cplusplus
}
#endif

#endif
