class Solution {
public:

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n,-1);
        queue<int> q;
         for(int i=0;i<n;i++){
             if(col[i]==-1){
                q.push(i);
                 col[i]=1;
                 while(!q.empty()){
                     int cur=q.front();
                     q.pop();
                     for(int x : graph[cur]){
                         if(col[x]==-1){
                             col[x]=col[cur]^1;
                             q.push(x);
                         }
                         else if(col[x]==col[cur]) return false;
                     }
                 }
             }
         }
        return true;
    }
};