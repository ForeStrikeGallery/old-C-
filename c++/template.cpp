#include<iostream>
#include<vector>
#include<stack>

using namespace std;



int main() {
	stack<int> s;
	s.push(2);
	s.push(4);
	s.pop();
	cout << s.top();
	return 0;
}