#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> p(4);


bool compare (string a, string b)
{
	for(int i =0 ; i < 4; i++)
	{
		if(a[i] != b[p[i]])return false;
	}
	return true;
}
int main()
{
	p[0] = 0;
	p[1] = 1;
	p[2] = 2;
	p[3] = 3;
	string dia1, dia2;
	cin >> dia1 >> dia2;
	int compare_condition = 1;
	bool eq = 0;
	while (1)
	{
		if (compare_condition < 2)eq = compare(dia1, dia2);
			if (eq)
			{
				//cout << "equal" << endl;
				printf("equal\n");
				return 0;
			}
		compare_condition++;
		compare_condition %= 4;
		if (!next_permutation(p.begin(), p.end())) break;
	}
	//cout << "different\n";
	printf("different\n");

return 0;
}