class Solution {
public:
    bool dfs(vector<int> &col,int node,vector<vector<int>>& graph){
      if(col[node]==-1)  col[node]=1;
        for(int ch : graph[node]){
            if(col[ch]==-1){
                col[ch]=col[node]^1;
                if(!dfs(col,ch,graph))
                    return false;
            }
            else if(col[ch]==col[node])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n,-1);
         for(int i=0;i<n;i++){
             if(col[i]==-1){
                 if(dfs(col,i,graph)==false)
                     return false;
             }
         }
        return true;
    }
};