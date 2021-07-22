Given an m x n matrix grid where each cell is either a wall 'W', an enemy 'E' or empty '0', return the maximum enemies you can kill using one bomb. You can only place the bomb in an empty cell.

The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since it is too strong to be destroyed.

Input: grid = [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
Output: 3

Naive O(N.M(N+M))
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& v) {
        int ans=0,c=0;
        int n=v.size(),m=v[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]=='0'){
                    c=0;
                    int r1=i,r2=i;
                    while(r1>=0 && v[r1][j]!='W'){
                        if(v[r1][j]=='E') c++;
                        r1--;
                    } 
                    while(r2<n && v[r2][j]!='W'){
                        if(v[r2][j]=='E') c++;
                        r2++;
                    } 
                    int c1=j,c2=j;
                    while(c1>=0 && v[i][c1]!='W'){
                        if(v[i][c1]=='E') c++;
                        c1--;
                    } 
                    while(c2<m && v[i][c2]!='W'){
                        if(v[i][c2]=='E') c++;
                        c2++;
                    } 
                }
                ans=max(ans,c);
            }
        }
        return ans;
    }
};
// Using DP editorial O(N.M)
class Solution {
    public int maxKilledEnemies(char[][] grid) {
        if (grid.length == 0)
            return 0;

        int rows = grid.length;
        int cols = grid[0].length;

        int maxCount = 0, rowHits = 0;
        int[] colHits = new int[cols];

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {

                // reset the hits on the row, if necessary.
                if (col == 0 || grid[row][col - 1] == 'W') {
                    rowHits = 0;
                    for (int k = col; k < cols; ++k) {
                        if (grid[row][k] == 'W')
                            // stop the scan when we hit the wall.
                            break;
                        else if (grid[row][k] == 'E')
                            rowHits += 1;
                    }
                }

                // reset the hits on the column, if necessary.
                if (row == 0 || grid[row - 1][col] == 'W') {
                    colHits[col] = 0;
                    for (int k = row; k < rows; ++k) {
                        if (grid[k][col] == 'W')
                            break;
                        else if (grid[k][col] == 'E')
                            colHits[col] += 1;
                    }
                }

                // run the calculation for the empty cell.
                if (grid[row][col] == '0') {
                    maxCount = Math.max(maxCount, rowHits + colHits[col]);
                }
            }
        }

        return maxCount;
    }
}