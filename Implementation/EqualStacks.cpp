#include<iostream>
#include<climits>
using namespace std;

bool allEqual(int *sum){
	if(sum[0] == sum[1] && sum[1] == sum[2] )
		return true;
	else
		return false;
}

int largest(int *sum){
	int largest = INT_MIN;
	int lari = -1;
	for(int i=0;i<3;i++){
		if(sum[i]>largest){
			largest = sum[i];
			lari = i;
		}
	}
 return lari;
}
int main()
{
 	int number[3];
	int stack[3][100000];
	int sum[3];		
	int top[3];

	for(int i=0;i<3;i++){
		sum[i] = 0;
		top[i] = 0;
	}

	for(int i=0;i<3;i++){
		cin>>number[i];
	}

	for(int i=0;i<3;i++){
		for(int j=0;j<number[i];j++)
			{
				cin>>stack[i][j];
				sum[i] += stack[i][j];
			}
	}

	while(!allEqual(sum)){
		int n = largest(sum);
		sum[n] -= stack[n][top[n]];
		top[n]++;	
	}
	cout<<sum[1];

}

