#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	int n;
	cin >> n;
	set<string> ss;
	string s;
	set<string> res;
	int i;
	for (i = 0; i < n; i++){
		cin >> s;
		if (ss.find(s) == ss.end()) ss.insert(s);
		else res.insert(s);
	}

	for (set<string>::iterator it = res.begin(); it != res.end(); ++it) cout << (*it) << endl;
	return 0;
}