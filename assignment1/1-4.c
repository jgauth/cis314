#include <stdio.h>

int even(unsigned int x) {

	//Uses bit mask to isolate the evens.
	//Used 0x55555555 because it corresponds to 1s in even spots and 0s in odd (0b01010101...0101)
	unsigned int mask = 0x55555555;

	//AND the mask and x to remove 1s that are in an odd spot
	unsigned int isolatedEvens = x & mask;


	//And one and every even spot. OR them all together because only one 1 is needed in an even spot.
	unsigned int one = 0x00000001;
	unsigned int result = (one & isolatedEvens) 
						| (one & isolatedEvens >> 2) 
						| (one & isolatedEvens >> 4) 
						| (one & isolatedEvens >> 6) 
						| (one & isolatedEvens >> 8) 
						| (one & isolatedEvens >> 10) 
						| (one & isolatedEvens >> 12) 
						| (one & isolatedEvens >> 14)
						| (one & isolatedEvens >> 16)
						| (one & isolatedEvens >> 18)
						| (one & isolatedEvens >> 20)
						| (one & isolatedEvens >> 22)
						| (one & isolatedEvens >> 24)
						| (one & isolatedEvens >> 26)
						| (one & isolatedEvens >> 28)
						| (one & isolatedEvens >> 30);


	printf("%X\n", result);

	return result;
}

int main() {
	//tests
	even(0x0);
	even(0x1);
	even(0x2);
	even(0x3);
	even(0xFFFFFFFF);
	even(0xAAAAAAAA);
	even(0x4);
}