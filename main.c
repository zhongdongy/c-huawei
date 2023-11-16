#include <stdio.h>
#include "libs/sorting.h"
#include "libs/utils.h"
#include "libs/string.h"

// int main(void)
// {
//   char str[] = "Hello World!";
//   printf("Before:\t'%s'\n", str);
//   str_sort(str, 13);
//   printf("After:\t'%s'\n", str);

//   return 0;
// }

int main(void)
{
	char *str = "Hello World!";
	printf("%s\n", str);
	str[6] = 'w';
	printf("%s\n", str);
	return 0;
}