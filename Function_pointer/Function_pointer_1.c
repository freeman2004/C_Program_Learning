#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void add (int a, int b);
void sub (int a, int b);

typedef struct TEST_TYPE
{
    int numberA;
    int numberB;
} TEST_TYPE;

typedef struct FUN_TYPE
{
    void (*add)(int, int);
    void (*sub)(int, int);
} FUN_TYPE;

typedef struct MESSAGE_STATE_TYPE
{
    TEST_TYPE number;
	FUN_TYPE fun;
} MESSAGE_STATE_TYPE;

TEST_TYPE system_state =
{
    .numberA =        3,
    .numberB =        2,
};

FUN_TYPE system_func =
{
    .add = add,
    .sub = sub,
};

// callback function 
void Add(MESSAGE_STATE_TYPE *para, void (*add)(int, int)) 
{ 
    (*add) (para->number.numberA, para->number.numberB); // callback to A 
} 

// callback function 
void Sub(MESSAGE_STATE_TYPE *para, void (*Sub)(int, int)) 
{ 
    (*Sub) (para->number.numberA, para->number.numberB); // callback to A 
} 

int main( int argc, char *argv[] )
{
	MESSAGE_STATE_TYPE para;
	para.number = system_state;
	para.fun = system_func;
	Add(&para, para.fun.add);
	Sub(&para, para.fun.sub);
	
    return 0;
}

void add (int a, int b)
{
	int c;
	c = a + b;
	printf("c=%d \n",c);

}

void sub (int a, int b)
{
	int c;
	c = a - b;
	printf("c=%d \n",c);
}