#include <stdio.h>

int main(void)
{
	char str1[5];
	char str2[100];
	// fgets(str1, 5, stdin);
	// fgets(str2, 100, stdin);

	gets(str1);
	gets(str2);

	// gets_s(str1, 5);
	// gets_s(str2, 100);

	printf("[%s]\n", str1);
	printf("[%s]\n", str2);

	return 0;
}

/**

Hel
lo World!
Line 2!

*/