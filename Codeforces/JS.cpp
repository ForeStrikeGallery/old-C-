#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	char arr[n][5];
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			cin>>arr[i][j];
		}

		if(arr[i][0] == 'O' && arr[i][1] == 'O'){
			cout<<"YES";
			return 0;
		} else if(arr[i][3] == 'O' && arr[i][4] == 'O'){
			cout<<"YES";
			return 0;
		}
	}

	cout<<"NO";
	return 0;
}