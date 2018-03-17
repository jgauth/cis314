#include <stdio.h>
#define N 10

void bubbleSort(int*, int);
void printArray(int*, int);

int array[10] = {10,9,8,7,6,5,4,3,2,1};

void main()
{
  printArray(array, N);
  bubbleSort(array, N);
  printArray(array, N);
}

void bubbleSort(int *a, int length) {
  int repeat, i;
  do {
    repeat = 0;
    i = 0;
    
    do {
      if (a[i] >= a[i+1]) {
        int t = a[i];
        int u = a[i+1];
        a[i] = u;
        a[i+1] = t;
        repeat = 1;
      }
      i += 1;
    } while  (i < length - 1);

  } while (repeat);
}

void printArray(int *data, int length) {
  for (int i = 0; i < length; ++i)
  {
    printf("%d\n", *(data+i));
  }
}