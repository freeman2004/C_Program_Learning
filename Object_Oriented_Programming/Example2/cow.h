#ifndef __COW_H__
#define __COW_H__

#include "animal.h"

typedef struct COW_STRUCT
{
	Animal base;
	void (*speek)(Animal* animal);
} Cow;

Cow *new_cow();
#endif