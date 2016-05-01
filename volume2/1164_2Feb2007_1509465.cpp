#include <iostream>
#include <string>
using namespace std;
int a[30];
int b[30];

int main()
{
	int n, m, p;
	cin >> n >> m >> p;
	char temp;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			cin >> temp;
			++a[temp - 'A'];
		}
	string str;
	for(int i = 0; i < p; i++)
	{
		cin >> str;
		for(int j = 0; j < str.length(); j++)
		{
			--a[str[j] - 'A'];
		}
	}
	for(int i = 0; i < 30; i++)
	{
		while (a[i])
		{
			cout << char(i + 'A');
			--a[i];
		}
	}
	cout << endl;
	return 0;
}