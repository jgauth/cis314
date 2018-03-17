// Author: John Gauthier
// Description: Rewrote C code to minimize unnecessary function calls and multiplications
// Sources: course/assignment material

#include <stdio.h>
#include <time.h>

#define N 4
typedef int array_t[N][N];

int dim() {
	return N;
}

void f(array_t a, int x, int y) {

	int n = dim(); //reduce calls to dim()
	int xy = x * y; //reduce multiplications
	int ixy = 0;

	for (int i = 0; i < n; ++i) {

		for (int j = 0; j < n; ++j) {
			a[i][j] = ixy + j;
		}

		ixy += xy; //reduce multiplications
	}
}


int main() {
	//testing
	array_t a = {5,6,7,8};
 	f(a, 1, 2);
}