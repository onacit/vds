#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <vdsic_array.h>
#include <vdsic_util.h>

#define MIN_ARGC 4

int main(int const argc, char * argv[]) {
  if (argc < MIN_ARGC) {
    fprintf(stderr, "insufficient number of arguments; %d < %d", argc,
            MIN_ARGC);
    return EXIT_FAILURE;
  }
  unsigned int const intc = argc - 1;
  int intv[intc];
  vdsic_array_args_ints(argc, argv, intv);
  printf("array: ");
  for (unsigned int i = 0; i < intc - 2; i++) {
    printf("%4d", *(intv + i));
  }
  printf("\n");
  unsigned int const index = intv[intc - 2];
  int old;
  int new = intv[intc - 1];
  printf("index: %4d\n", index);
  printf("  new: %4d\n", new);
  vdsic_array_get_set(intv, sizeof (int), intc - 2, index, &old, &new);
  printf("  old: %4d\n", old);
  printf("array: ");
  for (unsigned int i = 0; i < intc - 2; i++) {
    printf("%4d", *(intv + i));
  }
  printf("\n");
  return EXIT_SUCCESS;
}
