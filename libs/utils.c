#include "utils.h"
#include <stdio.h>

void print_array(int ar[], int length)
{
  int i;
  printf("[");
  for (i = 0; i < length; i++)
  {
    printf(" %d", ar[i]);
    if (i < length - 1)
    {
      printf(",");
    }
  }
  printf(" ]\n");
}