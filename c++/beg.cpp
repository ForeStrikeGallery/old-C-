#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

class Cstring {
	string s;
	int size;
public:
	Cstring() {
		size = s.size();
	}

	bool contains(string s2);
	int* split();

};

bool Cstring :: contains(string s2) {
	int size2 = s2.size();
	for (int i=0; i<size; i++) {
		int j = 0;
		int trav = i;
		if (s[i] == s2[j]) {
			trav++;
			j++;
			if (j == size2 - 1) 
				return true;
		} else {
			j = 0;
		}
	}
	return false;
}



void processCommand(string command) {
	cout << "..." << endl;

	if (command == "mkdir") {
		cout << "mkdir initiated..." << endl;
	}
}

int main() {

	while(1) {
		cout << '>' ;
		string command;
		cin >> command;
		processCommand(command);
	}
}