#include "util.h"

void swap(int *x, int *y)
{
	 *x = (*x)^(*y);
	 *y = (*y)^(*x);
	 *x = (*x)^(*y);
}

void mask_swap(int *x, int *y, int m)
{
	 *x = (*x)^(*y);
	 *y = (*y)^((*x) & m);
	 *x = (*x)^(*y);
}

int main(int argc, char** argv)
{
	 if(argc != 4)
		  exit(0);
	 
	 int x = atoi(argv[1]);
	 int y = atoi(argv[2]);
	 int m = atoi(argv[3]);
	 
	 printf("before swap x:%d, y:%d\n", x, y);
	 swap(&x, &y);
	 printf("after  swap x:%d, y:%d\n", x, y);

	 char c_x[32], c_y[32], c_m[32];
	 int2binary(x, c_x);
	 int2binary(y, c_y);
	 int2binary(m, c_m);
	 printf("mask:%.32s\n", c_m);
	 printf("before mask_swap\n");
	 printf("   x:%.32s\n", c_x);
	 printf("   y:%.32s\n", c_y);

	 mask_swap(&x, &y, m);
	 int2binary(x, c_x);
	 int2binary(y, c_y);
	 printf("after mask_swap\n");
	 printf("   x:%.32s\n", c_x);
	 printf("   y:%.32s\n", c_y);
}
