#include<iostream>
#include<cstdlib>

using namespace std;

int max(int a, int b) {
	return a>b?a:b;
}

int min(int a, int b) {
	return a<b?a:b;
}


void insertion_sort(int *arr, int N) {
	for (int i=1; i<N; i++) {
		int j = i-1;
		int key = arr[i];

		while (j >= 0 && arr[j] > key) {
			arr[ j + 1] = arr[j]
			j--;
		}
		arr[j + 1] = key;
	}
}



void insertionCount(int *arr, int N, int K) {
	
	insertion_sort(arr, N);
	int min, max;
	min = arr[0];
	max = arr[N-1];

	if (k > max - min) {
		for (int i=0; i<N; i++) {
			arr[i] += k;
		}
		return
	}

	int new_max = max(arr[0], arr[N-1]);
	int new_min = min(arr[0], arr[N-1]);

	for(int i=1; i<N-1; i++) {
		
		if (arr[i] < new_min) {
			arr[i] = arr[i] + k;
 		} else if (arr[i] > new_max){
 			arr[i] -= k;
 		} else if (dist(arr[i], new_min) > dist(arr[i], new_max) {
 			arr[i] -= k;
 		} else {
 			arr[i] += k;
 		}
 	}
}		


int main() {

	int arr = {1, 4,3,5 ,6};
	int N = sizeof(arr)/sizeof(arr[0]);


}