#include<iostream>
#include<climits>
using namespace std;

int max(int a, int b){ return a>b?a:b;};


int cut_rod(int *price, int *table, int n){
	cout<<"calle"<<n;
	if(n == 0)
		return 0;
	if(table[n] != -1)
		return table[n];
	int q = INT_MIN;
	for(int i=0;i<n;i++)
		q = max(q,price[i]+cut_rod(price,table,n-1-i));
	table[n] = q;
	return q;
	
}

int main()
{
 int N;
 cin>>N;
 int table[N], price[N];
 for(int i=0;i<N;i++) {cin>>price[i];table[i] = -1;} 
 cout<<cut_rod(price,table,N-1);
}

