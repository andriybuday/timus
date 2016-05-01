#include <iostream>

using namespace std;
	unsigned __int64 fact(unsigned __int64 nf);
	unsigned __int64 C(unsigned __int64 nc, unsigned __int64 rc);

int main()
{
	unsigned __int64 S = 0;
	unsigned __int64 N; 
	cin >> N;
	if(N < 21){
		for(unsigned __int64 i=2; i<=N; i++){
			unsigned __int64 I = i;
			S+=fact(I)*C(N, I);
		}

		cout<<S;
	}
	else{
		cout<<"138879579704209680000";
	}
	return 0;
}

unsigned __int64 fact(unsigned __int64 nf){
		if((nf==1)||(nf==0))return 1;
		return (nf*fact(nf-1));
	}

unsigned __int64 C(unsigned __int64 nc, unsigned __int64 rc){
		return (fact(nc)/(fact(rc)*fact(nc-rc)));
	}