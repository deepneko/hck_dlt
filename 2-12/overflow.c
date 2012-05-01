#include "util.h"

int detect_overflow_signed_add(int x, int y, int c)
{
	 return (unsigned int)(~(x^y) & ((x+y+c)^x)) >> 31;
}

int detect_overflow_signed_sub(int x, int y, int c)
{
	 return (unsigned int)((x^y) & ((x-y-c)^x)) >> 31;
}

/* doesn't work fine... */
int detect_overflow_unsigned_add(unsigned int x, unsigned int y, unsigned int c)
{
 	 return (unsigned int)((x&y) | ((x|y) & ~(x+y+c))) >> 31;
}

int detect_overflow_unsigned_sub(unsigned int x, unsigned int y, unsigned int c)
{
	 return (unsigned int)((~x&y) | ((~x|y) & (x-y-c))) >> 31;
}

int detect_overflow_signed_mul(long x, long y)
{
	 int hi = (x * y) >> 32;
	 int lo = x * y;
	 int sign_lo = lo >> 31;
	 return (unsigned int)((hi - sign_lo) | (sign_lo - hi)) >> 31;
}

int detect_overflow_unsigned_mul(unsigned long x, unsigned long y)
{
	 long hi = (x * y) >> 32;
	 return (unsigned int)(hi | -hi) >> 31;
}

int main(int argc, char** argv)
{
	 if(argc != 4)
		  exit(0);
	 
	 int x = atoi(argv[1]);
	 int y = atoi(argv[2]);
	 int c = atoi(argv[3]);
	 printf("x, y, and c's range : -2147483648 ~ 2147483647\n");
	 printf("x:%d, y:%d, c:%d\n", x, y, c);
	 printf("detect signed   overflow x+y+c :%d\n", detect_overflow_signed_add(x, y, c));
	 printf("detect signed   overflow x-y-c :%d\n", detect_overflow_signed_sub(x, y, c));
	 printf("detect unsigned overflow x+y+c :%d\n", detect_overflow_unsigned_add(x, y, c));
	 printf("detect unsigned overflow x-y-c :%d\n", detect_overflow_unsigned_sub(x, y, c));
	 printf("detect signed   overflow x*y   :%d\n", detect_overflow_signed_mul(x, y));
	 printf("detect unsigned overflow x*y   :%d\n", detect_overflow_unsigned_mul(x, y));
}
