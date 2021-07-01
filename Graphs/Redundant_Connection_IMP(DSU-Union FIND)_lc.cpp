In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

// DETECTING THE CYCLE IN UNDIRECTED GRAPH
class Solution {
public:
    int find(vector<int> &parent,int i){
        if(parent[i]==-1){
            return i;
        }
        return find(parent,parent[i]);
    }
    void dounion(vector<int> &parent,int x,int y){
        parent[x]=y;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> parent(n+1,-1);
        vector<int> ans;
        for(int i=0;i<n;i++){
            int e1=edges[i][0];
            int e2=edges[i][1];
            int x=find(parent,e1);
            int y=find(parent,e2);
            if(x==y){
                ans.push_back(e1);
                ans.push_back(e2);
            }
            else
            dounion(parent,x,y);
        }
        return ans;
    }
};