//1282
#include <stdio.h>
int N;
int father[1003];
int meen[1003];
int get_father_meen(int m,int flag)
{
int i, need = 0, getted;
if(meen[m] != 256)return meen[m];
if(flag == 1)
{
	need = -1;
	for(i = 2; i <= N; i++)
	{	
		if(father[i] == m)
		{
			getted = get_father_meen(i,2);
			if(need < getted)need = getted;
			if(need == 1)break;
		}
			
	}
}
if(flag == 2)
{
	need = 1;
	for(i = 2; i <= N; i++)
	{	
		if(father[i] == m)
		{
			getted = get_father_meen(i,1);
			if(need > getted)need = getted;
			if(need == -1)break;
		}
	}
}
return need;
}

int main()
{
int i;
for(i = 0; i < 1003; i++)meen[i] = 256;

char *ch = new char;
scanf("%d", &N);
for(i = 2; i <= N; i++)
{
	scanf("%c", ch);
	scanf("%c", ch);
	if(*ch == 'N')
	{
		scanf("%d", &father[i]);
	}
	if(*ch == 'L')
	{
		scanf("%d%d", &father[i], &meen[i]);
	}
}


int answer = get_father_meen(1,1);

if(answer == 1)
{
	printf("+1");
}
else printf("%d", answer);

return 0;
}
