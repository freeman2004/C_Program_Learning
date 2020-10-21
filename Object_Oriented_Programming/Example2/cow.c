#include <stdlib.h>
#include "cow.h"

Cow *new_cow()
{
	Cow* cow = calloc(1, sizeof(struct COW_STRUCT));
	
	Animal* animal = animal_constructor((Animal*)cow, "Mooh mooh");
	cow->speek = animal->speek;
	
	return cow;
}