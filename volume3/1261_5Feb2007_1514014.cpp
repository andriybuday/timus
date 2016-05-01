//1261
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#define uint64 unsigned __int64
struct NNSC  {
	short P;		//system of calculation
	unsigned __int64 Num;	//number
//---------------------------------------
	NNSC():P(0), Num(0){};	
//----------------------------------------
	NNSC(short p)
	{
		while((p<2)||(p>10))
		{
			cout<<"You entered bad system of calculation!!!\n";
			cout<<"Try again..."; 
			cin>>p;
		}
		P = p;
		Num = 0;
	}
//----------------------------------------
	NNSC(short p, unsigned __int64 n)
	{
		while((p<2)||(p>10))
		{
			cout<<"You entered bad system of calculation!!!\n";
			cout<<"Try again..."; 
			cin>>p;
		}
		P = p;
		Num = n; 
	}
//----------------------------------------
	NNSC(const NNSC& n2):P(n2.P),Num(n2.Num){}
//----------------------------------------
	friend std::ostream& operator <<(std::ostream& out,const NNSC& ob)
	{
		out /*<<ob.P<<" " */<<ob.Num;// <<endl;
		return out;
	}
//-----------------------------------------
	friend std::istream& operator >>(std::istream& in, const NNSC& ob)
	{
		in>>ob.P>>ob.Num;
		return in;
	}
//-----------------------------------------
	NNSC operator +(const NNSC& ob)
	{
		NNSC temp, temp1, temp2;
		temp1 = *this;
		temp2 = ob;
		if(temp1.P == temp2.P)
		{
			temp.P = temp1.P;
			temp1.p_to_dec(temp1);
			temp2.p_to_dec(temp2);
		
			temp.Num = temp1.Num + temp2.Num;
			temp.dec_to_p(temp);
		}else cout<<"Error: different systems of members!!!\n";
		return temp;
	}
//------------------------------------
	NNSC operator +=(const NNSC& ob)
	{
		NNSC temp, temp1;
		temp = *this;
		temp1 = ob;
		if(temp.P == temp1.P)
		{
			unsigned __int64 z = temp.P;
			temp.p_to_dec(temp);
			temp1.p_to_dec(temp1);
		
			temp.Num += temp1.Num;
			temp.dec_to_p(temp, z);
		}else cout<<"Error: different systems of members!!!\n";
		return temp;
	}
//------------------------------------
	NNSC operator -=(const NNSC& ob)
	{
		NNSC temp, temp1;
		temp = *this;
		temp1 = ob;
		if(temp.P == temp1.P)
		{
			unsigned __int64 z = temp.P;
			temp.p_to_dec(temp);
			temp1.p_to_dec(temp1);
		
			temp.Num -= temp1.Num;
			temp.dec_to_p(temp, z);
		}else cout<<"Error: different systems of members!!!\n";
		return temp;
	}
//-----------------------------------
	NNSC operator *(const NNSC& ob)
	{
		NNSC temp, temp1, temp2;
		temp1 = *this;
		temp2 = ob;
		if(temp1.P == temp2.P)
		{
			temp.P = temp1.P;
			temp1.p_to_dec(temp1);
			temp2.p_to_dec(temp2);
		
			temp.Num = temp1.Num * temp2.Num;
			temp.dec_to_p(temp);
		}else cout<<"Error: different systems of members!!!\n";
		return temp;
	}
//-------------------------------------
	NNSC operator *=(const NNSC& ob)
	{
		NNSC temp, temp1;
		temp = *this;
		temp1 = ob;
		if(temp.P == temp1.P)
		{
			unsigned __int64 z = temp.P;
			temp.p_to_dec(temp);
			temp1.p_to_dec(temp1);
		
			temp.Num *= temp1.Num;
			temp.dec_to_p(temp, z);
		}else cout<<"Error: different systems of members!!!\n";
		return temp;
	}

//------------------------------------
	NNSC operator -(const NNSC& ob)
	{
		NNSC temp, temp1, temp2;
		temp1 = *this;
		temp2 = ob;
		if(temp1.P == temp2.P)
		{
			temp.P = temp1.P;
			temp1.p_to_dec(temp1);
			temp2.p_to_dec(temp2);
		
			temp.Num = temp1.Num - temp2.Num;
			temp.dec_to_p(temp);
		}else cout<<"Error: different systems of members!!!\n";
		return temp;
	}
//-------------------------------------
	NNSC operator =(const NNSC& ob)
	{
		this->P = ob.P;
		this->Num = ob.Num;
		return *this;
	}
//--------------------------------------
	NNSC operator ++()
	{
		this->p_to_dec(*this);
		this->Num++;
		this->dec_to_p(*this);	
		return *this;
	}

//--------------------------------------
	NNSC operator --()
	{
		this->p_to_dec(*this);
		this->Num--;
		this->dec_to_p(*this);	
		return *this;
	}
//---------------------------------------
	NNSC p_to_p(const NNSC& ob2)
	{
		NNSC temp;
		temp.p_to_dec(ob2);
		return this->dec_to_p(temp);

	}
//---------------------------------------
	NNSC p_to_dec(const NNSC& ob2)
	{
		unsigned __int64 chast = ob2.Num;
		unsigned __int64 s=0;
		short k=0;
		while(chast)
		{
			s+=(chast%10)*pow(double(ob2.P), double(k));
			chast /= 10;
			k++;
		}
		P = 10;
		Num = s;
		return *this;
	}
//----------------------------------------
	NNSC operator ==(const NNSC& ob)
	{
		if (this->P == ob.P)
		{
			if(this->Num == ob.Num)return true;
		}
	else return false;
	}
//----------------------------------------
	NNSC operator <=(const NNSC& ob)
	{
		if (this->P == ob.P)
		{
			if(this->Num <= ob.Num)return true;
		}
	else return false;
	}
//----------------------------------------
	NNSC operator <(const NNSC& ob)
	{
		if (this->P == ob.P)
		{
			if(this->Num < ob.Num)return true;
		}
	else return false;
	}

//----------------------------------------
	NNSC operator >=(const NNSC& ob)
	{
		if (this->P == ob.P)
		{
			if(this->Num >= ob.Num)return true;
		}
	else return false;
	}

//----------------------------------------
	NNSC operator >(const NNSC& ob)
	{
		if (this->P == ob.P)
		{
			if(this->Num > ob.Num)return true;
		}
	else return false;
	}


//----------------------------------------
	NNSC dec_to_p(const NNSC& ob2)
	{
		unsigned __int64 s = ob2.Num;
		Num = 0;
		short ost, k=0;
		while(s)
		{
			ost = s%P;
			s /= P;
			Num += ost*pow(10.0, double(k));
			k++;
		}
		return *this;
	}
//----------------------------------------
	NNSC dec_to_p(const NNSC& ob2, short nn)
	{
		this->P = nn;
		unsigned __int64 s = ob2.Num;
		Num = 0;
		short ost, k=0;
		while(s)
		{
			ost = s%P;
			s /= P;
			Num += ost*pow(10.0, double(k));
			k++;
		}
		return *this;
	}
//-----------------------------------------
	virtual ~NNSC(){}

};

int main()
{
	//ofstream ofs ("1261_based_3.txt");
	int N;
	scanf("%d" , &N);
	/*
	for(int i = 0; i <= 100; i++)
	{
		NNSC temp(10, i);
		NNSC ret;
		ret.dec_to_p(temp, 3);
		ofs << i << "\t" << ret;
	}
	*/
	NNSC a(10, N), n_in_3;
	n_in_3.dec_to_p(a,3);// n is in 3 based system

	uint64 n = n_in_3.Num;
	uint64 pay = 0;
	uint64 differ = 0;

	uint64 multipl = 1;
	uint64 adder = 0;
	bool is_oneds = 1;
	while (n)
	{
		uint64 last_digit = n%10;
		if(last_digit == 0)
		{
			is_oneds = 0;
			if(adder)
			{
				pay += multipl;
				//differ += multipl;
				adder = 0;
			}
		}
		if(last_digit == 1)
		{
			if(adder)
			{
				differ += multipl;
				adder = 1;
			}
			else
			{
				pay += multipl;
				adder = 0;
			}
		}
		if(last_digit == 2)
		{
			is_oneds = 0;
			if(adder)
			{
				adder = 1;
			}
			else
			{
				differ += multipl;
				adder = 1;
			}
		
		}
		multipl *= 10;
		n /= 10;
	}

	if(adder)pay += multipl;
	if(is_oneds || differ == 0)
	{
		pay += multipl;
		differ += multipl;
	}

	NNSC NSpay(3,pay) , NSdiffer(3,differ);
	//cout << NSpay << " " << NSdiffer;
	NNSC NSpay2, NSdiffer2;
	NSpay2.p_to_dec(NSpay);
	NSdiffer2.p_to_dec(NSdiffer);

	
	cout << NSpay2 << " " << NSdiffer2 << endl;
}