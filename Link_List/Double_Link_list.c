#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct DList
{
	struct DList *back;
	int Num;
	struct DList *next;
};

typedef struct DList DNode;
typedef DNode *DLink;

#define Max1 10
int Data1 [Max1] = {1,2,3,4,5,6,7,8,9,0};

void Free_DList(DLink Head)
{
	DLink Pointer;
	
	while (Head != NULL)
	{
		Pointer = Head;
		Head = Head->next;
		free(Pointer);
	}
	free(Head);
}

DLink Create_DList(DLink Head, int *Data, int Max)
{
	DLink New;
	DLink Pointer;
	int i;
	
	Head = (DLink) malloc (sizeof(DNode));
	
	if (Head == NULL)
		printf("Memory allocate failure!!\n");
	else
	{
		Head->back = NULL;
		Head->Num = Data[0];
		Head->next = NULL;
		
		Pointer = Head;
		
		for (i = 1; i < Max; i++)
		{
			
			New = (DLink) malloc (sizeof(DNode));
			
			New->back = NULL;
			New->Num = Data[i];
			New->next = NULL;
			
			Pointer->next = New;
			New->back = Pointer;
			Pointer = New;
		}
	}
	
	return Head;
}

void Print_DList(DLink Head)
{
	DLink Pointer;
	Pointer = Head;
	printf ("Input Data :\n");
	
	do
	{
		printf("[%d]", Pointer->Num);
		Pointer = Pointer->next;
	} while (Pointer != NULL);
	
	printf("\n");
}

int main()
{
	DLink Head = NULL;
	
	Head = Create_DList(Head, Data1, Max1);
	if (Head != NULL)
		Print_DList(Head);
	Free_DList(Head);
}