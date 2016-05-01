//1219
#include <stdio.h>

void out(char p1, char p2, char p3)
{	
while(p1!='z'+1)
{
	while(p2!='z'+1)
	{
		while(p3!='z'+1)
		{
			//cout<<p1<<p2<<p3<<endl;
			printf("%c%c%c", p1, p2, p3);
			p3++;
		}
		p2++;
		p3 = 'a';
	}
	p1++;
	p2 = 'a';
	p3 = 'a';
}
}
void out_with_counter(char p1, char p2, char p3)
{	
int counter = 949107;
while(p1!='z'+1)
{
	while(p2!='z'+1)
	{
		while(p3!='z'+1)
		{
			//cout<<p1<<p2<<p3<<endl;
			printf("%c%c%c", p1, p2, p3);
			counter += 3;
			if(counter >= 1000000)return;
			p3++;
		}
		p2++;
		p3 = 'a';
	}
	p1++;
	p2 = 'a';
	p3 = 'a';
}
}
int main()
{
	int i;

	for(i = 0; i < 18; i++)
	{
		out('a', 'a', 'a');
	}

	out_with_counter('a', 'a', 'a');

	printf("z");

	return 0;
}