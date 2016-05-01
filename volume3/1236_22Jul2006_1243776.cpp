//1236
#include <iostream>
#include <string>
using namespace std;
int main()
{
string fr, sec;
cin>>fr>>sec;
int i, key, first = 32, second, add1, add2;
char ch1, ch2;

for(i = 0; i < (sec.length()/2); i++)
{
	ch1 = sec[2*i];
	ch2 = sec[2*i+1];

	if(isdigit(ch1))
	{
		add1 = (int(ch1) - 48)*16;
	}
	else
		switch(ch1)
		{
		case('A'):{add1 = 160;break;}
		case('B'):{add1 = 176;break;}
		case('C'):{add1 = 192;break;}
		case('D'):{add1 = 208;break;}
		case('E'):{add1 = 224;break;}
		case('F'):{add1 = 240;break;}
		}

	if(isdigit(ch2))
	{
		add2 = (int(ch2)-48);
	}
	else
		switch(ch2)
		{
		case('A'):{add2 = 10;break;}
		case('B'):{add2 = 11;break;}
		case('C'):{add2 = 12;break;}
		case('D'):{add2 = 13;break;}
		case('E'):{add2 = 14;break;}
		case('F'):{add2 = 15;break;}
		}

	second = add1 + add2;

	key = (second^first);

	int firstout = key/16;

	if(firstout < 10)
	{
		printf("%d", firstout);
	}
	else
		switch(firstout)
		{
		case(10):{printf("A");break;}
		case(11):{printf("B");break;}
		case(12):{printf("C");break;}
		case(13):{printf("D");break;}
		case(14):{printf("E");break;}
		case(15):{printf("F");break;}
		}

	int secondout = key%16;

	if(secondout < 10)
	{
		printf("%d", secondout);
	}
	else
		switch(secondout)
		{
		case(10):{printf("A");break;}
		case(11):{printf("B");break;}
		case(12):{printf("C");break;}
		case(13):{printf("D");break;}
		case(14):{printf("E");break;}
		case(15):{printf("F");break;}
		}

	ch1 = fr[2*i];

	ch2 = fr[2*i+1];

	if(isdigit(ch1))
	{
		add1 = (int(ch1) - 48)*16;
	}
	else
		switch(ch1)
		{
		case('A'):{add1 = 160;break;}
		case('B'):{add1 = 176;break;}
		case('C'):{add1 = 192;break;}
		case('D'):{add1 = 208;break;}
		case('E'):{add1 = 224;break;}
		case('F'):{add1 = 240;break;}
		}

	if(isdigit(ch2))
	{
		add2 = (int(ch2)-48);
	}
	else
		switch(ch2)
		{
		case('A'):{add2 = 10;break;}
		case('B'):{add2 = 11;break;}
		case('C'):{add2 = 12;break;}
		case('D'):{add2 = 13;break;}
		case('E'):{add2 = 14;break;}
		case('F'):{add2 = 15;break;}
		}
	first = add1 + add2;

	first = (first^key);
}

return 0;
}
