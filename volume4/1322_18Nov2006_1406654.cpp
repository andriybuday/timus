#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

void quickSortR(char* a, long N)
{
  long i = 0, j = N;
  char temp, p;

  p = a[ N>>1 ];


  do
  {
    while ( a[i] < p ) i++;
    while ( a[j] > p ) j--;

    if (i <= j)
	{
      temp = a[i]; a[i] = a[j]; a[j] = temp;
      i++; j--;
    }
  } while ( i<=j );

  if ( j > 0 ) quickSortR(a, j);
  if ( N > i ) quickSortR(a+i, N-i);
}

int main()
{
	int i, j;
	//string str;
	//string str_sorted;
	char *str = new char [100003];
	char *str_sorted = new char [100003];

	int next[100003];
	int x; 
	//cin >> x >> str;
	scanf("%d%s", &x, str);
	x--;

	int length_of_str = 0;
	for(i = 0; i < 100003; i++)
	{
		if(str[i] != '\0')
		{
			str_sorted[i] = str[i];
			length_of_str++;
		}else break;

	}
	//str_sorted = str;
	//sort(str_sorted.begin(), str_sorted.end());
	quickSortR(str_sorted, length_of_str - 1);


	int last_position = 0;
	char curr = 25;
	for(i = 0; i < length_of_str ; i++)
	{
		if(str_sorted[i] != curr)
		{
			curr = str_sorted[i];
			last_position = 0;
		}
		for(j = last_position; j < length_of_str; j++)
		{
			if(str[j] == curr)
			{
				next[i] = j;
				last_position = j+1;
				break;
			}
		}
	}
	
	//char t[11] = "rdarcaaaabb";//str
	for (i = 0; i < length_of_str; i++)
		putchar(str[x = next[x]]);
	

	return 0;
}