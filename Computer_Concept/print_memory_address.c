#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct List
{
	int Num;
	struct List *next;
	int test;
}a;


int main()
{
	printf("%p \n", &a);
	printf("%p \n", &a.Num);
	printf("%p \n", &a.next);
	printf("%p \n", &a.test);
}