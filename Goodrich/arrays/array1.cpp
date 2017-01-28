#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

/*
	Write a C program that, given an array A[] of n numbers and another number x, 
	determines whether or not there exist two elements in S whose sum is exactly x.

	a = [2, 4, 6, 5]

	x = 6

	Naive approach, use two loops.
	for i in a:
		for j = i + 1 in a:
			if a[i] + a[j] == x:
				return True

	return False

	Complexity is O(N^2)

	I can bring it down to O(logN*N) If I use sorting and Binary search, oh wait, can I ?
	Sorting takes up O(N^2)[worst case], but it is usually a lot better, definitely less than logN*N ?

	insertion_sort(a)

	for i in a:
		
		x_complement = x - a[i]
		if binary_search(x_complement) == True:
			return True

	Yet another way would be put i,j at opposite ends and make them converge till sums of
	(a[i],a[j])	pair is x, if i >= j ( actually i == j), loop ends	



*/

//utility print function

void print(int *arr, int N) {
	for(int i=0; i<N; i++) {
		cout << arr[i]<< ' ';
	}
}

bool naiveValExists(int *arr, int N, int X) {

	for(int i=0; i<N-1; i++) {
		for(int j=i+1; j<N; j++) {
			if(arr[i] + arr[j] == X) {
				cout << i <<" " <<j<<endl;
				return true;
			}	
		}
	}

	return false;
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

bool naiveValExists2(int *arr, int N, int X) {

	insertion_sort(arr, N);
	
	for (int i=0; i<N; i++) {
			int X_compliment = X - arr[i];
			if (binary_search(arr, 0, N-1, X_compliment) != -1)
				return true;

	}
	return false;

}

bool valExists(int *arr, int N, int X) {
	int i=0, j=N-1;
	insertion_sort(arr, N);
	while(i < j) {
		if(arr[i] + arr[j] == X)
			return true;
		else if (arr[i] + arr[j] < X)
			i = i + 1;
		else 
			j = j - 1;
	}
	return false;
}



int main() {

	srand(time(0));

	const int N = 100000;
	
	int arr[N];
	
	for(int i=0; i<N; i++)
		arr[i] = rand()%100000;

	int size = sizeof(arr)/sizeof(arr[0]);

	//print(arr, size);

	int X = 67;

	cout << "Part 1 started" << endl;
	if (naiveValExists(arr, size, X))
		cout << "Yes, it exists" << endl;

	cout << "Part 2 started" << endl;
	if (naiveValExists2(arr, size, X)) {
		cout << "Yes!\n";
	}

	if (valExists(arr, size, X)) {
		cout << "Yes, exists \n";
	}


	return 0;
}