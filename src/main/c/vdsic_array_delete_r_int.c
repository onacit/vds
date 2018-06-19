#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <vdsic_array.h>
#include <vdsic_util.h>

#define MIN_ARGC 5

extern void print_int(void * const p) {
  printf("%4d", *(int*) p);
}

extern void print(int intc, int * intv) {
  printf("index: ");
  for (int i = 0; i < intc; i++) {
    printf("%4d", i);
  }
  printf("\n");
  printf("array: ");
  for (int i = 0; i < intc; i++) {
    printf("%4d", *(intv++));
  }
  printf("\n");
}

int main(int argc, char * argv[]) {
  if (argc < MIN_ARGC) {
    fprintf(stderr, "argc(%d) < MIN_ARGC(%d)\n", argc, MIN_ARGC);
    return EXIT_FAILURE;
  }
  unsigned int intc = argc - 1;
  int intv[intc];
  vdsic_array_args_ints(argc, argv, intv);
  print(intc, intv);
  size_t const size = sizeof (int);
  int index;
  int value;

  index = 1;
  printf("\ndeleting at %d\n", index);
  vdsic_array_delete_r(intv, size, intc, index, &value);
  print(intc, intv);
  printf("value: %d\n", value);

  index = intc - 3;
  printf("\ndeleting at %d\n", index);
  vdsic_array_delete_r(intv, size, intc, index, &value);
  print(intc, intv);
  printf("value: %d\n", value);

  index = 0;
  printf("\ndeleting at %d\n", index);
  vdsic_array_delete_r(intv, size, intc, index, &value);
  print(intc, intv);
  printf("value: %d\n", value);

  index = intc - 1;
  printf("\ndeleting at %d\n", index);
  vdsic_array_delete_r(intv, size, intc, index, &value);
  print(intc, intv);
  printf("value: %d\n", value);

  return EXIT_SUCCESS;
}
