#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <vdsic_array.h>
#include <vdsic_util.h>

#define MIN_ARGC 3

int main(int const argc, char * argv[]) {
  if (argc < MIN_ARGC) {
    fprintf(stdout, "insufficient number of arguments; %d < %d\n", argc,
            MIN_ARGC);
    return EXIT_FAILURE;
  }
  unsigned int const intc = argc - 1;
  int intv[intc];
  vdsic_array_args_ints(argc, argv, intv);
  int const index = intv[intc - 1];
  size_t const size = sizeof (int);
  int value;
  vdsic_array_get(intv, size, intc - 1, index, &value);
  printf("value at %d is %d.\n", index, value);
  return EXIT_SUCCESS;
}
