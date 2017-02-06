#include<iostream>
#include<string>
using namespace std;

struct node {
	int data;
	struct node* next;
};

class Stack {
	struct node* top;
	

public:
	Stack();
	void push(int c);
	int pop();
	int peek();

};

Stack :: Stack() {
	top = NULL;
}

void Stack :: push(int c) {
	struct node* new_node = new node();
	
	new_node->data = c;
	new_node->next = NULL;

	if (top == NULL) {
		top = new_node;
	} else {
		new_node->next = top;
		top = new_node;
	}
}

int Stack :: peek() {
	if (top == NULL)
		return -1;

	return top->data;
}

int Stack :: pop() {

	node* temp = new node();
	if (top == NULL)
		return -1;
	else {
		temp = top;
		top = temp->next;
	}

	return temp->data;
}

int* nge(int *arr, int N) {
	
	Stack s1, s2;
	int *nge_arr = new int[N];
	nge_arr[N-1] = -1;
	s1.push(arr[N-1]);

	for (int i=N-2; i>=0; i++) {

		int key = arr[i];
		while (s1.peek() || s1.peek() < key) {
			s2.push(s1.pop());

		} 

		if (s1.peek() == -1) {
			nge_arr[i] = -1;
		} else {
			nge_arr[i] = s1.peek();
		}

		while (s2.peek() == -1) {
			s1.push(s2.pop());
		}

		s1.push(arr[i]);
	}

	return nge_arr;
}

void print_arr(int *arr, int N) 
{
	for (int i =0; i<N; i++) {
		cout << arr[i] << " ";
	}
}



 
int main() {
	
	int T, N;
	cin >> T;
	while(T--) {
		cin >> N;
		int arr[N];
		for (int i=0 ;i<N; i++)
			cin >> arr[i];
		print_arr(arr, N);
		print_arr(nge(arr, N), N);
	}

	return 0;
}