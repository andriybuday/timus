//1403_SB
#include <iostream>
#include <queue>
using namespace std;
int arr[1007];

struct visky
{
	int ds;//days
	int pr;//price
	int num;//number
	visky():ds(0), pr(0), num(0){}
	visky(int d, int p, int n):ds(d), pr(p), num(n){}
	visky(const visky& vs)
	{
		ds = vs.ds;
		pr = vs.pr;
		num = vs.num;
	}
	friend istream& operator >>(istream& is, visky& vs)
	{
		is >> vs.ds;
		is >> vs.pr;
		return is;
	}
	friend ostream& operator <<(ostream& os,const visky& vs)
	{
		os << vs.ds <<" ";
		os << vs.pr;
		return os;
	}

	bool operator < (const visky& vs)const
	{
		if(ds < vs.ds)
		{
			return true;
		}
		if(ds == vs.ds)
		{
			return (pr < vs.pr);
		}
		return false;
	}

};

int main()
{
	int N, i;
	cin >> N;
	priority_queue<visky> qk, empty, qk_new;
	visky temp, zero;
	empty.push(zero);
	for(i = 0; i < N; i++)
	{
		cin >> temp;
		temp.num = i+1;
		qk.push(temp);
	}
	qk_new = empty;

	int counter = qk.top().ds;
	int k = 0, j;

	for(i = 0; i < N; i++)
	{
		if(counter >= qk.top().ds)
		{
			counter = qk.top().ds;
		}

//		cout<<"\n"<<qk.top()<<"\n";
		arr[k] = qk.top().num;
		k++;
		qk.pop();
		counter--;
		if(counter == 0)break;
		int seq_end = qk.size();
		for(j = 0; j < seq_end; j++)
		{
			temp = qk.top();
			if(temp.ds > counter)
			{
				//temp = qk.top();
				temp.ds = counter;
				//qk_new.push(temp);
			}
			
			qk.pop();
			qk_new.push(temp);
			
		}
		//qk.erase();
		qk = qk_new;
		qk_new = empty;
		//qk_new.erase();
	}
	cout<<k<<"\n";
	for(j = k-1; j >= 0; j--)
	{
		cout<<arr[j]<<" ";
	}

	return 0;
}
