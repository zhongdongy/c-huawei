#include <stdio.h>
#include "libs/sorting.h"
#include "libs/utils.h"

int main(void)
{

  int ar[] = {4, 2, 1, 3, 6, 5, 8, 7};
  printf("Before:\t");
  print_array(ar, 8);

  quick_sort_desc(ar, 8);

  printf("After:\t");
  print_array(ar, 8);

  return 0;
}