You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes a bidirectional path between garden xi to garden yi. In each garden, you want to plant one of 4 types of flowers.

All gardens have at most 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th garden. The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists.

//Hint: Since each garden is connected to at most 3 gardens, there's always an available color for each garden. For example, if one garden is next to gardens with colors 1, 3, 4, then color #2 is available.
class Solution {
public:
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& v) {
        int m=v.size();
        
         vector<int> ad[n+1];
         vector<int> ans(n,0);
        for(int i=0;i<m;i++){
            int x=v[i][0],y=v[i][1];
            ad[x].push_back(y);
            ad[y].push_back(x);
        }
        for(int i=1;i<=n;i++) {
            sort(ad[i].begin(),ad[i].end());
        }
        bool vis[n+1];
        queue<int> q;
        for(int i=1;i<=n;i++) vis[i]=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                  ans[i-1]=1;
                  q.push(i);
                  vis[i]=1;
                      
        while(!q.empty()){
            int cur=q.front();
           for(int k=1;k<=4;k++){
               bool done=false;
                  for(int node: ad[cur]){
                      if(ans[node-1]==k) {
                          done=true;
                          break;}
                     
                  }  
               if(!done)
               ans[cur-1]=k;
            }
            q.pop();
        
            for(int c : ad[cur]){
                if(vis[c]==0){
                    q.push(c);
                     vis[c]=1;
                }
                else{
                    
                }
            }
           
        }

            }
        }
        
        return ans;
    }
};