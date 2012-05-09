#include "util.h"

int round_down(int x, int y)
{
	 return x & (-y);
}

int round_up(int x, int y)
{
	 return (x+y-1) & (-y);
}

int main(int argc, char** argv)
{
	 if(argc != 3)
		  exit(0);
	 
	 int x = atoi(argv[1]);
	 unsigned int y = atoi(argv[2]);
	 printf("x:%d, y:%d\n", x, y);
	 printf("round down to multiple of %d: %d\n", y, round_down(x, y));
	 printf("round up to multiple of %d: %d\n", y, round_up(x, y));
}
