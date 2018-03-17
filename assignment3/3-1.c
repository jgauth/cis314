#include <stdio.h>
#include <stdlib.h>

struct IntArray {
	int length;
	int *dataPtr;
};

struct IntArray* mallocIntArray(int length) {

	//allocate memory for struct
	struct IntArray* array = malloc(sizeof(struct IntArray));
	array->length = length;
	//allocate memory for int array of size length
	array->dataPtr = (int*) malloc(sizeof(int) * length);

	return array;
}

void freeIntArray(struct IntArray **arrayPtr) {

	struct IntArray* array = (*arrayPtr);

	free(array->dataPtr);

	array->dataPtr = NULL;
	array->length = 0;

	free(*arrayPtr);
	*arrayPtr = NULL;
}

int getInput(int positiveOnly) {
	/*
	Function to get input from user via stdin.
	Has one parameter, positiveOnly. If positiveOnly is 0,
	the function will consider all integers valid inputs.
	If positiveOnly is not 0, only integers >0 will be considered valid inputs.
	*/

	char buffer[16];
	char *ptr;

	while(1) {

		fgets(buffer, sizeof(buffer), stdin);

		int ret = (int)strtol(buffer, &ptr, 10);

		//Check if there are invalid characters in the input
		if (ret == 0 || *ptr != 0xA) {
			printf("Invalid input, enter a valid int: ");
		}
		//Check if positiveOnly is !0 and if input is >0
		else if (positiveOnly && ret <= 0){
			printf("Invalid input, enter a positive int: ");
		}
		else {
			return ret;
		}
	}
}

void readIntArray(struct IntArray *array) {

	int length = array->length;
	int *dataPtr = array->dataPtr;

	//Loop calls getInput() 'length' times. Adds input to int array.
	for (int i = 0; i < length; ++i) {
		printf("Enter an integer: ");
		int input = getInput(0); //getInput with argument 0 indicates positive and negative numbers allowed
		dataPtr[i] = input;
	}
}



void swap(int *xp, int *yp){

	int x = (*xp);
	int y = (*yp);
	*xp = y;
	*yp = x;
}

void sortIntArray(struct IntArray *array) {

	//Source: https://en.wikipedia.org/wiki/Bubble_sort

	int *dataPtr = array->dataPtr;
	int length = array->length;

	for (int i = 0; i < length-1; ++i) {

		for (int j = 0; j < length-i-1; ++j) {

			if (dataPtr[j] > dataPtr[j+1]) {
				swap(&dataPtr[j], &dataPtr[j+1]);
			}
		}
	}
}

void printIntArray(struct IntArray *array) {

	int *dataPtr = array->dataPtr;
	int length = array->length;

	for (int i = 0; i < length; ++i) {
		printf("%d ", dataPtr[i]);
	}
	printf("\n");
}

void main(void) {

	printf("Enter length: ");
	int length = getInput(1); //getInput with argument 1 indicates positive numbers only 
	struct IntArray* array = mallocIntArray(length);
	readIntArray(array);
	sortIntArray(array);
	printIntArray(array);
	freeIntArray(&array);
}