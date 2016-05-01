#include <iostream>
using namespace std;

char arr[1003][1003];

int main()
{
	int n, i, j;
	cin >> n;
	int w = 0, b = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++){
			cin >> arr[i][j];
			if (arr[i][j] == '0') w++;
			else b++;
		}
	int ww;

	ww = 0;
	for (i = 0; i < n; i++){
		if (arr[i][0] == '0')
			for (j = 0; j < n; j++){
				if (arr[i][j] == '0') ww++;
				else break;
			}
	}
	if (ww == w){
		cout << "Yes" << endl;
		return 0;
	}

	ww = 0;
	for (i = 0; i < n; i++){
		if (arr[i][n - 1] == '0')
			for (j = n - 1; j >= 0; j--){
				if (arr[i][j] == '0') ww++;
				else break;
			}
	}
	if (ww == w){
		cout << "Yes" << endl;
		return 0;
	}

	ww = 0;
	for (j = 0; j < n; j++){
		if (arr[0][j] == '0')
			for (i = 0; i < n; i++){
				if (arr[i][j] == '0') ww++;
				else break;
			}
	}
	if (ww == w){
		cout << "Yes" << endl;
		return 0;
	}

	ww = 0;
	for (j = 0; j < n; j++){
		if (arr[n - 1][j] == '0')
			for (i = n - 1; i >= 0; i--){
				if (arr[i][j] == '0') ww++;
				else break;
			}
	}
	if (ww == w){
		cout << "Yes" << endl;
		return 0;
	}

	cout << "No" << endl;
	return 0;
}