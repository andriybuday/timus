#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//string str[1005];
int main()
{
//#ifndef ONLINE_JUDGE
 //    freopen("in.txt", "r", stdin);
//#endif
	 
	vector<string> str;
	int n, i, j;
	//scanf("%d", &n);
	cin >> n;
	string s;
	for (i = 0; i < n; ++i)
	{
		cin >> s;
		str.push_back(s);
	}
	sort(str.begin(), str.end());
	char ch;
	cin >> ch;

	for(i = 0; i < n; ++i)
		if(str[i][0] == ch)
			cout << str[i] << endl;


	return 0;
}