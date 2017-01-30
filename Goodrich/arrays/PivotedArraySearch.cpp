#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

/*

	An element in a sorted array can be found in O(log n) time via binary search. But suppose we 
	rotate an ascending order sorted array at some pivot unknown to you beforehand. So for instance, 1 2 3 4 5
	might become 3 4 5 1 2. Devise a way to find an element in the rotated array in O(log n) time.

	Naive appraoch is to rotate till it's in the proper position and then BSearch

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


void rotateArray(int *arr, int N, int K) {
	while(K--) {
		start_elem = arr[0];
		for (int i=0; i<N-1; i++) {
			arr[i] = arr[i+1];
		}
		arr[N-1] = start_elem;
	}
}

int findPivotElement(int *arr, int low, int high) {
	int mid = (low + high)/2;
	if (arr[low] < arr[high])
		return -1;

	if (arr[mid] < arr[high]) {
		high = mid;
	}
}

int main() {

	srand(time(0));

	const int N = 100000;
	
	int arr[N];
	
	for(int i=0; i<N; i++)
		arr[i] = rand()%100000;

	int size = sizeof(arr)/sizeof(arr[0]);

	

	return 0;
}