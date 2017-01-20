#include<iostream>
#include<climits>
using namespace std;

int longestSub(int *arr, int N){
	int t[N];
	for(int i=0;i<N;i++){t[i] = 1;}

	for(int i = 1;i<N;i++)
		for(int j = 0; j<i ;j++)
			if(arr[j]<arr[i] && t[i]<t[j]+1)
				t[i] = 1+t[j];
				

	int max = INT_MIN;
	for(int i=0;i<N;i++){
		cout<<t[i]<<" ";
		if(t[i]>max)
			max = t[i];
	}

	return max;
}

int main(){
	int N;
	cin>>N;
	int arr[N];
	for(int i=0;i<N;i++){cin>>arr[i];}
	cout<<longestSub(arr,N);

return 0;
}
