#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, K;
	int F[65];
	string S;


	cin >> N >> K;
	F[0]=1;
	F[1]=1;
	F[2]=2;
	for(int i = 3; i <= 60; i++)
	{
		F[i] = F[i-1]+F[i-2];
	}
	int max_lenght = 1;
	for(int i = 0; i < N; i++)
	{
		max_lenght += F[i];
	}
	if (K > max_lenght)
	{
		cout << -1 << endl;
		return 0;
	}

	S = "";
	for(int i = N; i >= 1; i--)
	{
		if(K > F[i])
		{
			S = S + "1";
			K = K - F[i];	
		}
		else
		S = S + "0";
	}
	cout << S;
	return 0;
}