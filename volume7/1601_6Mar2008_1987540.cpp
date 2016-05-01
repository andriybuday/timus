#include <stdio.h>
#include <ctype.h>
int main()
{
	bool beg = true;
	char ch = 's';
	while(scanf("%c", &ch) != -1)
	{
		if(!isalpha(ch))
		{
			printf("%c", ch);

			if(ch == '.' || ch == '!' ||ch == '?') beg = true;			

			continue;
		}

		if(beg)
		{
			printf("%c", toupper(ch));
			beg = false;
		}		
		else
		{
			printf("%c", tolower(ch));			
		}
		
	}
	return 0;
}