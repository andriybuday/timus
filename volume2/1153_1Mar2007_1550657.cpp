//this is unsigned BigInt based on __int64
//Andriy Buday (c)
#include <iostream>

#include <cmath>
#include <ctime>
#include <ctime>
#include <vector>
#include <string>
using namespace std;
#define INT64 __int64
#define UINT unsigned int
#define MAXNUM __int64(999999999)
#define BASE __int64(1000000000)
#define SIZE 70
inline INT64 string_to_INT64(string str)
{
	int len = int(str.length());
	INT64 res = 0;
	INT64 mult = 1;
	int i = 0;
	for(i = len-1; i >= 0; --i)
	{
		res += mult*(str[i] - 48);
		mult*=10;
	}
	return res;
}
struct BigInt
{
	INT64 a[SIZE];
	UINT pos;
	BigInt()
	{
		for (UINT i = 0; i < SIZE; i++)a[i] = 0;
		pos = 0;
	}
	BigInt(__int64 val)
	{
		for (UINT i = 0; i < SIZE; i++)a[i] = 0;
		a[0] = val%BASE;
		val -= val%BASE;
		a[1] = val;
		(a[1])?pos = 1:pos = 0;
	}
	BigInt(const BigInt& bint)
	{
		pos = bint.pos;
		for (UINT i = 0; i < SIZE; ++i)a[i] = bint.a[i];
	}
	BigInt(string& str)
	{
		BigInt();
		int sections = int(str.length()/9);
		int i;
		for (i = 0; i < int(SIZE); i++)a[i] = 0;

		UINT last_digits = UINT(str.length()%9);
		int end = int(str.length()-1);

		for (i = 0; i < sections; i++)
		{
			a[i] = string_to_INT64(str.substr(end-8, 9));	
			end -= 9;
		}
		pos = sections-1;
		if (last_digits)
		{
			pos = sections;
			a[i] = string_to_INT64(str.substr(0, last_digits));
		}
	}
	inline BigInt& operator =(const BigInt& bint)
	{
		if (this == &bint)return *this;
		pos = bint.pos;
		for (int i = 0; i < SIZE; i++)a[i] = bint.a[i];
		return *this;
	}
	inline const bool operator < (const BigInt& bint)const
	{
		if (pos == bint.pos)
		{
			int i = pos;
			while(i > 0 && a[i] == bint.a[i])i--;
			return a[i] < bint.a[i];

		}
		return (pos < bint.pos);
	}
	inline const bool operator == (const BigInt& bint)const
	{
		if (pos != bint.pos)return false;
		for (UINT i = 0; i <= pos; ++i)
		{
			if (a[i] != bint.a[i])return false;
		}
		return true;
	}
	void print()
	{
		printf("%I64d", a[pos]);
		for (int i = pos-1; i >= 0; --i)
		{
			printf("%09I64d", a[i]);
		}
	}
};
//////////////////////////////////////////////////////////////////////////
//Mul(A, B, C),  Mul(A, B, A) is not working

//C = A+B expression Add(A, B, A) is right
inline void Add(BigInt& A,BigInt& B, BigInt& C)
{	
	INT64 next = 0;
	INT64 current = 0;
	int i = 0;
	if (A.pos < B.pos)
	{
		Add(B, A, C);
		return;
	}
	for(i = 0; i <= (int)B.pos; ++i)
	{
		current = A.a[i] + B.a[i] + next;
		if (current >= BASE)
		{
			C.a[i] = current - BASE;
			next = 1;
		} else {
			C.a[i] = current;
			next = 0;
		}
	}
	for (; i <= (int)A.pos; ++i)
	{
		current = A.a[i] + next;
		if (current >= BASE)
		{
			C.a[i] = current - BASE;
			next = 1;
		}
		else
		{
			C.a[i] = current;
			next = 0;
		}
	}
	if (next)
	{
		++C.pos;
		C.a[C.pos] = next;
	}
	else C.pos = A.pos;
	for (i = C.pos + 1; i < SIZE; ++i)C.a[i] = 0;
}
//C = A-B expression Sub(A, B, A) is right
inline void Sub(BigInt& A,BigInt& B, BigInt& C)
{
	int i = 0;
	INT64 next = 0;
	INT64 current = 0;
	if (A.pos < B.pos)return;

	for (i = 0; i <= (int)B.pos; i++)
	{
		current = A.a[i] - B.a[i] + next;
		if (current < 0)
		{
			C.a[i] = current + BASE;
			next = -1;
		}
		else
		{
			C.a[i] = current;
			next = 0;
		}
	}
	for (; i <= (int)A.pos; ++i)
	{
		current = A.a[i] + next;
		if (current < 0)
		{
			C.a[i] = current + BASE;
			next = -1;
		}
		else
		{
			C.a[i] = current;
			next = 0;
		}
	}
	for (i = A.pos + 1; i < SIZE; ++i)C.a[i] = 0;
	i = A.pos;
	while(C.a[i] == 0)i--;
	if (i >= 0)C.pos = i;
	else C.pos = 0;
}
//C = A*B Mul(A, B, A) is not working
inline void Mul(BigInt& A,BigInt& B,BigInt& C)
{
	int i, j;
	INT64 temp = 0, carry = 0;

	for (i = 0; i <= (int)(A.pos + B.pos + 1); i++)C.a[i] = 0;

	for (i = 0; i <= int(A.pos); i++) 
	{
		carry = 0;
		for (j = 0; j <= int(B.pos); j++) 
		{
			temp = A.a[i] * B.a[j] + C.a[i+j] + carry;
			carry = temp/BASE;
			C.a[i+j] = temp - carry*BASE;
		}
		C.a[i+j] = carry;
	}
	i = A.pos + B.pos + 1;
	if (C.a[i] == 0)i--;
	C.pos = i;
}
//C = A*B Smul(A, B, A) is right
inline void SMul(BigInt& A, const INT64 B, BigInt& C)
{
	UINT i;
	INT64 current, next = 0;
	for (i = 0; i <= A.pos; i++)
	{
		current = A.a[i]*B + next;
		next = current / BASE;
		C.a[i] = current - next*BASE; // с[i] = temp % BASE
	}
	if (next)
	{
		C.a[i] = next;
		C.pos = A.pos+1;
	}
	else C.pos = A.pos;
}
//Q = A/B , R = A%B
inline void SDiv(BigInt& A, INT64 B, BigInt& C, INT64& R)
{
	INT64 r = 0;
	INT64 i, temp;
	for (i = A.pos; i >= 0; i--)
	{
		temp = r*BASE + A.a[i];
		C.a[i] = temp / B;
		r = temp - C.a[i]*B;
	}
	R = r;
	i = A.pos + 1;
	while ( (i > 0) && (C.a[i] == 0) ) i--;
	C.pos = UINT(i);
}
//////////////////////////////////////////////////////////////////////////
inline void sqrt(BigInt& A, BigInt& C)
{
	//using binary serch
	///binary search
	INT64 one = 1;

	BigInt curr, roof, floor, kv;
	roof.pos = A.pos/2 + 1;
	floor.pos = (int(A.pos/2) - 1 > 0)?(A.pos/2 - 1):(0);

	roof.a[roof.pos] = 1;
	floor.a[floor.pos] = 1;
	BigInt temp;
	Sub(roof,floor,temp);//temp = roof - floor
	SDiv(temp,2,temp,one);//

	Add(floor,temp,curr);
	while(true)
	{
		Mul(curr,curr,kv);
		if(A == kv)
		{
			C = curr;
			return;
		}
		if(!(A < kv))
		{
			floor = curr;
			//curr = curr + (roof-curr)/2;
			BigInt sub_me;
			Sub(roof,floor,sub_me);
			BigInt add_me;
			SDiv(sub_me,2,add_me,one);
			Add(floor,add_me,curr);
			continue;
		}
		if(A < kv)
		{
			roof = curr;
			BigInt sub_me;
			Sub(roof,floor,sub_me);
			BigInt add_me;
			SDiv(sub_me,2,add_me,one);
			Sub(roof,add_me,curr);
			//curr = curr - (curr - floor)/2;
			continue;
		}
	}
	return;
}
int main()
{
	/*
	INT64 n, i, res;
	while(true)
	{

	cin >> n;
	res = 0;
	for(i = 1; i <= n; i++)
	{
	res += i;
	}
	cout << res<< endl;
	*/
	/*
	string a = "40876752400";
	string b = "40000400001";
	BigInt aa(a);
	BigInt bb(b);
	cout << (aa < bb);
	*/
	INT64 R;
	BigInt one(1);
	string num;
	cin >> num;
	//num = "5000050000";
	BigInt ans(num);
	SMul(ans,8,ans);
	Add(ans,one,ans);
	//ans.print();
	//printf("\n");
	sqrt(ans,ans);
	Add(ans,one,ans);
	BigInt answer;
	SDiv(ans,2,answer,R);
	Sub(answer,one,answer);
	answer.print();
	printf("\n");
	
	//}
}