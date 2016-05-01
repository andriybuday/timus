//1038_AC
#include <stdio.h>

int main()
{
char ch  = '#';
int state = 0,errors = 0;
 
while((ch=getchar())!=-1)
{
switch(state)
{
case(0):
	{
		if('a' <= ch && ch <= 'z')
		{
			errors++;
			state = 1;
			break;
		}
		if('A' <= ch && ch <= 'Z')
		{
			state = 1;//word
			break;
		}
		if(ch == '.' || ch == '!' || ch == '?')state = 0;//end of sentense!
		else state = 0;
		break;
	}
case(1):
	{
		if('A' <= ch && ch <= 'Z')
		{
			errors++;
			break;
		}
		if('a' <= ch && ch <= 'z')
		{
			state = 1;//word
			break;
		}
		if(ch == '.' || ch == '!' || ch == '?')state = 0;//end of sentense!
		else state = 2;
		break;
	}
case(2):
	{
		if('a' <= ch && ch <= 'z')
		{
			state = 1;
			break;
		}
		if('A' <= ch && ch <= 'Z')
		{
			state = 1;//word
			break;
		}
		if(ch == '.' || ch == '!' || ch == '?')state = 0;//end of sentense!
		else state = 2;
		break;
	}
	//default :{ break;}
}

}
	printf("%d\n", errors);
	return 0;
}