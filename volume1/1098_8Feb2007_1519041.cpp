//1098_AC
#include <stdio.h>
//	This function calculates ordinal element,
//	which remains after erasing every k-th element
//	from sequence of n ordinal elements
int Josef(int n, int k)
{
	int result = 0;
	for (int i = 1; i <= n; i++)
		result = (result + k - 1) % i + 1;
	return result;
}
int question[30005];
int main()
{
	char ch  = '#';
	int i = 0;
 
	while((ch=getchar())!=-1)
	{
		if(ch == 32)question[++i] = 32;
		else
			if(ch == '?')question[++i] = 100;
			else
			{
				if(ch == '\n')continue;
				question[++i] = 256;
			}
	}
	int len = i;
	int	pos = Josef(len, 1999);


//	int N = len;
//	int pos = 0;
//	for(int len  = i-1; len > 0; len--)
//	{
//		pos = (pos+ N-1)%len;
//	}


	if(question[pos] == 32)printf("No\n");
	if(question[pos] == 100)printf("Yes\n");
	if(question[pos] == 256)printf("No comments\n");



	return 0;
}