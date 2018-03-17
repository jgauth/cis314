// Author: John Gauthier
// Description: Prints hex byte representation of variables
// Sources: course/assignment material

#include <stdio.h>

void printBytes(unsigned char *start, int len) {
	for (int i = 0; i < len; i++) {
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

void printInt(int x) {
	printBytes((unsigned char *) &x, sizeof(int));
}

void printFloat(float x) {
	printBytes((unsigned char *) &x, sizeof(float));
}

void printShort(short x) {
	printBytes((unsigned char *) &x, sizeof(short));
}

void printLong(long x) {
	printBytes((unsigned char *) &x, sizeof(long));
}

void printDouble(double x) {
	printBytes((unsigned char *) &x, sizeof(double));
}

int main() {
	
	//From the following tests I noticed that the printBytes function
	//prints the hex with the least significant byte on the left and most significant on the right.
	//I was expecting it to print in the opposite order, from most significant to least.
	printInt(123345);

	printFloat(123.418);

	printShort(234);

	printLong(123345);

	printDouble(18989.32489989);
}
