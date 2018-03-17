/*
loop:
	pushl %ebp           //save old %ebp
	movl  %esp, %ebp     //set %ebp as frame pointer
	pushl %esi           //save callee-save register %esi
	pushl %ebx           //save callee-save register %ebx
	movl 8(%ebp), %esi   //%esi = x
	movl 12(%ebp), %ecx  //%ecx = y
	movl $2, %edx        //%edx (mask) = 2
	movl $-1, %eax       //%eax (result) = -1
.L2:
	movl %esi, %ebx      //%ebx = x
	andl %edx, %ebx      //%ebx = mask & x
	xorl %ebx, %eax      //result = result ^ (mask & x)
	sall %cl, %edx       //mask = mask << y
	cmpl $1, %edx        //compare mask with 1 (mask - 1)
	jg .L2               //if mask > 1 goto .L2
	popl %ebx            //restore %ebx
	popl %esi            //restore %esi
	popl %ebp            //restore %ebp
	ret                  //return result
*/

#include <stdio.h>

int loop(int x, int y) {

	int result = -1;  //movl $-1, %eax

	for (int mask = 2; mask > 1; mask = mask << y) {

		result ^= mask & x;  //xorl %ebx, %eax
	}

	return result;
}

int main(){
	//tests
	printf("%d\n", loop(1,5));
	printf("%d\n", loop(2,4));
	printf("%d\n", loop(3,3));
	printf("%d\n", loop(4,2));
	printf("%d\n", loop(5,1));
}
