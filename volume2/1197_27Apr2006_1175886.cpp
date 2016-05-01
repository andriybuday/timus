//1197
#include <iostream>
using namespace std;
int board[12][12];
int fir, sec;
char ch;

int main(){
	int n;
	int i, j;
	for(i = 2; i<10; i++){
		for(j = 2; j<10; j++)board[i][j] = 1;
	}
/*	
	for(i = 0; i<12; i++){
		for(j = 0; j<12; j++)printf("%d", board[i][j]);
		printf("\n");
	}
*/	
	cin>>n;
	
	for(int ii = 0; ii<n; ii++)
	{
		cin>>ch>>sec;
		
		fir = int(ch) - 95;
		sec += 1;
		//cout<<sec<<' '<<fir<<endl;
		
		int res = 0;
		
		res += board[fir-2][sec-1];
		res += board[fir-1][sec-2];
		res += board[fir+2][sec+1];
		res += board[fir+1][sec+2];
		res += board[fir-2][sec+1];
		res += board[fir-1][sec+2];
		res += board[fir+2][sec-1];
		res += board[fir+1][sec-2];
	
		cout<<res<<endl;
		//printf()
	}

	return 0;
}