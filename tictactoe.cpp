#include <bits/stdc++.h>
using namespace std;
int turn = 0;
void printBoard(vector<vector<int>>&arr){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(j!=0)cout<<" | ";
			if(arr[i][j]==10) cout<<'X';
			else if(arr[i][j]==-10) cout<<'O';
			else
			cout<<arr[i][j];
		}
		cout<<endl;
		if(i==2) continue;
		for(int j=0;j<9;j++){
			cout<<"_";
		}
		cout<<endl;
	}
}
//checks if the outcome is player 1 or player 2 or a draw
int outcome(vector<vector<int>>&arr){
	int s = 0;
	//checks if horizontally any rows are checked
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			s = s+arr[i][j];
		}
		if(s==30) return 1;
		if(s==-30) return 2;
		s = 0;
	}
	//checks if vertically any columns are checked
	for(int j=0;j<3;j++){
		for(int i=0;i<3;i++){
			s = s + arr[i][j];
		}
		if(s==30) return 1;
		if(s==-30) return 2;
		s = 0;
	}
	//checks if main diagonal is checked
	for(int i=0;i<3;i++){
		s = s+arr[i][i];
	}
	if(s==30) return 1;
	if(s==-30) return 2;
	s = 0;
	//checks if adj diagonal is checked
	for(int i=0;i<3;i++){
		s = s + arr[i][2-i];
	}
	if(s==30) return 1;
	if(s==-30) return 2;
	return 0;
}
void makemove(vector<vector<int>>&arr){
	if(turn>=9){
		cout<<"Its a draw"<<endl;
		return;
	}
	printBoard(arr);
	cout<<"Player "<<(turn%2+1)<<endl;
	cout<<"Choose a cell which is unoccupied"<<endl;
	
	int cell;
	cin>>cell;
	cell--;
	int i=(cell/3);
	int j = cell%3;
	if(arr[i][j] == 10 or arr[i][j] == -10){
		cout<<"The cell is already taken \nSelect from the ones available: "<<endl;
		makemove(arr);
		return;
	}
	turn++;
	arr[i][j] = (turn%2)?10:-10;
	int o = outcome(arr);
	if(o==0) {
		makemove(arr);
		return;
	}
	cout<<"The winner is "<<o<<endl;
}

int main(){
	vector<vector<int>>arr(3,vector<int>(3,0));
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			arr[i][j] = i*3+j+1;
		}
	}
	//for(int i=0;i<9;i++)
	makemove(arr);
	printBoard(arr);
}