#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

/*

You are given a list of n-1 integers and these integers are in 
the range of 1 to n. There are no duplicates in list. One of the 
integers is missing in the list. Write an efficient code to find 
the missing integer.

Isn't that very easy? Sum - N*(N + 1)/2

*/


int main() {
	int arr[] = {1,3,4,6,5};
	int N = sizeof(arr)/sizeof(arr[0]);

	int real_sum = (N + 1)*(N + 2)/2;
	int sum = 0;
	for (int i=0;i<N;i++) 
		sum += arr[i];

	cout << real_sum - sum;

	return 0;
}