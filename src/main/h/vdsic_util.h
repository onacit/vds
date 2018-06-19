#ifndef VDSIC_UTIL_H
#define VDSIC_UTIL_H

#ifdef __cplusplus
extern "C" {
#endif

  void vdsic_accept_int_println(void *);


  int vdsic_compare_int_natural(void *, void *);

  int vdsic_compare_int_reverse(void *, void *);
  


  long vdsic_hash_int(void *);

  long vdsic_hash_long(void *);


  void vdsic_swap_byte(char *, char *, char *);

  void vdsic_swap_bytes(char *, char *, size_t);


  void vdsic_swap_word(void *, void *, size_t, void *);

  void vdsic_swap_words(void *, void *, size_t, size_t);


  void vdsic_swap_block(void *, void *, size_t);

#ifdef __cplusplus
}
#endif

#endif
