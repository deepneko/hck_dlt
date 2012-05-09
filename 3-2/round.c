#include "util.h"

unsigned int round_down(unsigned int x)
{
	 unsigned int y = 0x80000000;
	 while(y > x){
		  y = y >> 1;
	 }
	 return y;
}

unsigned int round_up(unsigned int x)
{
	 unsigned int y = 1;
	 while(y < x)
		  y = 2*y;
	 return y;
}

int main(int argc, char** argv)
{
	 if(argc != 2)
		  exit(0);
	 
	 int x = atoi(argv[1]);
	 printf("x:%d\n", x);
	 printf("round down to power of 2: %d\n", round_down(x));
	 printf("round up to power of 2: %d\n", round_up(x));
}
