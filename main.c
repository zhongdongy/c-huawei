#include <stdio.h>
#include "./libs/string.h"
#include "./libs/utils.h"
#include "./libs/sorting.h"

int main(void)
{
	char str_arr[] = "Hello World!";
	printf("Before:\t%s\n", str_arr);
	str_sort_desc(str_arr, 13);
	printf("After:\t%s\n", str_arr);

	return 0;
}