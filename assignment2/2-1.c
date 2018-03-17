// Author: John Gauthier
// Description: Uses bitwise ops to return a bit-mask of the least significant n bits
// Sources: course/assignment material

#include <stdio.h>

int mask(int n) {
	
	//shifting 0x2 left (n-1) results in some power of 2. subtracting 1 from 
	//a power of 2 results in every bit being 1, up to that power of 2.
	//eg 0b01000 - 1 = 0b00111
	int mask = (0x2 << n-1) - 1; 

	// printf("%08X\n", mask);

	return mask;
}

int main() {
	
	//tests
	mask(1);
	mask(2);
	mask(3);
	mask(5);
	mask(8);
	mask(16);
	mask(32);
}
