#include <stdio.h>
int NSD(int min, int max)
{
	int temp = 1;
	while(temp!=0)
	{
		if(min != 0)temp = max%min;
		if(min == 0)continue;
		max = min;
		min = temp;
		if(temp == 0)continue;
	}
	return max;
}

class wheel{
public:
int num;
int den;

wheel():num(-1), den(-1){}
wheel(int n):num(n), den(1){}
wheel(int n, int d)
{
if(n == 0){num = 0; den = 1; return;}
if(d < 0){n = -n;d = -d;} 
if(!(n%d)){num = n/d; den = 1; return;}
int temp_d = d;
///////
//num = 
int sign_n = (n<0)?(-1):(1);
int sign_d = (d<0)?(-1):(1);
if(n < 0)n = -n;
if(d < 0)d = -d;
int min = (n < d)?(n):(d);
int max = (n > d)?(n):(d);
int div = NSD(min, max);
num = (n/div)*sign_n;
den = (d/div)*sign_d;
/////
/*
while(temp_d)
{
	temp_d--;
	if((!(n%temp_d))&&(!(d%temp_d)))
	{
	num = n/temp_d; den = d/temp_d; return;
	}
}

num = n;
den = d;
*/
}
void out()
{
	if(num == 0){printf("0/1\n"); return;}
	printf("%d/%d\n", num, den);
}

};
int amount[1002];
int index[1002][1002];
wheel warr[1002];
bool was_indet[1002];
int to_indet[1002][2];
int counter;
void initialization(int jj,int ind)
{
warr[ind] = wheel(-(amount[jj]*warr[jj].num), amount[ind]*warr[jj].den);
}
void init(int jj){
int i = 0;
while(index[jj][i])
{
int ind = index[jj][i];
if(was_indet[ind]){i++; continue;}
//warr[ind] = wheel(-(amount[jj]*warr[jj].num), amount[ind]*warr[jj].den);
//initialization(jj ,ind);
to_indet[counter][0] = jj;
to_indet[counter][1] = ind;
counter++;
was_indet[ind] = 1;
init(ind);//
i++;
}
return;
}
int main(){

int N, i, j;
int index_to_read;
scanf("%d", &N);
for(i = 1; i <= N; i++)
{

j=0;
scanf("%d", &amount[i]);

do{
scanf("%d", &index_to_read);
index[i][j] = index_to_read;
j++;
}while(index_to_read);

}

scanf("%d", &j);
scanf("%d", &i);

warr[j] = wheel(i);
init(j); //main recursive function
for(i = 0; i < N; i++)initialization(to_indet[i][0],to_indet[i][1]);
for(i = 1; i <= N; i++)
{
	if(warr[i].den == -1)
	{
		printf("0/1\n");
	}
	else
	{
		warr[i].out();
	}
}
return 0;
}
