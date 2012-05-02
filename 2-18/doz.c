#include "util.h"

int doz(int x, int y)
{
	 int d = x - y;
	 return d & ((~(d ^ (((x^y) & (d^x))))) >> 31);
}

int max(int x, int y)
{
	 return y + doz(x, y);
}

int min(int x, int y)
{
	 return x - doz(x, y);
}

/*
  Apparently, the code doesn't work if x-y overflows,
  but works fine...nmm...
 */
unsigned int dozu(unsigned int x, unsigned int y)
{
	 int d = x - y;
	 return d & ~((int)(((~x&y) | (~(x^y) & d))) >> 31);
}

unsigned int maxu(unsigned int x, unsigned int y)
{
	 return y + dozu(x, y);
}

unsigned int minu(unsigned int x, unsigned int y)
{
	 return x - dozu(x, y);
}

int main(int argc, char** argv)
{
	 if(argc != 3)
		  exit(0);
	 
	 int x = atoi(argv[1]);
	 int y = atoi(argv[2]);
	 
	 printf("x:%d, y:%d\n", x, y);
	 printf("doz :%d\n", doz(x, y));
	 printf("max :%d\n", max(x, y));
	 printf("min :%d\n", min(x, y));
	 printf("dozu:%u\n", dozu(x, y));
	 printf("maxu:%u\n", maxu(x, y));
	 printf("minu:%u\n", minu(x, y));
}
