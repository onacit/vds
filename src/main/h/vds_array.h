#ifndef VDS_ARRAY_H
#define VDS_ARRAY_H

#ifdef __cplusplus
extern "C" {
#endif

  long vds_array_hash_o(void *, size_t, size_t, long (*)(void *));

  long vds_array_hash_u(void *, size_t, size_t, long (*)(void *));

  // begin, size, length, comparator
  void vds_array_sort_insertion(void *, size_t, size_t, int (*)(void *, void *));
  void vds_array_sort_insertion(void *, size_t, size_t, int (*)(void *, void *));

  void vds_array_sort_selection(void *, size_t, size_t, int (*)(void *, void *));

  void vds_array_sort_merge(void *, size_t, size_t, int (*)(void *, void *));

#ifdef __cplusplus
}
#endif

#endif
