#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct List
{
	int Num;
	struct List *next;
};

typedef struct List Node;
typedef Node *Link;

#define Max1 10
int Data1 [Max1] = {1,2,3,4,5,6,7,8,9,0};

void Free_Clist(Link Head)
{
	
	Link Pointer;
	Link Next;
	
	Next = Head->next;
	
	while (Next != Head)
	{
		Pointer = Next;
		Next = Next->next;
		free(Pointer);
	}
	free(Head);
}

Link Insert_CList(Link Head, Link New, int Key)
{
	Link Pointer;
	Link Last;
	
	Pointer = Head;
	
	while (1)
	{
		if (Pointer->Num == Key)
		{
			New->next = Pointer->next;
			Pointer->next = New;
			break;
		}
		
		if (Pointer->Num != Key && Pointer->next == Head)
		{
			New->next = Pointer->next;
			Pointer->next = New;
			Head = New;
			break;
		}
		
		Pointer = Pointer->next;
	}
	return Head;
}

Link Create_CList(Link Head, int *Data, int Max)
{
	Link New;
	Link Pointer;
	int i;
	
	Head = (Link) malloc (sizeof(Node));
	
	if (Head == NULL)
		printf("Memory allocate failure!!\n");
	else
	{
		Head->Num = Data[0];
		Head->next = NULL;
		
		Pointer = Head;
		
		for (i = 1; i < Max; i++)
		{
			New = (Link) malloc (sizeof(Node));
			
			New->Num = Data[i];
			New->next = NULL;
			
			Pointer->next = New;
			Pointer = New;
		}
		Pointer->next = Head;
	}
	
	return Head;
}

void Print_CList(Link Head)
{
	Link Pointer;
	Pointer = Head;
	printf ("Input Data :\n");
	
	do
	{
		printf("[%d]", Pointer->Num);
		Pointer = Pointer->next;
	} while (Pointer != Head);
	
	printf("\n");
}

int main()
{
	Link Head;
	Link New;
	int key;
	
	Head = Create_CList(Head, Data1, Max1);
	Print_CList(Head);
	
}