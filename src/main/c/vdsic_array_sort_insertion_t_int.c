#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <vdsic_array.h>
#include <vdsic_util.h>

int main(int const argc, char * argv[]) {
  size_t const intc = argc - 1;
  int intv[intc];
  vdsic_array_args_ints(argc, argv, intv);
  size_t const size = sizeof (int);
  for (unsigned long i = 0; i < intc; i++) {
    printf("%4d", *(intv + i));
  }
  int const hash1 = vdsic_array_hash_u_int(intv, intc, size);
  printf("\thash1: %d\n", hash1);
  vdsic_array_sort_insertion_t(intv, intc, size, &vdsic_compare_int_natural);
  for (unsigned long i = 0; i < intc; i++) {
    printf("%4d", *(intv + i));
  }
  int const hash2 = vdsic_array_hash_u_int(intv, intc, size);
  printf("\thash2: %d\n", hash2);
  assert(hash2 == hash1);
  vdsic_array_sort_insertion_t(intv, intc, size, &vdsic_compare_int_reverse);
  for (unsigned long i = 0; i < intc; i++) {
    printf("%4d", *(intv + i));
  }
  int const hash3 = vdsic_array_hash_u_int(intv, intc, size);
  printf("\thash3: %d\n", hash3);
  assert(hash3 == hash2);
  return EXIT_SUCCESS;
}
