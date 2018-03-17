#include <stdio.h>
#include <time.h>

void inner(float *u, float *v, int length, float *dest) {

	int i;
	float sum = 0.0f;

	for (i = 0; i < length; ++i) {
		sum += u[i] * v[i];
	}
	*dest = sum;
}

void inner2(float *u, float *v, int length, float *dest) {

	int i;
	float sum1 = 0.0f; //4 accumulators
	float sum2 = 0.0f;
	float sum3 = 0.0f;
	float sum4 = 0.0f;
	int limit = length - 3;

	for (i = 0; i < limit; i+=4) {
		sum1 += u[i] * v[i];
		sum2 += u[i+1] * v[i+1];
		sum3 += u[i+2] * v[i+2];
		sum4 += u[i+3] * v[i+3];
	}

	*dest = sum1 + sum2 + sum3 + sum4;

	//include values not covered in main loop
	for (; i < length; ++i) {
		*dest += u[i] * v[i];
	}
}

int main() {
	//testing
	int length = 500000;
	float u[500000] = {0};
	float v[500000] = {0};
	float d;

	inner2(u, v, length, &d);
	printf("%f\n", d);


	clock_t start, end;
    double cpu_time_used;

    start = clock();
 	inner(u, v, length, &d);
 	end = clock();
 	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
 	printf("Unoptimized: %f\n", cpu_time_used);

 	d = 0.0f;

 	start = clock();
 	inner2(u, v, length, &d);
 	end = clock();
 	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
 	printf("Optimized  : %f\n", cpu_time_used);
}