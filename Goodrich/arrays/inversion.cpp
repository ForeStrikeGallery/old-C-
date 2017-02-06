
/*


Count Inversions in an array | Set 1 (Using Merge Sort)

Inversion Count for an array indicates – how far (or close) the array is from 
being sorted. If array is already sorted then inversion count is 0. If array is
sorted in reverse order that inversion count is the maximum.
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j 

This has a greedy solution.
At each point take the nearest possible combination you have


 */

#include<iostream>
#include<cstdlib>

using namespace std;


int naiveInversionCount(int *arr, int N) {
	int count = 0;
	for(int i=0; i<N-1; i++) {
		for(int j=i; j<N; j++) {
			if (arr[j] < arr[i])
				count++;
		}
	}
	return count;
}



int main() {
	
	int arr1[] = {2,4,1,3,5};



	int N = sizeof(arr1)/sizeof(arr1[0]);

	cout << naiveInversionCount(arr1, N);
	
	return 0;
}