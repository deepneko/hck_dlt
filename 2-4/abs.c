#include "util.h"

int abs1(int x)
{
	 int y = x >> 31;
	 return (x ^ y) - y;
}

int abs2(int x)
{
	 int y = x >> 31;
	 return (x + y) ^ y;
}

int abs3(int x)
{
	 int y = x >> 31;
	 return x - ((x<<1) & y);
}

int main(int argc, char** argv)
{
	 if(argc != 2)
		  exit(0);
	 
	 int x = atoi(argv[1]);
	 printf("argument :%d\n", x);
	 printf("abs1     :%d\n", abs1(x));
	 printf("abs2     :%d\n", abs2(x));
	 printf("abs3     :%d\n", abs3(x));
}
