/*
.L3:
	movl (%edx), %esi     //t = i
	movl (%eax), %ecx     //%ecx = j
	addl $4, %eax         //add 4 to j, moves to next column
	addl $40, %edx        //add (N * 4) to i, moves to next row
	movl %esi, -4(%eax)   //move t (original i value) to %eax -4
	movl %ecx, -40(%edx)  //move %ecx (original j value) to i - (N *4)
	cmpl %ebx, %eax       //compare j to %ebx, which is set in the outter loop. (j - %ebx)
	jne .L3               //if j != %ebx goto .L3
*/



#include <stdio.h>

#define N 4 //changed this to 4 to make testing easier
typedef int array_t[N][N];


void transpose(array_t a) {
	for (int i = 0; i < N; ++i) {

		for (int j = 0; j < i; ++j) {

			int* t1 = a[i] + j; //get pointer to element at row i column j
			int* t2 = a[j] + i; //get poitner to element at row j column i
			int temp = *t1;
			*t1 = *t2;   //dereference t1 and t2 to swap their elements
			*t2 = temp; 
		}
	}
}

// function to print 2d array, used for testing
void printArray(array_t a) {
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main() {
	//tests
	array_t a = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	printArray(a);
	transpose(a);
	printArray(a);
}