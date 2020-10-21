#include <stdio.h>
#include "cow.h"

int main()
{
	Cow* cow = new_cow();
	cow->speek((Animal*)cow);
	
	return 0;
}