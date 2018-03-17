// Author: John Gauthier
// Description: Reverse engineered IA32 code to create this C code
// Sources: course/assignment material

#include <stdio.h>

int decode(int x, int y, int z) {
	//Collaborated with Rafael Yehuda for this part.
	//Produces the expected return value, but for some reason
	//the %edx and %eax registers are switched in some of the 
	//instructions such as the 2nd movl

	y = y - z;

	x = x * y;

	y = y << 31;

	y = y >> 31;

	return x ^ y;
}


void main(void) {
	//test
	printf("%d\n", decode(-4, -8,-12));
}