// Author: John Gauthier
// Description: Uses bitwise ops to compare two floats
// Sources: course/assignment material

#include <stdio.h>

int ge(float x, float y) {
	unsigned ux = *((unsigned int*) &x); // convert x raw bits
	unsigned uy = *((unsigned int*) &y); // convert y raw bits
	unsigned sx = ux >> 31; // extract sign bit of ux
	unsigned sy = uy >> 31; // extract sign bit of uy
	ux <<= 1; // drop sign bit of ux
	uy <<= 1; // drop sign bit of uy
	// TODO: return using sx, sy, ux, uy



	return ((ux == 0) && (uy == 0)) //Returns 1 if ux and uy are 0
		 ||((ux == uy) && (sx == sy)) //Returns 1 if x and y are equal to each other
		 ||((sx == 0) && (sy == 1)) //Returns 1 if x is positive an y is negative
	  	 ||((ux < uy) && (sx == 1) && (sy == 1)) //Returns 1 if x is greater than y (both positive)
    	 ||((ux > uy) && (sx == 0) && (sy == 0)); //Returns 1 if x is greater than y (both negatve)

}

int main() {

	//tests
	ge(0.0f, 0.0f);
	ge(-0.0f, 0.0f);
	ge(-1.0f, 0.0f);
	ge(0.0f, 1.0f);
	ge(1.0f, 0.0f);
	ge(0.0f, -1.0f);
}
