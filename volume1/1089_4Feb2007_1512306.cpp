//1089_SB
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;
int word_pos = 0;
string vocabulary[202];

bool compare(string s1, string s2)
{
	if(s1.length() != s2.length())return false;
	int miss = 0;
	for(int i = 0; i < s1.length(); i++)
	{
		if(s1[i] != s2[i])miss++;
		if(miss > 1)return false;
	}
	if(miss == 0)return false;
	return true;
}

int main()
{
	int errors = 0;
	int state = 0;
	int i = 1;
	while(vocabulary[i-1] != "#")
	{
		cin >> vocabulary[i];
		i++;
	}
	vocabulary[--i] = "";
	string row;
	while(getline(cin, row, '\n'))
	{
	//	
		string word = "";
		int last_pos = 0;
		for(int i = 0; i <= row.length(); i++)
		{
			if(isalpha(row[i]))
			{
				word += row[i];
				if(state == 0)
				{
					last_pos = i;
					state = 1;
				}
			}
			else
			{
				//correct(word, row, last_pos);
				///////////////////
				for(int i = 1; i < 102; i++)
				{
					if(compare(vocabulary[i], word))
					{
						errors++;
						for(int j = last_pos; j < last_pos + word.length(); j++)
						{
							row[j] = vocabulary[i][j - last_pos] ;
						}
					}
				}
				////////////////////
				word = "";
				state = 0;//before any word
			}
		}
		cout << row << endl;
	}
	cout << errors;
	
	return 0;
}