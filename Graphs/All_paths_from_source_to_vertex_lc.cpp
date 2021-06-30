Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1, and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).



class Solution {
public:

    void dfs(vector<vector<int>> &v,vector<vector<int>> &ans,vector<int> &tmp,int node){
        if(node==v.size()-1){
            ans.push_back(tmp);
            return ;
        }
        for(int cur:v[node]){
            tmp.push_back(cur);
            dfs(v,ans,tmp,cur);
            tmp.pop_back();
        }
      
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& v) {
        
        vector<vector<int>> ans;
        vector<int> tmp;
        tmp.push_back(0);
        dfs(v,ans,tmp,0);
        return ans;
    }
};