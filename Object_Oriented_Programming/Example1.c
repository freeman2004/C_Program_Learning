#include<stdio.h>
#include<stdlib.h>

static const int MaxLength = 1000;

typedef struct
{
	int *data;
	size_t count;
}ListAdmin;

ListAdmin* InitialiseList()
{
	
	ListAdmin* this = malloc(sizeof(*this));
	this->data = malloc (MaxLength * sizeof(*(this->data)));
	this->count = 0;
	
	return this;
}

void DestroyList(ListAdmin* thisptr)
{
	free(thisptr->data);
	thisptr->data = NULL;
	free(thisptr);
	thisptr = NULL;
}

size_t ListCount(ListAdmin* this)
{
	return this->count;
}

int ListAdd(ListAdmin* this, int item)
{
	if(this->count >= MaxLength)
	{
		return -1;
	}
	
	this->data[this->count++] = item;
	return 0;
}

int ListGet(ListAdmin* this, size_t index, int* item)
{
	if(index >= this->count)
	{
		return -1;
	}
	
	*item = this->data[index];
	return 0;
}

void ListRemoveAt(ListAdmin* this, size_t index)
{
	size_t i;
	for(i = index + 1; i < this->count; i++)
	{
		this->data[i - 1] = this->data[i];
	}
	this->count--;
}

int ListRemove(ListAdmin* this, int item)
{
	size_t i = 0;
	for (i = 0; i < this->count; i++)
	{
		if(this->data[i] == item)
		{
			ListRemoveAt(this, i);
			return 0;
		}
	}
	
	return -1;
}

void ListClear(ListAdmin* this)
{
	this->count = 0;
}

int main(void)
{
	ListAdmin* list1 = InitialiseList();
	ListAdmin* list2 = InitialiseList();
	
	ListAdd(list1, 1);
	ListAdd(list1, 2);
	ListAdd(list1, 3);
	ListAdd(list1, 4);
	ListAdd(list1, 5);
	ListAdd(list1, 6);


	//printf("List2 is still empty: %lu items\n",listCount());
	size_t i;
	for (i = 0; i < ListCount(list1); i++)
	{
		int value;
		ListGet(list1, i ,&value);
		printf("item %lu is: %d\n",i , value);
	}
	
	printf("removing from list 1: %s \n", (0 == ListRemove(list1, 4))?"True":"False");
	
	for (i = 0; i < ListCount(list1); i++)
	{
		int value;
		ListGet(list1, i ,&value);
		printf("item %lu is: %d\n",i , value);
	}
	
	return 0 ;
}
