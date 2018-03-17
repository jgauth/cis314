// Author: John Gauthier
// Description: Uses bitwise ops to return specific bytes of an unsigned int
// Sources: course/assignment material

#include <stdio.h>

unsigned int extract(unsigned int x, int i) {

	//Shifting i << 3 gives the location of the byte represented by i
	//Subtract that from 24 to get the number of bits to shift that location to the MSB
	unsigned int offset = 24 - (i << 3);

	//Shift byte i of x to the MSB
	int MSB = x << offset;

	//Shift the MSB to the LSB to give i of x sign extended to 32 bits
	MSB >>= 24;

	printf("%08X\n", MSB);

	return MSB;
}

int main() {

	//tests
	extract(0x12345678, 0);
	extract(0xABCDEF00, 2);
	extract(0x8F000000, 3);
}
