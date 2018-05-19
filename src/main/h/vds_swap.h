#ifndef VDSC_SWAP_H
#define VDSC_SWAP_H

#ifdef __cplusplus
extern "C" {
#endif

  void vds_swap_byte(void *, void *, void *);
  
  //void vds_swap_byte(void *, void *);
  
  void vds_swap_bytes(void *, void *, size_t);


  void vds_swap_word(void *, void *, size_t, void *);

  //void vds_swap_word(void *, void *, size_t);

  void vds_swap_words(void *, void *, size_t, size_t);


  void vds_swap_block(void *, void *, size_t);

#ifdef __cplusplus
}
#endif

#endif
