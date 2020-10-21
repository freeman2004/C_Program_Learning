#include <stdio.h>
#include "cow.h"

int main()
{
	Cow* cow = new_cow();
	
	Animal* animal_cow = (Animal*) cow;
	animal_cow->speek(animal_cow);
	
	return 0;
}