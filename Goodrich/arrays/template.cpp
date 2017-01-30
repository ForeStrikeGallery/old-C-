#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

/*

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



int main() {

	srand(time(0));

	const int N = 100000;
	
	int arr[N];
	
	for(int i=0; i<N; i++)
		arr[i] = rand()%100000;

	int size = sizeof(arr)/sizeof(arr[0]);

	

	return 0;
}