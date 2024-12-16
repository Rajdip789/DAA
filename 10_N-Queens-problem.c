/*#include<stdio.h>

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
}*/

#include<stdio.h>
#include<math.h>
 
int board[20], count;
void queen(int row,int n);

int main(){
	int n,i,j;
	 
	printf(" - N Queens Problem Using Backtracking -");
	printf("\nEnter number of Queens:");
	scanf("%d",&n);
	
	queen(1,n);
	return 0;
}
 
//function for printing the solution
void print(int n){
	int i,j;
	printf("\n\nSolution %d:\n\n",++count);
	 
	for(i = 1; i <= n; ++i)
		printf("\t%d",i);
	 
	for(i = 1; i <= n; ++i) {
		printf("\n\n%d",i);
		for(j=1;j<=n;++j) { //for nxn board
	    	if(board[i]==j)
	    		printf("\tQ"); //queen at i,j position
	   		else
	    		printf("\t-"); //empty slot
		}
	}
}
 
/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row, int column) {
	int i;
	for(i = 1; i <= row-1; ++i) {
		//checking column and digonal conflicts
		if(board[i] == column)
			return 0;
	  	else
	   		if(abs(board[i] - column) == abs(i - row))
	    		return 0;
	}
	return 1; //no conflicts
}
 
//function to check for proper positioning of queen
void queen(int row, int n) {
	int column;
	for(column = 1; column <= n; ++column) {
		if(place(row, column)) {
			board[row] = column; //no conflicts so place queen
	   		if(row == n) //dead end
	    		print(n); //printing the board configuration
	   		else //try queen with next position
	    		queen(row+1, n);
	   }
	}
}


















