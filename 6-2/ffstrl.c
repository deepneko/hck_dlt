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

int ffstrl1(unsigned int x, int n)
{
	 int k, p;

	 p = 0;
	 while(x != 0){
		  k = nlz(x);
		  x = x << k;
		  p = p + k;
		  k = nlz(~x);
		  if(k >= n)
			   return p;
		  x = x << k;
		  p = p + k;
	 }
	 return 32;
}

int ffstrl2(unsigned int x, int n)
{
	 int s;
	 while(n > 1){
		  s = n >> 1;
		  x = x & (x<<s);
		  n = n - s;
	 }
	 return nlz(x);
}

int main(int argc, char** argv)
{
	 if(argc != 3)
		  exit(0);
	 
	 int x = atoi(argv[1]);
	 int n = atoi(argv[2]);
	 printf("x:%d\n", x);
	 printf("n:%d\n", n);

	 char c[32];
	 int2binary(x, c);
	 printf("x binary:%.32s\n", c);
	 printf("x hex:0x%x\n", x);

	 printf("find 1bit row:%d\n", ffstrl1(x, n));
	 printf("find 1bit row:%d\n", ffstrl2(x, n));
}
