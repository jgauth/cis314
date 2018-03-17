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
void bubbleSort(int *data, int length)
{
  int i, j;
  for (i = 0; i < length - 1; i++)
  {
    for (j = 0; j < length-i-1; j++)
    {
      if ( *(data+j) > *(data+j+1) )
      {
        //Swap adjacent elements
        int t = *(data+j+1);
        int u = *(data+j);
        *(data+j+1) = u;
        *(data+j) = t; 
      }
    }
  }
}

void printArray(int *data, int length) {
  for (int i = 0; i < length; ++i)
  {
    printf("%d\n", data[i]);
  }
}