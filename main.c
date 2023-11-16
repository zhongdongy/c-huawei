#include <stdio.h>
#define MSG "Hello World!";

int main(void)
{
	char *str_p = "Hello World!";
	char str_arr[] = "Hello World!";
	char *msg_p = MSG;
	char msg_arr[] = MSG;

	printf("Source\t\tPtr Addr.\tPtr Target Addr.\tTarget String\n");
	printf("[str_p]\t\t%p\t%p\t\t%s\n", &str_p, str_p, str_p);
	printf("[str_arr]\t%p\t%p\t\t%s\n", &str_arr, str_arr, str_arr);
	printf("[msg_p]\t\t%p\t%p\t\t%s\n", &msg_p, msg_p, msg_p);
	printf("[msg_arr]\t%p\t%p\t\t%s\n", &msg_arr, msg_arr, msg_arr);

	return 0;
}