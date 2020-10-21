#include <stdlib.h>
#include "cow.h"

Cow *new_cow()
{
	Cow* cow = calloc(1, sizeof(struct COW_STRUCT));
	animal_constructor((Animal*)cow, "Mooh mooh");
	
	return cow;
}