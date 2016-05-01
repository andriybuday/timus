//1206
#include <stdio.h>
//int array_for_BIGINT_are_here[100];
//#define arr array_for_BIGINT_are_here
#define base 10000
#define max_digit 9999

class IamInt{
public:
	//int base;
	int arr[100];
	void zero(){for(int i = 0; i<100; i++)arr[i] = 0;}
	IamInt(){zero();}
	IamInt(IamInt& a){		
		for(int i = 0;i<100; i++){
			arr[i] = a.arr[i];
		}
	}
	IamInt(int a){zero();arr[0] = a;}//

	void print(){
		int  i = 99;
		while(!arr[i])i--;
		if(i == 0)
		{
			printf("%d", arr[0]);
			return;
		}
		printf("%d", arr[i]);
		while(i--)
		{
				if(arr[i]%base >= 1000)
				{
					printf("%d", arr[i]);
					continue;
				}else
					if(arr[i]%base >= 100)
					{
						printf("0%d", arr[i]);
						continue;
					}else
						if(arr[i]%base >= 10)
						{
							printf("00%d", arr[i]);
							continue;
						}else
							if(arr[i]%base >= 1)
							{
								printf("000%d", arr[i]);
								continue;
							}
			printf("0000");
		}
	}
	
	IamInt operator +(const IamInt& a){
		IamInt temp;
		int sum_to_next = 0;
		int  pointer = 99;
		while(!arr[pointer])pointer--;
		int i = 0;
		while(sum_to_next||pointer>=0){
			temp.arr[i] = ((arr[i] + a.arr[i] + sum_to_next) > max_digit) ? ((arr[i] + a.arr[i] + sum_to_next)%10000) : (arr[i] + a.arr[i] + sum_to_next);
			sum_to_next = (arr[i] + a.arr[i])/10000;		
			i++;
			pointer--;
		}
		return temp;
	}
	IamInt operator +(const int& a){
		IamInt temp;
		int sum_to_next = a;
		int  pointer = 99;
		while(!arr[pointer]&&(pointer>=0))pointer--;
		int i = 0;
		while(sum_to_next||pointer>=0){
			temp.arr[i] = ((arr[i]  + sum_to_next) > max_digit) ? ((arr[i] + sum_to_next)%10000) : (arr[i] + sum_to_next);
			sum_to_next = (arr[i])/10000;		
			i++;
			pointer--;
		}
		return temp;
	}
	IamInt operator +=(const IamInt& a){
		IamInt temp;
		int sum_to_next = 0;
		int  pointer = 99;
		while(!arr[pointer])pointer--;
		int i = 0;
		while(sum_to_next||pointer>=0){
			temp.arr[i] = ((2*arr[i] + a.arr[i] + sum_to_next) > max_digit) ? ((2*arr[i] + a.arr[i] + sum_to_next)%10000) : (2*arr[i] + a.arr[i] + sum_to_next);
			sum_to_next = (2*arr[i] + a.arr[i])/10000;		
			i++;
			pointer--;
		}
		*this = temp;
		return temp;
	}
	IamInt operator = (const IamInt& a){
		IamInt *temp = this;
		for(int i = 0;i<100; i++){
			temp->arr[i] = a.arr[i];
		}	
		return *temp;
	}

};

IamInt power(int exp)
{
	//int base = 55;
	int i, j;
	IamInt sum(1);
	for(i=1;i<=exp;i++)
	{
		IamInt tmp = sum;
		//IamInt tmp2 = sum;
		for(j = 1; j<55; j++)
		{
			sum = sum + tmp;//sum=sum*base;
		}
		//sum = tmp;
	}
	return sum;
}

int main()
{

	int i;
	int digit;
	IamInt answer(1);

	scanf("%d",&digit);

	if(digit==1){
		printf("36");
		return 0;
	}
	else
	{// answer=36*power(55,digit-1);
		IamInt temp_ = power(digit-1);
		answer = temp_;
		for(i = 1; i<36; i++)answer = answer + temp_;

		answer.print();
		return 0;
	}  

return 0;
}

//1206
/*
#include<stdio.h>
_int64 power(__int64 base,__int64 exp)
{
__int64 i;
__int64 sum;
sum=1;
for(i=1;i<=exp;i++) sum=sum*base;
return sum;
}
int main()
{
__int64 digit;
__int64 answer;

scanf("%I64d",&digit);

if(digit==1) answer=36;
else answer=36*power(55,digit-1);

printf("%I64d",answer);
}  
*/
