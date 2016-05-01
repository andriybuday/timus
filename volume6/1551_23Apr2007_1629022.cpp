#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;


int main()
{
	
#ifndef ONLINE_JUDGE
     freopen("in.txt", "r", stdin);
#endif
	int n, i, j;
	//scanf("%d", &n);
	cin >> n;
	int p = 1 << n;

	string s;
	map<string, int> mp;

	for (i = 0; i < p; ++i)
	{
		cin >> s;
		cin >> s;
		if (mp.find(s) == mp.end()) mp.insert(make_pair(s, 0));
		mp[s] = mp[s] + 1;
	}

	int max = 0;
	for (map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it){
		if (max < (*it).second) max = (*it).second;
	}

	if (max == 1){
		printf("%d\n", n);
		return 0;
	}

	int res = 1, mask = 1;
	while (max > mask){
		++res;
		mask <<= 1;
	}
	--res;

	//printf("%d\n", n - res);
	//cout << max << " " << res << endl;
	cout << n - res << endl;


	return 0;
}