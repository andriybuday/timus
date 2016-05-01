//1253_SB
#include <iostream>
//#include <stdio.h>
#include <string>
using namespace std;
char answ[1000001];
int check = 0;
int error = 0;
char **necr;
int N;
//int dep = 0;
int global_pos = 0;

void create_necrolog(char *print_necr, int dep)
{

	if(dep  >= 200){printf("#");exit(0);}
	int i;
	for(i = 1; i < 1001; i++)
	{
		if(print_necr[i] == '*')
		{
			dep++;
			create_necrolog(necr[print_necr[i+1] - 49], dep);
			++i;
		}
		else
		{
			if(int(print_necr[i]) == 0)break;
			
			//if((print_necr[0] != '\n')||(print_necr[1] != '\n'))continue;
			answ[global_pos++] = print_necr[i];
			if(global_pos > 1000000){printf("#"); exit(0);} 
		}
	}
	dep--;
	return;
}

int main()
{
	int i;
	cin >> N;
	necr = new char *[N];
	for(i = 0; i <= N; i++)
	{
		necr[i] = new char [1001];
	}

	for(i = 0; i < N; i++)
	{
		cin.getline(necr[i], 1001,'#');
		//printf("%s",necr[i]);
	}
	
	create_necrolog(necr[0], 0);
	
	if(check == 1)
	{
		printf("#");
		return 0;
	}
	
	printf("%s",answ);
	

	return 0;
}