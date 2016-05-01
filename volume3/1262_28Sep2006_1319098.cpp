#include <iostream>
using namespace std;

int main()
{
char ch;
int counter = 0;
int i;

while(cin>>ch)
//for(i = 0; i < 4; i++)
{
//cin>>ch;
int res = ch - 48;

switch(res)
{
	case(0):
	{
		counter += 0;
		break;
	}
	case(1):
	{
		counter += 1;
		break;
	}
	case(2):
	{
		counter += 2;
		break;
	}
	case(3):
	{
		counter += 3;
		break;
	}
	case(4):
	{
		counter += 2;
		break;
	}
	case(5):
	{
		counter += 1;
		break;
	}
	case(6):
	{
		counter += 2;
		break;
	}
	case(7):
	{
		counter += 3;
		break;
	}
	case(8):
	{
		counter += 4;
		break;
	}
	case(9):
	{
		counter += 2;
		break;
	}

}

}
printf("%d", counter);



return 0;
}