//this is unsigned BigInt based on __int64
//Andriy Buday (c)
#define _CRT_SECURE_NO_DEPRECATE
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
#define SIZE 2000
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
	inline BigInt& operator ++()
	{
		int i = 0;
		while(a[i] == MAXNUM)
		{
			a[i] = 0;
			++i;
		}
		if(i > pos)++pos;
		++a[i];
		return *this;
	}
	inline BigInt& operator --()
	{
		if(pos == 0)
		{
			if(a[0])--a[0];
			return *this;
		}
		int i = 0;
		while(a[i] == 0)
		{
			a[i] = MAXNUM;
			++i;
		}
		--a[i];
		if(a[i] == 0 && i == pos)--pos;
		return *this;
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
	//using binary search
	INT64 one = 1;
	BigInt curr, roof, floor, temp_pow2, add_me, sub_me;

	// C means curr
	roof.pos = A.pos/2;
	floor.pos = ((A.pos/2)-1 > 0)?((A.pos/2) - 1):(0);

	roof.a[roof.pos] = MAXNUM;
	floor.a[floor.pos] = 1;
	Sub(roof,floor,temp_pow2);//temp = roof - floor
	SDiv(temp_pow2,2,curr,one);//
	Add(floor,curr,curr);
	while(true)
	{
		Mul(curr,curr,temp_pow2);
		if(A == temp_pow2)
		{
			C = curr;
			return;
		}
		if(!(A < temp_pow2))
		{
			floor = curr;
			//curr = curr + (roof-curr)/2;
			Sub(roof,floor,sub_me);
			SDiv(sub_me,2,add_me,one);
			Add(floor,add_me,curr);
			continue;
		}
		if(A < temp_pow2)
		{
			roof = curr;	
			Sub(roof,floor,sub_me);
			SDiv(sub_me,2,add_me,one);
			Sub(roof,add_me,curr);
			//curr = curr - (curr - floor)/2;
			continue;
		}
	}
	return;
}
struct matrix
{
	BigInt F[2][2];
	void print()
	{
		F[0][0].print();
		printf(" ");
		F[1][0].print();
		printf("\n");
		F[0][1].print();
		printf(" ");
		F[1][1].print();
		printf("\n");
	}
};
matrix powers[18];
void make_powers()
{
	powers[1].F[0][0] = BigInt(1);
	powers[1].F[1][0] = BigInt(1);
	powers[1].F[0][1] = BigInt(1);
	powers[1].F[1][1] = BigInt(2);

	powers[0] = powers[1];

	BigInt temp1001;
	BigInt temp0000;
	BigInt temp0001;
	BigInt temp0111;
	BigInt temp0010;
	BigInt temp1011;
	BigInt temp1111;
	for(int i = 2; i < 17; ++i)
	{
		Mul(powers[i-1].F[0][0],powers[i-1].F[0][0],temp0000);
		Mul(powers[i-1].F[1][0],powers[i-1].F[0][1],temp1001);
		Mul(powers[i-1].F[0][0],powers[i-1].F[0][1],temp0001);
		Mul(powers[i-1].F[0][1],powers[i-1].F[1][1],temp0111);
		Mul(powers[i-1].F[0][0],powers[i-1].F[1][0],temp0010);
		Mul(powers[i-1].F[1][0],powers[i-1].F[1][1],temp1011);
		Mul(powers[i-1].F[1][1],powers[i-1].F[1][1],temp1111);

		Add(temp0000,temp1001,powers[i].F[0][0]);
		Add(temp0001,temp0111,powers[i].F[0][1]);
		Add(temp0010,temp1011,powers[i].F[1][0]);
		Add(temp1001,temp1111,powers[i].F[1][1]);
	}

}
void mul_matrixes(matrix& a,matrix& b, matrix& c)
{
	BigInt temp1001;
	BigInt temp0000;
	BigInt temp0001;
	BigInt temp0111;
	BigInt temp0010;
	BigInt temp1011;
	BigInt temp1111;
	

		Mul(a.F[0][0],b.F[0][0],temp0000);
		Mul(a.F[1][0],b.F[0][1],temp1001);
		Mul(a.F[0][0],b.F[0][1],temp0001);
		Mul(a.F[0][1],b.F[1][1],temp0111);
		Mul(a.F[0][0],b.F[1][0],temp0010);
		Mul(a.F[1][0],b.F[1][1],temp1011);
		Mul(a.F[1][1],b.F[1][1],temp1111);

		Add(temp0000,temp1001,c.F[0][0]);
		Add(temp0001,temp0111,c.F[0][1]);
		Add(temp0010,temp1011,c.F[1][0]);
		Add(temp1001,temp1111,c.F[1][1]);
}
void pow_F(matrix& m,int n)
{
	for(int i = 1; i < n; ++i)
	{
		Add(m.F[0][0], m.F[0][1], m.F[0][0]);
		Add(m.F[0][1], m.F[0][0], m.F[0][1]);
		Add(m.F[1][0], m.F[1][1], m.F[1][0]);
		Add(m.F[1][1], m.F[0][1], m.F[1][1]);
	}
}
int get_power(int n)
{
	int p = 0;
	while(pow(2.0, double(p)) <= n)p++;
	return (p-1);
}
int main()
{
	make_powers();
	int n;
	scanf("%d", &n);

	BigInt ans;
	matrix tmp;
	if(!(n%2))
	{
		int nth_power = get_power(n);
		tmp = powers[nth_power];

		int next = n - (int)pow(2.0,nth_power);
		nth_power  = get_power(next);
		if(nth_power > 0)mul_matrixes(tmp,powers[nth_power],tmp);
		
		next -= (int)pow(2.0,nth_power);
		nth_power  = get_power(next);
		if(nth_power > 0)mul_matrixes(tmp,powers[nth_power],tmp);
		
		next -= (int)pow(2.0,nth_power);
		nth_power  = get_power(next);
		if(nth_power > 0)mul_matrixes(tmp,powers[nth_power],tmp);
		
		
		pow_F(tmp, (next - (int)pow(2.0, nth_power))/2 + 1);

		Add(tmp.F[0][0], tmp.F[1][1], ans);

		ans.print();
		printf("\n");
	}
	else
	{
		n--;
		int nth_power = get_power(n);
		tmp = powers[nth_power];

		int next = n - (int)pow(2.0,nth_power);
		nth_power  = get_power(next);
		if(nth_power > 0)mul_matrixes(tmp,powers[nth_power],tmp);
		
		next -= (int)pow(2.0,nth_power);
		nth_power  = get_power(next);
		if(nth_power > 0)mul_matrixes(tmp,powers[nth_power],tmp);

		pow_F(tmp, ((next + 1) - (int)pow(2.0, nth_power))/2 + 1);

		ans = tmp.F[1][0];
		pow_F(tmp,2);
		Add(ans, tmp.F[1][0], ans);
		ans.print();
		printf("\n");
	}

	return 0;
}