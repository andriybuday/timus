#include <iostream>

using namespace std;

int main()
{
//initialization of array!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	int arr[100007];
	arr[0]=0;
	arr[1]=1;
	for(int j=2; j<=100000; j++){
		if(j%2){arr[j]= arr[j/2] + arr[j/2+1];}
		else
			arr[j] = arr[j/2];
	}
////end of initilitrghtyjgjkrtgjhdrteh
////////////////////////////////////////////////////	
	int N;
	cin>>N;
	//int arr2[13];
	//int count=0;
	while(N){
		//find max
		int max = 0;
		for(int k=0; k<=N; k++)
		{
			if(arr[k]>=max)max=arr[k];
		}
		//arr2[count]=max;
		cout<<max<<endl;
		cin>>N;
		//count++;
	}
	//for(int y=0; y<count; y++){
	//	cout<<arr[2];
	//}

	return 0;
}

