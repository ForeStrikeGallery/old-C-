#include<iostream>
#include<stack>

using namespace std;

/*
size(): Return the number of elements in the stack.
empty(): Return true if the stack is empty and false otherwise.
push(e): Push e onto the top of the stack.
pop(): Pop the element at the top of the stack.
top(): Return a reference to the element at the top of the stack.

*/


int main() {
	stack<int> myStack;
	myStack.push(3);
	myStack.push(4);
	myStack.push(5);

	cout << myStack.top();

	return 0;
}