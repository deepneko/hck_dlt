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

int ntz1(unsigned int x)
{
	 return pop(~x&(x-1));
}

int ntz2(unsigned int x)
{
	 int n;
	 x = ~x & (x-1);
	 n = 0;
	 while(x != 0){
		  n++;
		  x = x >> 1;
	 }
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
	 printf("x:%.32s\n", c);

	 printf("number of trailing zeros 1:%d\n", ntz1(x));
	 printf("number of trailing zeros 2:%d\n", ntz2(x));
}
