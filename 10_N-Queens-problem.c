#include<stdio.h>

bool isSafe(int row, int col, vector<string> board, int n){
	//check upper diagonal
	int duprow = row;
	int dupcol = col;
	
	while(row>=0 && col>=0 ){
		if(board[row][col] == 'Q')
			return false;
		row--;
		col--;
	}
	
	row = duprow;
	col = dupcol;
	
	while(col>=0 ){
		if(board[row][col] == 'Q')
			return false;
		col--;
	}
	
	row = duprow;
	col = dupcol;
	
	while(row<n && col>=0){
		if(board[row][col] == 'Q')
			return false;
		row++;
		col--;
	}
	
	return true;
}
		
void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
	if(col==n){
		ans.push_back(board);
		return;
	}
	
	for(int row=0;row<n;row++){
		if(isSafe(row,col,board,n)){
			board[row][col] = 'Q';
			solve(col+1,board,ans,n);
			board[row][col] = '.';
		}
	}
}

int **solveNQueens(int n){
	vector<vector<string>> ans;
	vector<string> board(n);
	string s(n,'.');
	
	for(int i=0;i<n;i++){
		board[i]=s;
	}
	
	solve(0,board,ans,n);
	
	return ans;
}

int main(){
	int n;
	cout<<"Enter the no of queens: ";
	cin>>n;
	
	for(auto it1: s1.solveNQueens(n)){
		for(auto it2: it1){
			cout<<it2<<endl;
		}
		cout<<endl;
	}
	
	return 0;
}


















