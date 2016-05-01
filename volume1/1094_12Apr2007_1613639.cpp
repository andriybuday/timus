//1094_
#include <iostream>
using namespace std;
char output[81];
int cursor = 0;

int main()
{

int i = 0;

for (i = 0; i < 81; i++)output[i] = ' ';


char c;
while(cin.get(c))
{
	if(c == '<')
	{
			if(cursor > 0)
				cursor--;	
			else
				cursor = 0;
			continue;
	}
	if(c == '>')
	{
		if(cursor < 79)
			cursor++;
		else
			cursor = 0;	

		continue;
	}
	
	if(isalnum(c) || c == ':' || c == ';' || c == '-' || c == '!' || c == '?'
		|| c == '.' || c == ',' || c == ' ')
	{

		output[cursor] = c;

		if(cursor < 79)
			cursor++;
		else
			cursor = 0;	
	}

}
	

	for(i = 0; i < 80; ++i)printf("%c", output[i]);
	printf("\n");

	return 0;
}