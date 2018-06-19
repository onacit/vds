#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <vdsic_array.h>
#include <vdsic_util.h>

extern void print_int(void * const p) {
  printf("%4d", *(int*) p);
}

int main(int const argc, char * argv[]) {
  unsigned int const intc = argc - 1;
  int intv[intc];
  vdsic_array_args_ints(argc, argv, intv);
  size_t const size = sizeof (int);
  vdsic_array_iterate_natural(intv, size, intc, &print_int);
  printf("\n");
  vdsic_array_iterate_reverse(intv, size, intc, &print_int);
  printf("\n");
  return EXIT_SUCCESS;
}
