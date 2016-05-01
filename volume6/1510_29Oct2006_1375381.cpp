#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	vector<int> v;
	int n, k, m = 0, maxel = 0, maxcount = 0;
	scanf("%d", &n);
	v.reserve(n + 2);

	int i;
	for (i = 0; i < n; i++){
		scanf("%d", &k);
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	
	int el = -341;
	int count;
	int sz = v.size();
	i = 0;
	while (i < sz){
		count = 0;
		while (i < sz && v[i] == el){
			count++;
			i++;
		}
		if (maxcount <= count){
			maxcount = count;
			maxel = el;
		}
		if (i == sz) break;
		else el = v[i];
	}
	//cout << maxel << endl;
	printf("%d", maxel);
	return 0;
}