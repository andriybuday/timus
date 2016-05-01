#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[3];
	a[0] = a[1] = a[2] = 0;
	string Penguin;
	for(int i = 0; i < n; ++i)
	{
		cin >> Penguin;
		if(Penguin == "Emperor")a[0]++;
		if(Penguin == "Macaroni")a[1]++;
		if(Penguin == "Little")a[2]++;
		cin >> Penguin;
	}
	int min_p = 0;
	int max_a = a[0];
	for(int i = 0; i < 3; ++i)
	{
		if(a[i] > max_a)
		{
			max_a = a[i];
			min_p = i;
		}
	}
	switch(min_p)
	{
	case(0): cout << "Emperor ";break;
	case(1): cout << "Macaroni ";break;
	case(2): cout << "Little ";break;
	}
	cout << "Penguin\n";
	return 0;
}
/*
7
Emperor Penguin
Macaroni Penguin
Little Penguin
Emperor Penguin
Macaroni Penguin
Macaroni Penguin
Little Penguin
*/