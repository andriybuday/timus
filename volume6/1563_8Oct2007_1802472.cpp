#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> s;
	string str = "";
	getline(cin,str);
	for(int i = 0; i < n; i++)
	{
		//cin >> str;
		getline(cin,str);
		s.push_back(str);
	}
	sort(s.begin(), s.end());
	str = s[n-1];
	int r = s.size();
	unique(s.begin(), s.end());
	int k = 0;
	while(s[k++] != str);
	cout << r - k;

	return 0;
}