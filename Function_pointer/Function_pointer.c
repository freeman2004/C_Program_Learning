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
    TEST_TYPE states;
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

void calc(MESSAGE_STATE_TYPE *para)
{
 para->fun.add(para->states.numberA, para->states.numberB);
}

void Add()
{
    MESSAGE_STATE_TYPE para;

    para.states = system_state;
 para.fun = system_func;

 calc(&para);
}

int main( int argc, char *argv[] )
{
 Add();

    return 0;
}

void add (int a, int b)
{
 int c;
 c = a + b;
 printf("c=%d",c);

}

void sub (int a, int b)
{
 int c;
 c = a - b;
 printf("c=%d",c);
}