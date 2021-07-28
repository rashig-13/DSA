You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

class Solution {
public:
    int orangesRotting(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        queue<pair<int,int>> q;
        int total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==2){
                    q.push({i,j});
                }
               else if(v[i][j]==1) 
                    total++;
            }
        }
        
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        int time=0;
        while(!q.empty() && total>0){
            int qsize=q.size();
           for(int k=0;k<qsize;k++){
              
               int i=q.front().first;
               int j=q.front().second;
              
               q.pop();
               for(int z=0;z<dir.size();z++){
                   int x=i+dir[z].first;
                   int y=j+dir[z].second;
                
                   if(x>=0 && x<n && y>=0 && y<m && v[x][y]==1){
                      q.push({x,y});
                       v[x][y]=2;
                       total--;
                   }
               }
              
           }
           
            time++;
           
        }
        if(total==0)
        return time;
        else
            return -1;
    }
};