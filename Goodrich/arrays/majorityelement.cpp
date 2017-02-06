#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

const int max_num = 1000000;
/*
	
	Majority Element: A majority element in an array A[] of size n is an element that 
	appears more than n/2 times (and hence there is at most one such element).
	Write a function which takes an array and emits the majority element (if it exists), 
	otherwise prints NONE as follows:


	Naive Approach
	for hashtable, check if any of it is > N/2
	that's not really too bad
	O(N) time
	I didn't like that approach all that much, let's see if there is an alternative.

	sort(A);
	i = 0
	j = i + N/2
	if arr[i] == arr[j]
		return i
	else
		i++ till arr[i-1] != arr[i]	



*/

//utility print function

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

int majorityElement(int *arr, int N) {
	int brr[max_num];
	for (int i=0; i<N; i++) {
		brr[arr[i]]++;
	}

	for(int i=0; i<max_num; i++) {
		if (brr[i] > N/2) {
			print(brr, max_num);
			return i;
		}
	}

	return -1;
}

int majorityElement2(int *arr, int N) {
	insertion_sort(arr, N);
	int i=0, j;
	int prev = -1;
	for(int i=0; i<N/2; i++) {
		int j = i + N/2;
		if(prev != arr[i]) {
			if (arr[i] == arr[j]) {
				return i;
			}
		} else {
			prev = arr[i];
		}
	} 

	return -1;
}



int main() {

	srand(time(0));
	const int N = 10000;
	int arr[N];
	
	for(int i=0; i<N; i++)
		arr[i] = rand()%100000;

	int ap[] = {2, 2, 2, 3};

	int size = sizeof(ap)/sizeof(ap[0]);

	int i =  majorityElement2(ap, size) ;
	if ( i != -1) {
		cout << "Found it "<< ap[i] ;
	} else {
		cout << "Better luck next time";
	}

	
	return 0;
}s