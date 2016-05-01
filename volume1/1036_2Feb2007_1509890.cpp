//1036_SB
#include <iostream>
#include <fstream>
//#include <string>
//#include <cmath>
using namespace std;
#define SIZE 50
#define BASE 10000
void TL()
{
	while(true){}
}
struct Bint{
	int	arr[SIZE];
	Bint(){for(int i = 0; i < SIZE; i++)arr[i] = 0;}
	explicit Bint(const int val)
	{
		for(int i = 0; i < SIZE; i++)arr[i] = 0;
		arr[0] = val;
	}

	friend Bint& BigSum(const Bint& a, const Bint& b)//we add a and b in answer
	{
		Bint answer;
		int next = 0;
		int current = 0;
		int i;
		for(i = 0; i < SIZE; i++)
		{
			current = a.arr[i] + b.arr[i] + next;
			answer.arr[i] = current%BASE;
			next = current/BASE;
		}
		return answer;
	}
	friend Bint& BigMinus(const Bint& a, const Bint& b)//a-b
	{
		Bint answer;
		int next = 0;
		int current = 0;
		int i;
		for(i = 0; i < SIZE; i++)
		{
			if(i >= SIZE-2)
			{
				answer.arr[i] = 0;
				break;
			}
			current = a.arr[i] - b.arr[i] - next;
			if(current < 0)
			{
				current += BASE;
				next = 1;
			}else next = 0;

			answer.arr[i] = current;
		}
		return answer;
	}

	friend Bint& Multi(const Bint& a, const int k)
	{
		Bint answer;
		int next = 0;
		int current = 0;
		int i;
		for(i = 0; i < SIZE; i++)
		{
			current = k*a.arr[i] + next;
			answer.arr[i] = current%BASE;
			next = current/BASE;
		}
		return answer;
	}
/*
	void print()
	{
		int i = SIZE-1, j;
		while((!arr[i])&&(i > 0))i--;

		printf("%d", arr[i]);
		for(j = i-1; j >= 0; j--)
		{
			if(arr[j]%BASE >= 10000)
				{
					printf("%d", arr[j]);
					continue;
				}else
					if(arr[j]%BASE >= 1000)
					{
						printf("0%d", arr[j]);
						continue;
					}else
						if(arr[j]%BASE >= 100)
						{
							printf("00%d", arr[j]);
							continue;
						}else
							if(arr[j]%BASE >= 10)
							{
								printf("000%d", arr[j]);
								continue;
							}else
								if(arr[j]%BASE >= 1)
								{
								printf("0000%d", arr[j]);
								continue;
								}
							
			printf("00000");
		}
	}
	*/
	void print()
	{
		int i = SIZE-1, j;
		while((!arr[i])&&(i > 0))i--;

		printf("%d", arr[i]);
		for(j = i-1; j >= 0; j--)
		{
			if(arr[j]%BASE >= 1000)
				{
					printf("%d", arr[j]);
					continue;
				}else
					if(arr[j]%BASE >= 100)
					{
						printf("0%d", arr[j]);
						continue;
					}else
						if(arr[j]%BASE >= 10)
						{
							printf("00%d", arr[j]);
							continue;
						}else
							if(arr[j]%BASE >= 1)
							{
								printf("000%d", arr[j]);
								continue;
							}			
			printf("0000");
		}
	}
};
// C = A*B, не работает вызов Mul(A, B, A)
void BigMultiplying(const Bint &a, const Bint &b, Bint &c) 
{
	int a_size = SIZE-1;
	while((!a.arr[a_size])&&(a_size > 0))a_size--;
	a_size++;

	int b_size = SIZE-1;
	while((!b.arr[b_size])&&(b_size > 0))b_size--;
	b_size++;


	int i, j;
	int temp = 0, carry = 0;

	for (i = 0; i < a_size; i++) 
	{
		carry = 0;
	// вычисление временного результата с одновременным прибавлением
	// его к c[i+j] (делаются переносы)
		for (j = 0; j < b_size; j++) 
		{
			temp = a.arr[i] * b.arr[j] + c.arr[i+j] + carry;
			carry = temp/BASE;
			c.arr[i+j] = temp - carry*BASE;
		}
		c.arr[i+j] = carry;
	}
	// Установить размер по первой ненулевой цифре
	/*
	i = A.Size + B.Size - 1;
	if ( c[i] == 0 ) i--;
	C.Size = i+1;
	*/
}
Bint a[52][504];
Bint kvadrat[105];
int main()
{

	///init of matrix
	for (int i = 0; i < 10; i++)a[1][i] = Bint(1);
	for (int i = 0; i < 52; i++)a[i][0] = Bint(1);

	for (int i = 2; i <= 51; i++)
	{
		for(int j = 1; j < 10; j++)
		{
			a[i][j] = BigSum(a[i][j-1],a[i-1][j]);
		}
		int middle = 0;
		if (i%2)//непарне
		{
			middle = (i*9 - 1)/2;//перше з однакових
			for (int j = 10; j <= middle; j++)
			{
				Bint temp = BigSum(a[i][j-1],a[i-1][j]);
				a[i][j] = BigMinus( temp , a[i-1][j-10]);
			}
			//зворотне копіювання
			for (int j = 1; j <= middle + 1; j++)
			{
				a[i][j + middle] = a[i][middle - j + 1];
			}
		
		}
		else//парне
		{
			middle = i*9 / 2; //позиція на якій буде середній елемент
			for (int j = 10; j <= middle; j++)
			{
				Bint temp = BigSum(a[i][j-1] , a[i-1][j]);
				a[i][j] = BigMinus( temp , a[i-1][j-10]);
			}
			//зворотне копіювання
			for (int j = 1; j <= middle; j++)
			{
				a[i][j + middle] = a[i][middle - j];
			}
		}
	
	}
/*
	Bint a(89023), b(76833);
	Bint c = BigSum(a, b);
	for(int i = 0; i < 100; i++)c = BigSum(c, c);
	Bint savec = c;
	c = BigSum(c, b);
	c.print();
	cout << endl;
	savec.print();
	cout << endl;
	
	savec = BigMinus(c, savec);
	savec.print();
	*/
	
	int n, sum;
	cin >> n >> sum;
	if(sum%2)
	{
		printf("0\n");
		return 0;
	}

	sum /= 2;
	Bint ans = a[n][sum];
	Bint copy_ans1 = ans;
	Bint copy_ans2 = ans;
	Bint answer;
	BigMultiplying(copy_ans1 , copy_ans2 , answer);
	Bint canswer = answer;

//	ans.print();
//	cout << endl;

	canswer.print();
	cout << endl;
	exit(0);

	//answer = ans*ans;
	//cout << a[n][sum];//*a[n][sum] << endl;











	///outputting all the table in out file!

	//ofstream ofs ("1036_all_table_Bint.txt");
	/*
	int t = 0;
	for(int i = 0; i < 52; i++)
	{
		for(int j = 0; j < 452; j++)
		{
			a[i][j].print();
			cout << " ";
		}
		cout << endl;
		cin >> t;
		system("cls");
	}
	*/

	return 0;
}