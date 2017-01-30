

/*Write an efficient C program to find 
the sum of contiguous subarray within a one-dimensional 
array of numbers which has the largest sum.*/


#include<iostream>
#include<cstdlib>
#include<ctime>
#include<climits>
using namespace std;

const int max_num = 1000000;

/*
	This had a lot to do with dp as if my memory serves me right
	there can be negative integers

	So here's one way of doing this.
	Iterate through the array till you find a positive integer.
	label it as start_int, and continue on to find the sum of the
	consecutive elements to the right of it(including start_int). The maximum
	value of the sum while iterating through, will be max_universal_sum. When local_sum 
	becomes negative, drop the start_int and label it to the next positive integer after
	the local sum becomes negative. 

	Good, that worked!

	The complexity is O(n) even though there are two loops, actually I didn't need two loops
	I'll rewrite it.

	Nah, too much pain.

	Oh and Kadane's algorithm is the same one, so that's chill
	

*/

void print(int *arr, int N) {
	for(int i=0; i<N; i++) {
		cout << arr[i]<< ' ';
	}
}



void insertion_sort(int *arr, int N) {
	cout << "insertion_sort started\n";
	int i, j;

	for (i=1; i<N; i++) {
		//cout << i << " \n";
		j = i -1;
		int key = arr[i];
		while (j > 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1] = key;

	}
}

int binary_search(int *arr, int low, int high, int key) {
	cout << "BS started \n";
	while (low < high) {
		int mid = (low + high)/2;
		if (arr[mid] == key) 
			return mid;
		else if (key > arr[mid])
			low = mid + 1;
		else if (key < arr[mid])
			high = mid - 1;
	}
	return -1;
}

int findMaxSubarraySum(int *arr, int N) {
	int max_universal_sum = INT_MIN;

	for(int i=0; i<N-1; i++) {
		if (arr[i] >= 0) {
			int local_sum = 0;
			for (int j = i; j < N; j++) {
				local_sum += arr[j];
				if (max_universal_sum  < local_sum) {
					max_universal_sum = local_sum;
				}
				if (local_sum < 0) {
					i = j;
					break;
				}
			}
		}
	}

	return max_universal_sum;
}


int main() {

	srand(time(0));
	const int N = 10000;
	int arr[N];
	
	for(int i=0; i<N; i++)
		arr[i] = rand()%100000;

	int ap[] = {-2, -3, 4, -1, -2, 1, 5, -3};

	int size = sizeof(ap)/sizeof(ap[0]);

	cout << findMaxSubarraySum(ap, size);


	return 0;
}