#include<iostream>
using namespace std;

int main()
{
	int N,M;
	int count = 0;
	string S;
	cin>>N>>M;
	int pos1x,pos1y,pos2x = -1,pos2y = -1;
	char mesh[N][M];
	bool foundFirst = false;
	bool foundSecond = false;
	for(int i=0;i<N;i++){
		cin>>S;
		;
		
		for(int j=0;j<M;j++){
			if(S[j] == '*'){
				if(!foundFirst){
					pos1x = i;
					pos1y = j;
					foundFirst = true;
					
				}
				
				if(foundFirst && !foundSecond){
					if(pos1x != i && pos1y != j){
						pos2x = i;
						pos2y = j;
						foundSecond = true;
					}
				}
				count++;
			}
			mesh[i][j] = S[j];
		}
	}

	int meshOne = 0;
	int meshTwo = 0;

	if(pos2x == -1){
		pos1x += 1;
		pos1y += 1;
		cout<<"YES"<<endl;
		cout<<pos1x<<" "<<pos1y;
		return 0;
	}
	


	for(int i = 0;i<N;i++){
		if(mesh[i][pos1y] == '*')
			meshOne++;

		if(mesh[i][pos2y] == '*')
			meshTwo++;
	}
	

	for(int j =0;j<M;j++){
		if(mesh[pos2x][j] == '*')
			meshOne++;
		if(mesh[pos1x][j] == '*')
			meshTwo++;
	}
	
	pos1x += 1;
	pos1y += 1;
	pos2x += 1;
	pos2y += 1;

	if(meshOne == count+1){
		cout<<"YES"<<endl;
		cout<<pos2x<<" "<<pos1y;
	}
	else if(meshTwo == count+1){
		cout<<"YES"<<endl;
		cout<<pos1x<<" "<<pos2y;
	}
	else
		cout<<"NO";
	return 0;
}
