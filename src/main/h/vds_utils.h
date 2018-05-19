#ifndef VDS_UTILD_H
#define VDS_UTILD_H

#ifdef __cplusplus
extern "C" {
#endif
  
  
  int comparel(long, long);

  int comparelu(unsigned long, unsigned long);

  int comparell(long long, long long);

  int comparellu(unsigned long long, unsigned long long);


  int comparelp(long *, long *);

  int comparelup(unsigned long *, unsigned long *);

  int comparellp(long long *, long long *);

  int comparellup(unsigned long long *, unsigned long long *);



  void swap_byte(char *, char *, char *);

  void swap_block(void *, void *, size_t);

  void swap_block_w(void *, void *, size_t);

#ifdef __cplusplus
}
#endif

#endif
