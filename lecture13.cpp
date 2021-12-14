#include<vector>
#include<iostream>
using namespace std;
bool isSafeForSudoku(vector<vector<int>>&board,int row,int col,int val){
  for(int i=0;i<board[0].size();i++){
    if(board[row][i]==val){
      return false;
    }
  }
  for(int i=0;i<board.size();i++){
    if(board[i][col]==val){
      return false;
    }
  }
  int sRow=(row/3)*3;
  int sCol=(col/3)*3;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(board[i+sRow][j+sCol]==val){
        return false;
      }
    }
  }
  return true;
}
void display(vector<vector<int>>&board){
  for(int i=0;i<board.size();i++){
    for(int j=0;j<board[0].size();j++){
      cout<<board[i][j]<<" ";
    }
    cout<<"\n";
  }
}
void sudoku(vector<vector<int>>&board,int row,int col){
  if(row==board.size()-1&&col==board.size()){
    display(board);
    cout<<"\n";
    return ;
  }
  if(col==board[0].size()){
    row=row+1;
    col=0;
  }
  if(board[row][col]!=0){
    sudoku(board,row,col+1);
  }
  else{
    for(int val=1;val<=9;val++){
      if(isSafeForSudoku(board,row,col,val)){
        board[row][col]=val;
        sudoku(board,row,col+1);
        board[row][col]=0;
      }
    }
  }
}
void sudoku(){
  vector<vector<int>>board={{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}};
    sudoku(board,0,0);
}
bool isSafeForNqueen(vector<vector<int>>&board,int row,int col){
  for(int i=row;i>=0;i--){
    if(board[i][col]==1){
      return false;
    }
  }
  for(int i=row,j=col;i>=0&&j>=0;i--,j--){
    if(board[i][j]==1){
      return false;
    }
  }
  for(int i=row,j=col;i>=0&&j<board[0].size();i--,j++){
    if(board[i][j]==1){
      return false;
    }
  }
  return true;
}
int nqueen(vector<vector<int>>&board,int row){
  if(row==board.size()){
    display(board);
    cout<<"\n";
    return 1;
  }
  int ans=0;
  for(int col=0;col<board[0].size();col++){
    if(isSafeForNqueen(board,row,col)){
      board[row][col]=1;
      ans=ans+nqueen(board,row+1);
      board[row][col]=0;
    }
  }
  return ans;
}
void nqueen(){
  int n=4;
  vector<vector<int>>board(n,vector<int>(n,0));
  cout<<nqueen(board,0)<<"\n";
}
int main(){
  // sudoku();
  nqueen();
  return 0;
}