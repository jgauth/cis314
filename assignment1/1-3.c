#include <stdio.h>

unsigned int replace(unsigned int x, int i, unsigned char b) {

	//Create variable with correct location of the byte to be replaced
	//0 << 3 = 0, 1 << 3 = 8, 2 << 3 = 16, 3 << 3 = 24
	//Shiting over 3 bits its like multiplying by 8 because 2^3 = 8
	unsigned int location = i << 3;

	//Create a mask to change the desired byte to 0x00
	unsigned int FF = 0x000000FF << location;

	//AND x and NOT FF to replace the byte at the desired location to 0x00
	x = x & ~FF;

	//Move the replacement byte to the correct location
	unsigned int y = b << location;

	printf("%X\n", (x|y));
	
	//OR the replacement byte with x. Works because the byte to be replaced is currently 0x00
	return x | y;
}

int main() {

	//Tests
	replace(0x12345678, 2,  0xAB);//0x12AB5678
	replace(0x12345678, 0, 0xAB);//0x123456AB
}