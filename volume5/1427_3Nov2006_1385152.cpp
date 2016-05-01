//1427_AC
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
#define arr_i ((!isalpha(str[i]))&&(str[i] != ' '))

//int arr[100007];

int main(){

	int i = 0, j = 0, count = 0, n, m;

	string t;


	char *str = new char[100007];
	cin >> n >> m;
	//scanf("%d%d", &n, &m);
	getline(cin, t, '\n');
	//getline(cin, str, '\n');
	cin.getline(str, 100007,'\n');
	
	while(i < 100007)
	{
		if(str[i] == '\0')break;
		i++;
	}
	int fix = i;//i-1;
	
	
	bool b = false;
	i = 0;

	while (i < fix)
	{
		b = false;
		j = 0;
		while ((i < fix) && (j < n))// '<' -????
		{
			b = arr_i || b;
			i++; j++;
		}
		while ((i < fix) && (j < m))// '<' -????
		{
			b = arr_i || b;
			if (b){
				//i--;
				break;
			}
	//		b = arr_i || b;			
			i++; j++;
		}
		count++;
	}

	printf("%d", count);
	
	return 0;
}