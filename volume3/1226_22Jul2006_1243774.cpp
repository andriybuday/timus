//1226
#include<stdio.h>
#include<ctype.h>
int main()
{
	char s[256],ch;
	
	int poz=-1;

	scanf("%c",&ch);

while(!feof(stdin))
{
	if (isalpha(ch))
	{	
		poz++;
		s[poz]=ch;
	}
	else 
	if (!feof(stdin))
	{
		if (poz!=-1)
		{
			while(poz>=0)
			{
				printf("%c",s[poz]);
				poz--;
			}
		}
		printf("%c",ch);
	}
	scanf("%c",&ch);
}

	
while(poz>=0)
{
	printf("%c",s[poz]);
	poz--;
}

return 0;
}