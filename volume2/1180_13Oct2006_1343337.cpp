#include <iostream>
using namespace std;

int main()
{
	char ch;
	int sum = 0;
	while(cin >> ch)
	{
		sum += (ch-48);
	}

	if(!(sum%3))
	{
		printf("2\n");
		return 0;
	}

	if(!((sum+1)%3))
	{
		printf("1\n2\n");
		return 0;
	}

	if(!((sum+2)%3))
	{
		printf("1\n1\n");
		return 0;
	}

	return 0;
}