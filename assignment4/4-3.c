#include <stdio.h>

int sum(int from, int to) {
	int result = 0;
	//Ensure that argument *from* is in %ecx,
	//argument *to* is in %edx, *result* is in %eax - do not modify
	__asm__ ("movl %0, %%ecx # from in ecx;" :: "r" ( from ));
	__asm__ ("movl %0, %%edx # to in edx;" :: "r" ( to ));
	__asm__ ("movl %0, %%eax # result in eax;" :: "r" ( result ));

	//Your IA32 code goes below - comment each instruction...
	//__asm__ ("movl %edx, %eax # For example, this sets result = to;");

	__asm__(".L1:"); // Loop label
	__asm__("addl %ecx, %eax"); // result += from
	__asm__("addl $1, %ecx"); // ++from
	__asm__("cmpl %edx, %ecx"); // compare from and to (from - to)
	__asm__("jle .L1"); // if from <= to, goto .L1

	//Ensure that *result* is in %eax for return - do not modify.
	__asm__ ("movl %%eax, %0 #result in eax;" : "=r" ( result ));
	return result;
}


int main() {
	//tests
	printf("%d\n", sum(1,6));
	printf("%d\n", sum(3,5));
}