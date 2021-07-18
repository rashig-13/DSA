Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.


class Solution {
public:
    void dfs(vector<vector<char>>& grid,int r,int c){
        int n=grid.size();
        int m=grid[0].size();
        grid[r][c]='0';
        if(r+1<n && grid[r+1][c]=='1') dfs(grid,r+1,c);
        if(r-1>=0 && grid[r-1][c]=='1') dfs(grid,r-1,c);
        if(c-1>=0 && grid[r][c-1]=='1') dfs(grid,r,c-1);
        if(c+1<m && grid[r][c+1]=='1') dfs(grid,r,c+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        if(n==0) return 0;
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};