#include<iostream>
#include<string>
#include<stack>
using namespace std;

typedef stack<int> intStack;


void push_bot(stack<int> &s, int a) {
	cout << "push bot" << a;
	stack<int> temp;
	while(!s.empty()) {

		temp.push(s.top());
		s.pop();

	}
	s.push(a);

	while(!temp.empty()){
		s.push(temp.top());
		temp.pop();
	}
}

void reverse(stack<int> &s) {

		int a = s.top();
		s.pop();
		cout << a << " " << endl;

		if (s.empty()){
			s.push(a);
			return;
		}
		
		
		
		reverse(s);
		
		push_bot(s, a);

}

int main() {

	stack<int> s;
	s.push(2);
	s.push(4);
	s.push(5);
	s.push(1);

	reverse(s);
	
	cout << s.top();
	return 0;
}