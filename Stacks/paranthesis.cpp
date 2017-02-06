#include<iostream>
#include<string>
using namespace std;

struct node {
	char data;
	struct node* next;
};

class Stack {
	struct node* top;
	

public:
	Stack();
	void push(char c);
	char pop();
	char peek();

};

Stack :: Stack() {
	top = NULL;
}

void Stack :: push(char c) {
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

char Stack :: peek() {
	if (top == NULL)
		return -1;

	return top->data;
}

char Stack :: pop() {

	node* temp = new node();
	if (top == NULL)
		return -1;
	else {
		temp = top;
		top = temp->next;
	}

	return temp->data;
}

char reverse(char c) {
	switch(c) {
		case '{':
			return '}';
		case '[':
			return ']';
		case '(' :
			return ')';
		default:
			return -1;			
	}
	return -1;
}

bool isCorrect(string arr, int N) {
	Stack s;
	s.push(arr[0]);
	for (int i=1; i<N; i++) {
		if (arr[i] == reverse(s.peek())) {
			//cout << "popping... " << s.pop() << endl;
			s.pop();
		} else {
			//cout << "pushing... " << arr[i] << endl;
			s.push(arr[i]);
		}
	}

	if (s.peek() == -1)
		return true;
	else 
		return false;
}

int main() {
	string arr;
	int T;
	cin >> T;
	while(T--) {
		cin >> arr;
		int size = arr.size();
		//cout << size << endl;
		if (isCorrect(arr, size)) {
			cout << "balanced" << endl;
		} else {
			cout << "not balanced" << endl;
		}
	}

	return 0;
}