#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	char d[1000];
	int a;
	char e[3];
	int pw;
	int di = 0;
	bool dotPass = false;
	bool ePass = false;
	int ei = 0;
	
	string S;
	cin>>S;
	
	for(int i=0;i<S.length();i++){
		if(i == 0){
			a = S[i] - '0';
			continue;
		}
		if(S[i] == '.'){
			dotPass = true;
			continue;
		}

		if(S[i] == 'e'){
			ePass = true;
			continue;
		}

		if(dotPass && !ePass){
			d[di++] = S[i];
			continue;
		}

		
		if(ePass == true){
			e[ei++] = S[i];
		}
		
	}
	
	int n = ei;	
	for(int i = 0;i<n;i++){
		pw = pw + (e[i] - '0');
		pw = pw*pow(10,ei-1);
		ei--;	
	}


	if(pw<di){
		for(int i = pw;i<di;i++){
			d[i+1] = d[i];
		}d[pw] = '.';
	}
/*
	else if(pw>di){
		for(int i = di; i<pw ;i++){
			d[i] = '0';
				
		}
	}
*/
	

	if(a != 0)
		cout<<a<<d;
	else
		cout<<d;

 return 0;
}

