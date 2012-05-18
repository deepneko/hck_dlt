#include "util.h"

int nlz1(unsigned int x)
{
	 unsigned y;
	 int n, c;

	 n = 32;
	 c = 16;
	 do {
		  y = x >> c;
		  if(y != 0){
			   n = n - c;
			   x = y;
		  }
		  c = c >> 1;
	 } while(c != 0);
	 return n - x;
}

int pop(unsigned int x)
{
	 x = (x & 0x55555555) + ((x>>1) & 0x55555555);
	 x = (x & 0x33333333) + ((x>>2) & 0x33333333);
	 x = (x & 0x0F0F0F0F) + ((x>>4) & 0x0F0F0F0F);
	 x = (x & 0x00FF00FF) + ((x>>8) & 0x00FF00FF);
	 x = x + (x>>16);
	 return x & 0x0000003F;
}

int nlz2(unsigned int x)
{
	 x = x | (x >> 1);
	 x = x | (x >> 2);
	 x = x | (x >> 4);
	 x = x | (x >> 8);
	 x = x | (x >> 16);
	 return pop(~x);
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

	 printf("number of leading zeros 1:%d\n", nlz1(x));
	 printf("number of leading zeros 2:%d\n", nlz2(x));
}
