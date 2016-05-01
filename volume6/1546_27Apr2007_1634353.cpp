//1546_SB
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#define STRING_SIZE 200000
#define STRING_AMOUNT 200000
char* s[STRING_AMOUNT];
int ind[STRING_AMOUNT];

inline bool IsAlpha(char ch)
{
	return (ch >= 'a' && ch <= 'z');
}
inline bool IsDigit(char ch)
{
	return (ch >= '0' && ch <= '9');
}
inline bool compare(int a, int b)
{
	//we need to compare the strings like s[a] and s[b]
	int zero_leading = 1; // 2 means that a have more zeros, 1 both have the same amounts , 0 mean that b have more zeros
	int i = 0, j = 0; //i is going on a, and j is going on b

while(true)
{
	while(IsAlpha(s[a][i]) && IsAlpha(s[b][j]))
	{
		if(s[a][i] < s[b][j])return true;
		if(s[a][i] > s[b][j])return false;
		++i, ++j;
	}
	if(IsAlpha(s[a][i]) && !IsAlpha(s[b][j]))return false;
	if(!IsAlpha(s[a][i]) && IsAlpha(s[b][j]))return true;
	//the same that they are equl to this place and begin there digits
	int a_zeros = 0, b_zeros = 0;
	while(s[a][i] == '0')++a_zeros, ++i;
	while(s[b][j] == '0')++b_zeros, ++j;

	//the real digits begins
	int digits = 1;// 2 a have greater num, 0 b have greater num, 1 equal
	while(IsDigit(s[a][i]) && IsDigit(s[b][j]))
	{
		if(s[a][i] < s[b][j]){digits = 0; break;}
		if(s[a][i] > s[b][j]){digits = 2; break;}
		++i, ++j;
	}
	int a_digits = 0, b_digits = 0;
	while(IsDigit(s[a][i]))++a_digits, ++i;
	while(IsDigit(s[b][j]))++b_digits, ++j;
	if(a_digits < b_digits)return true;
	if(a_digits > b_digits)return false;
	//amount of digits are equal
	if(digits != 1)
	{
		if(digits == 2)return false;
		if(digits == 0)return true;
	}
	if(zero_leading == 1)
	{
			if(a_zeros > b_zeros)zero_leading = 2;
			if(a_zeros < b_zeros)zero_leading = 0;
	}

	if(s[a][i] == '\0' && s[b][j] == '\0')break;
}
	
	
	if(s[a][i-1] == '0' && IsAlpha(s[b][j-1]))return false;
	if(s[b][j-1] == '0' && IsAlpha(s[a][i-1]))return true;

	if(zero_leading == 2)return true;

	return false;
}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r",  stdin);
#endif

	int n = -1, i;

	for(i = 0; i < STRING_AMOUNT; ++i)ind[i] = i;

	char temp[STRING_SIZE];
	int len = 0;

	while(scanf("%s", &temp) != EOF)
	{
		len = strlen(temp);
		s[++n] = new char[len+5];
		for(i = 0; i < len+3; ++i)s[n][i] = temp[i];
	}

	std::sort(ind, ind + n+1, compare);

	for(i = 0; i <= n; ++i)
		printf("%s\n", s[ind[i]]);
	
	return 0;
}