#include "util.h"

int sign(int x)
{
	 unsigned int y = x;
	 return (x >> 31) | ((-y) >> 31);
}

int main(int argc, char** argv)
{
	 if(argc != 2)
		  exit(0);
	 
	 int x = atoi(argv[1]);
	 printf("argument :%d\n", x);
	 printf("sign     :%d\n", sign(x));
}
