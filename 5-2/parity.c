#include "util.h"

int parity1(int x)
{
	 int y = x ^ (x >> 1);
	 y = y ^ (y >> 2);
	 y = y ^ (y >> 4);
	 y = y ^ (y >> 8);
	 y = y ^ (y >> 16);
	 return y & 0x00000001;
}

int parity2(int x)
{
	 x = x ^ (x >> 1);
	 x = (x ^ (x >> 2)) & 0x11111111;
	 x = x * 0x11111111;
	 return (x >> 28) & 1;
}

int main(int argc, char** argv)
{
	 if(argc != 2)
		  exit(0);
	 
	 int x = atoi(argv[1]);
	 printf("x:%d\n", x);

	 char c[32];
	 int2binary(x, c);
	 printf("x:%.32s\n", c);

	 printf("parity1: %d\n", parity1(x));
	 printf("parity2: %d\n", parity2(x));
}
