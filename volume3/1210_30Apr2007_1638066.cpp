//1210
#include <stdio.h>
#include <iostream>
int next[35];
int current[35];
using namespace std;
int main()
{
	int levels;
	scanf("%d", &levels);
	int i, j;
	int NumNext;
	
	for(i = 0; i < 35; i++)next[i] = 999999;


	for(i = 1; i <= levels; i++)
	{
		scanf("%d", &NumNext);
		
		for(j = 1; j <= NumNext; j++)
		{
			int ThisHip = 1000, Prise = 0;
			while(ThisHip)
			{
				scanf("%d", &ThisHip);
				if(ThisHip == 0)break;
				scanf("%d", &Prise);
				next[j] = (current[ThisHip]+Prise < next[j])?(current[ThisHip]+Prise):(next[j]);
			}	
		
		}
		char ch;
		if(i != levels)//scanf("%d", &ch);
				cin>>ch;
		for(j = 0; j < 35; j++)current[j] = next[j];
		for(j = 0; j < 35; j++)next[j] = 999999;
		
		
	}

	int answer = 999999;
	for(i = 1; i <= NumNext; i++)
	{
		if(current[i] < answer)answer = current[i];
	}

	printf("%d", answer);
	
	return 0;
}
// -32768  32767;