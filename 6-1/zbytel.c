#include "util.h"

int pop(unsigned int x)
{
	 x = (x & 0x55555555) + ((x>>1) & 0x55555555);
	 x = (x & 0x33333333) + ((x>>2) & 0x33333333);
	 x = (x & 0x0F0F0F0F) + ((x>>4) & 0x0F0F0F0F);
	 x = (x & 0x00FF00FF) + ((x>>8) & 0x00FF00FF);
	 x = x + (x>>16);
	 return x & 0x0000003F;
}

int nlz(unsigned int x)
{
	 x = x | (x >> 1);
	 x = x | (x >> 2);
	 x = x | (x >> 4);
	 x = x | (x >> 8);
	 x = x | (x >> 16);
	 return pop(~x);
}

int zbytel1(unsigned int x)
{
	 if((x>>24) == 0)
		  return 0;
	 else if((x&0x00FF0000) == 0)
		  return 1;
	 else if((x&0x0000FF00) == 0)
		  return 2;
	 else if((x&0x000000FF) == 0)
		  return 3;
	 else
		  return 4;
}

int zbytel2(unsigned int x)
{
	 unsigned int y;
	 int n;
	 y = (x & 0x7F7F7F7F) + 0x7F7F7F7F;
	 y = ~(y | x | 0x7F7F7F7F);
	 n = nlz(y) >> 3;
	 return n;
}

int main(int argc, char** argv)
{
	 if(argc != 2)
		  exit(0);
	 
	 int x = atoi(argv[1]);
	 printf("x:%d\n", x);

	 char c[32];
	 int2binary(x, c);
	 printf("x binary:%.32s\n", c);
	 printf("x hex:0x%x\n", x);

	 printf("find leftmost 0-byte:%d\n", zbytel1(x));
	 printf("find leftmost 0-byte:%d\n", zbytel2(x));
}
