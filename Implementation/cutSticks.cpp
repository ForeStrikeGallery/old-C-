#include<iostream>
#include<climits>
using namespace std;

int main(){
	int smallest = INT_MAX;
	int N;
	cin>>N;
	int stickLength[N];

	for(int i=0;i<N;i++){
		cin>>stickLength[i];
	}

	int count ;	
	cout<<N<<endl;
	while(true){
		count = 0;
		smallest = INT_MAX;

		for(int i=0;i<N;i++){
			if(stickLength[i]<smallest && stickLength[i]>0)
				smallest = stickLength[i];
		}

		for(int i=0;i<N;i++){
			stickLength[i] -= smallest;
			if(stickLength[i] > 0)
				count++;
		}
		if(count == 0)
			break;
		
		cout<<count<<endl;

	}
return 0;

}
