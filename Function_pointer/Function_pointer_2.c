#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef void (*FuncPtr)();

void showEnglish()
{
	printf("Welcom to my English blog");
}

void showChinese()
{
	printf("Welcom to my Chinese blog");
}

FuncPtr funs[] = {showEnglish, showChinese};

void CommandLine()
{
	printf("cmd>");
}

void TestFunPtr()
{
	int num;
	FuncPtr funPtr;
	while (1)
	{
		printf("\n1) English 2) Chinese \n");
		CommandLine();
		scanf("%d", &num);
		if (num > 2) break;
		funPtr = funs[num - 1];
		funPtr();	
	}
}

int main()
{
	TestFunPtr();
}