#include "util.h"

int eq(int x, int y)
{
	 return (unsigned int)(~((x-y) | (y-x))) >> 31;
}

int ne(int x, int y)
{
	 return (unsigned int)((x-y) | (y-x)) >> 31;
}

int lt(int x, int y)
{
	 return (unsigned int)((x-y) ^ ((x^y)&((x-y)^x))) >> 31;
}

int le(int x, int y)
{
	 return (unsigned int)((x|~y) & ((x^y) | ~(y-x))) >> 31;
}

int lt_unsigned(int x, int y)
{
	 return (unsigned int)((~x&y) | ((~x|y)&(x-y))) >> 31;
}

int le_unsigned(int x, int y)
{
	 return (unsigned int)((~x|y) & ((x^y) | ~(y-x))) >> 31;
}

int main(int argc, char** argv)
{
	 if(argc != 3)
		  exit(0);
	 
	 int x = atoi(argv[1]);
	 int y = atoi(argv[2]);
	 printf("x:%d, y:%d\n", x, y);
	 printf("x = y  :%d\n", eq(x, y));
	 printf("x != y :%d\n", ne(x, y));
	 printf("x < y  :%d\n", lt(x, y));
	 printf("x <= y :%d\n", le(x, y));
	 printf("x u< y :%d\n", lt_unsigned(x, y));
	 printf("x u<= y:%d\n", le_unsigned(x, y));
}
