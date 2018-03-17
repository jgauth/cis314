// Author: John Gauthier
// Description: Uses bitwise ops to combine unsigned ints
// Sources: course/assignment material

#include <stdio.h>

unsigned int combine(unsigned int x, unsigned int y) {

	//AND operation to assign most significant byte from x to an unsigned int
	//AABBCCDD to AA000000
	unsigned int left = x & 0xFF000000;

	//AND operation to assign the 3 least significant bytes from y to an unsigned int
	//AABBCCDD to 00BBCCDD
	unsigned int right = y & 0x00FFFFFF;

	printf("%X\n", left | right);

	//OR operation to combine the left and right bytes
	return left | right;
}

int main() {
	
	//Tests
	combine(0x12345678, 0xABCDEF00);
	combine(0xABCDEF00, 0x12345678);
}
