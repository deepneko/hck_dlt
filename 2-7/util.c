void int2binary(int x, char* c)
{
	 int bit = 1;
	 int i;
	 int bitsize = sizeof(c);
	 
	 for(i=bitsize-1; i>=0; i--){
		  if(x & bit)
			   c[i] = '1';
		  else
			   c[i] = '0';
		  bit <<= 1;
	 }
}
