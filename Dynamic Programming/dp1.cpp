#include<iostream>
#include<climits>
using namespace std;

int maxima(int a, int b){return a>=b?a:b;}

int findLongestSub(int *S,int i,int max){
			
	if(i == sizeof(S)/sizeof(S[0]))
		return 0;

	if(S[i]<=max)
		return findLongestSub(S,i+1,max);
	else{
		
		return maxima(1+findLongestSub(S,i+1,S[i]),findLongestSub(S,i+1,max));
	}

}
int main()
{
	
	int N;
	cin>>N;
	int  S[N];
	for(int i=0;i<N;i++) cin>>S[i];
	int max = INT_MIN;
	int a = findLongestSub(S,0,max);
	cout<<a;
}
