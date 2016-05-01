#include <iostream>
using namespace std;
int main()
{
	double k1, k2, k3;
	cin >> k1 >> k2 >> k3;
	cout << (int)(1000.0 * k1*k3*k2 / (k1*k2+k2*k3+k1*k3) + 0.5);
	return 0;
}