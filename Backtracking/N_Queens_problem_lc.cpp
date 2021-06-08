The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.
//strt filling row by row one queen at a row at a time for all the positions of the columns.



class Solution {
public:
    void solve(int n,vector<string> &v,vector<vector<string>> &ans,int row){
        //BC
        if(row==n){
            ans.push_back(v);
            return ;
        }
        
        for(int col=0;col<n;col++){
            if(isValid(n,row,col,v)){
                v[row][col]='Q';
                solve(n,v,ans,row+1);
                v[row][col]='.';
            }
        }
        
    }
    
    bool isValid(int n,int row,int col,vector<string> &v){
        //check for col
        for(int i=0;i<row;i++){
            if(v[i][col]=='Q') return false;
        }
        // check for left diagonal
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(v[i][j]=='Q') return false;
        }
        // check for right diagonal
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(v[i][j]=='Q') return false;
        }
        return true;
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v(n,string(n,'.'));
        solve(n,v,ans,0); // 0 denotes the row no.
        return ans;
    }
};