#include "util.h"

int rightmost_bit_1_to_0(int x)
{
	 return x & (x-1);
}

int rightmost_bit_0_to_1(int x)
{
	 return x | (x+1);
}

int get_rightmost_bit_1(int x)
{
	 return x & (-x);
}

int get_rightmost_bit_0(int x)
{
	 return (~x) & (x+1);
}

int get_mask_last_line_0(int x)
{
	 return (~x) & (x-1);
}

int rightmost_bit_1_propagate(int x)
{
	 return x | (x-1);
}

int rightmost_line_1_to_0(int x)
{
	 return ((x | (x-1)) + 1) & x;
}

int main(int argc, char** argv)
{
	 if(argc != 2)
		  exit(0);

	 int x, y;
	 char c[8];
	 x = atoi(argv[1]);
	 int2binary(x, c);
	 printf("argument                 :%.8s\n", c);

	 y = rightmost_bit_1_to_0(x);
	 int2binary(y, c);
	 printf("rightmost_bit_1_to_0     :%.8s\n", c);

	 y = rightmost_bit_0_to_1(x);
	 int2binary(y, c);
	 printf("rightmost_bit_0_to_1     :%.8s\n", c);

	 y = get_rightmost_bit_1(x);
	 int2binary(y, c);
	 printf("get_rightmost_bit_1      :%.8s\n", c);

	 y = get_rightmost_bit_0(x);
	 int2binary(y, c);
	 printf("get_rightmost_bit_0      :%.8s\n", c);

	 y = get_mask_last_line_0(x);
	 int2binary(y, c);
	 printf("get_mask_last_line_0     :%.8s\n", c);

	 y = rightmost_bit_1_propagate(x);
	 int2binary(y, c);
	 printf("rightmost_bit_1_propagate:%.8s\n", c);

	 y = rightmost_line_1_to_0(x);
	 int2binary(y, c);
	 printf("rightmost_line_1_to_0    :%.8s\n", c);
}
