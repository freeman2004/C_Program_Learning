#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *Data1 [] = {"11:22:33:44:55:66","22:33:44:55:66:77","33:44:55:66:77:88"};
#define Row (sizeof(Data1) / sizeof(Data1[0]))

struct List
{
	char *MAC[Row];
	struct List *next;
};

typedef struct List Node;
typedef Node *Link;



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

Link Create_CList(Link Head, char (**Data), int Max)
{
	Link New;
	Link Pointer;
	int i;
	
	Head = (Link) malloc (sizeof(Node));
	
	if (Head == NULL)
		printf("Memory allocate failure!!\n");
	else
	{
		Head->MAC[0] = Data[0];
		Head->next = NULL;
		Pointer = Head;
		
		for (i = 1; i < Max; i++)
		{
			New = (Link) malloc (sizeof(Node));

			New->MAC[i] = Data[i];
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
	int i = 0;
	Link Pointer;
	Pointer = Head;
	printf ("Input Data :\n");
	
	do
	{
		printf("[%s]", Pointer->MAC[i]);
		Pointer = Pointer->next;
		i++;
	} while (Pointer != Head);
	
	printf("\n");
}

int main()
{
	Link Head;

	Head = Create_CList(Head, &(*Data1), Row);
	Print_CList(Head);
	Free_Clist(Head);
}