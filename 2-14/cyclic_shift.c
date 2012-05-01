#include "util.h"

int cyclic_left_shift(int x, unsigned int n)
{
	 return (x << n) | ((unsigned int)x >> (32-n));
}

int cyclic_right_shift(int x, unsigned int n)
{
	 return ((unsigned int)x >> n) | (x << (32-n));
}

int main(int argc, char** argv)
{
	 if(argc != 3)
		  exit(0);
	 
	 int x = atoi(argv[1]);
	 int y;
	 int n = atoi(argv[2]);

	 if(n > 32 || n < 0)
		  exit(0);

	 char c[32];
	 printf("x:%d, n:%d\n", x, n);

	 int2binary(x, c);
	 printf("before shift      :%.32s\n", c);

	 y = cyclic_left_shift(x, n);
	 int2binary(y, c);
	 printf("after left shift  :%.32s\n", c);

	 y = cyclic_right_shift(x, n);
	 int2binary(y, c);
	 printf("after right shift :%.32s\n", c);
}
