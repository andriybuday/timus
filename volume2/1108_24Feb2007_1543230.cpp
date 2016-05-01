#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
using namespace std;
//#define 
/* 999999999
 *
 *
 */
#define INT64 __int64
#define UINT unsigned int
#define MAXNUM __int64(999999999)
#define BASE __int64(1000000000)
#define SIZE 2990

/*
class Polint;
struct PolMul
{
	const Polint& poli_1;
	const Polint& poli_2;
	PolMul(const Polint& pol1, const Polint& pol2):poli_1(pol1),poli_2(pol2){}
	operator Polint();
};
inline PolMul operator *(const Polint& pol1, const Polint& pol2)
{
	return PolMul(pol1, pol2);
}
*/
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
class Polint
{
public:
	INT64 a[SIZE];
	bool sign;
	UINT pos;
public:
	Polint()
	{
		sign = true;
		for (UINT i = 0; i < SIZE; i++)a[i] = 0;
		pos = 0;
	}
	Polint(__int64 pol)
	{
		//if ()
		sign = (pol >= 0)?true:false;
		pol = (pol >= 0)?pol:-pol;
		INT64 pos_0 = 0, pos_1 = 0;
		(pol > MAXNUM)?(pos_1 = pol/BASE, pos_0 = pol%BASE):(pos_0 = pol);
		(pos_1)?(pos = 1):(pos = 0);

		for (UINT i = 0; i < SIZE; i++)a[i] = 0;
		
		a[0] = pos_0;
		a[1] = pos_1;
	}
	Polint(string& str)
	{
		Polint();
		sign = true;
		if (str[0] == '-')
		{
			sign = false;
			str.erase(str.begin());
		}
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

	Polint operator =(const Polint& pol)
	{
		if (*this == pol)return *this;
		pos = pol.pos;
		sign = pol.sign;
		for (int i = 0; i < SIZE; i++)a[i] = pol.a[i];
		return *this;
	}
	friend istream& operator >> (istream& is, Polint& pol)
	{
		string str;
		is >> str;
		pol = Polint(str);
		return is;
	}
	friend ostream& operator << (ostream& os, Polint& pol)
	{
		pol.print();
		return os;
	}
	inline const bool operator < (const Polint& pol)const
	{
		//both is positive
		if (sign && pol.sign)
		{
			if (pos == pol.pos)
			{
				return (a[pos] < pol.a[pos]);
			}
			return (pos < pol.pos);
		}
		//both is negative
		if (!sign && !pol.sign)
		{
			if (pos == pol.pos)
			{
				return (a[pos] > pol.a[pos]);
			}
			return (pos > pol.pos);	
		}
		//different signes
		return (sign && !pol.sign)
			?(false):(true);
	}
	inline const bool operator == (const Polint& pol)
	{
		if (pos != pol.pos)return false;
		if (pos > 0)
		{
			if (sign != pol.sign)return false;
		}
		if (pos == 0 && a[0] != 0)
		{
			if (sign != pol.sign)return false;
		}
		for (int i = 0; i <= int(pos); i++)
		{
			if (a[i] != pol.a[i])return false;
		}
		return true;
	}
	const bool less_abs(const Polint& pol)const
	{
		if (pos == pol.pos)
		{
			return (a[pos] < pol.a[pos]);
		}
		return (pos < pol.pos);
	}
	UINT capacity()const {return SIZE;}
	UINT GetPos()const{return pos;}
	void print()
	{
		if (*this == Polint(0))
		{
			printf("0"); return;
		}
		printf((sign)?(""):("-"));
		printf("%I64d", a[pos]);
		for (int i = pos-1; i >= 0; --i)
		{
			printf("%09I64d", a[i]);
		}
	}
	//////////////////////////////////////////////////////////////////////////
	// Big Functions declarations
	inline friend void PolSameSignsSum(const Polint& pol1, const Polint& pol2, Polint& res);
	inline friend void PolSum(const Polint& pol1, const Polint& pol2, Polint& res);
	inline friend void PolMinus(const Polint& pol1, const Polint& pol2, Polint& res);
	inline friend void PolSimpleOneWayMinus(const Polint& pol1, const Polint& pol2, Polint& res);
	inline friend void PolMul(const Polint& pol1, const Polint& pol2,Polint& res);
	inline void PolSimpleDiv(const Polint &pol1, const INT64 B, Polint &res, INT64 &R);
	friend Polint operator + (const Polint& pol1, const Polint& pol2)
	{
		Polint res;
		PolSum(pol1, pol2, res);
		return res;
	}
	friend Polint operator - (const Polint& pol1, const Polint& pol2)
	{
		Polint res;
		PolMinus(pol1, pol2, res);
		return res;
	}
	friend Polint operator * (const Polint& pol1, const Polint& pol2)
	{
		Polint res;
		PolMul(pol1, pol2, res);
		return res;
	}
};
//////////////////////////////////////////////////////////////////////////
inline void PolMul(const Polint& pol1, const Polint& pol2,Polint& res)
{
for (int i = 0; i < SIZE; i++)res.a[i] = 0;
	int i, j;
	INT64 temp = 0, carry = 0;

	for (i = 0; i <= int(pol1.pos); i++) 
	{
		carry = 0;
		for (j = 0; j <= int(pol2.pos); j++) 
		{
			temp = pol1.a[i] * pol2.a[j] + res.a[i+j] + carry;
			carry = temp/BASE;
			res.a[i+j] = temp - carry*BASE;
		}
		res.a[i+j] = carry;
	}
	i = pol1.pos + pol2.pos + 3;
	while(res.a[i] == 0) i--;
	if(i >= 0)res.pos = i;
	else res.pos = 0;
	if (!pol1.sign && pol2.sign || pol1.sign && !pol2.sign)
	{
		res.sign = false; return;
	}
	res.sign = true;
}
inline void PolSameSignsSum(const Polint& pol1, const Polint& pol2, Polint& res)
{
for (int i = 0; i < SIZE; i++)res.a[i] = 0;
	//reserving the memory for res
	(pol1.GetPos() > pol2.GetPos())
		?(res.pos = pol1.GetPos())
		:(res.pos = pol2.GetPos());

	INT64 next = 0;
	INT64 current = 0;
	INT64 i;
	for(i = 0; i <= res.pos; i++)
	{
		current = pol1.a[i] + pol2.a[i] + next;
		res.a[i] = current%BASE;
		next = current/BASE;
	}
	if (next)
	{
		++res.pos;
		res.a[res.pos] = next;
	}
}
inline void PolSum(const Polint& pol1, const Polint& pol2, Polint& res)
{
	if (pol1.sign && pol2.sign)
	{
		PolSameSignsSum(pol1,pol2, res);
		res.sign = true; return;
	}
	if (!pol1.sign && !pol2.sign)
	{
		PolSameSignsSum(pol1,pol2, res);
		res.sign = false;return;
	}
	if (pol1 < pol2)
	{
		if (pol1.less_abs(pol2))
		{
			PolSimpleOneWayMinus(pol2, pol1, res);
			res.sign = true; return;
		}
		else
		{
			PolSimpleOneWayMinus(pol1, pol2, res);
			res.sign = false; return;
		}
	}
	else
	{
		if (pol1.less_abs(pol2))
		{
			PolSimpleOneWayMinus(pol2, pol1, res);
			res.sign = false; return;
		}
		else
		{
			PolSimpleOneWayMinus(pol1, pol2, res);
			res.sign = true; return;
		}
	}
}
//////////////////////////////////////////////////////////////////////////
inline void PolSimpleOneWayMinus(const Polint& pol1, const Polint& pol2, Polint& res)
{
for (int i = 0; i < SIZE; i++)res.a[i] = 0;
	//we are assumed that pol2 is less than pol1
	//and we forgot about the signs
	INT64 next = 0;
	INT64 current = 0;
	int i;
	for (i = 0; i <= int(pol1.pos); i++)
	{
		current = pol1.a[i] - pol2.a[i] - next;
		if(current >= 0)
		{
			res.a[i] = current; //a[i] = current%10000;
			next = 0;//next = current/10000;
		}
		else
		{
			res.a[i] = BASE + current;//current%10000;
			next = 1;
		}
	}
	i = pol1.pos + 2;
	while(res.a[i] == 0)i--;
	if (i >= 0)res.pos = i;
	else res.pos = 0;
}
inline void PolMinus(const Polint& pol1, const Polint& pol2, Polint& res)
{
	if (pol1.sign && pol2.sign)
	{
		if (pol2 < pol1)
		{
			PolSimpleOneWayMinus(pol1, pol2, res);
			res.sign = true; return;
		}
		else
		{
			PolSimpleOneWayMinus(pol2, pol1, res);
			res.sign = false; return;
		}
	}
	if (!pol1.sign && !pol2.sign)
	{
		if (pol1 < pol2)
		{
			PolSimpleOneWayMinus(pol1, pol2, res);
			res.sign = false; return;
		}
		else
		{
			PolSimpleOneWayMinus(pol2, pol1, res);
			res.sign = true; return;
		}
	}
	//different signs
	if (pol1 < pol2)
	{
		PolSameSignsSum(pol1, pol2, res);
		res.sign = false; return;
	}
	else
	{
		PolSameSignsSum(pol2, pol1, res);
		res.sign = true; return;
	}
	return;
}
//Q = A/B , R = A%B
inline void PolSimpleDiv(const Polint &pol1, const INT64 B, Polint &res, INT64 &R)
{
	INT64 r = 0;
	INT64 i, temp;
	for (i = pol1.pos; i >= 0; i--)
	{
		temp = r*BASE + pol1.a[i];
		res.a[i] = temp / B;
		r = temp - res.a[i]*B;
	}
	R = r;

	i = pol1.pos + 1;
	while ( (i>0) && (res.a[i]==0) ) i--;
	res.pos = UINT(i+1);
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
int main()
{

	//a[i]= a[i-1]*a[i-1] - a[i-1] + Polint(1);

	int n;
	scanf("%d", &n);
	Polint a(2);
	Polint b;
	Polint c;
	Polint zero;

	for (int i = 1; i <= n; i++)
	{
		a.print();
		printf("\n");
		a = a*a - a + Polint(1);
	}
	return 0;
	
}
