There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.

LOGIC: Treat the graph as undirected. Start a dfs from the root, if you come across an edge in the forward direction, you need to reverse the edge.
//Remeber it's a Tree :)

class Solution {
public:
    vector<int> ad[50005];
    vector<int> dir[50005];
    bool vis[50005];
    int ans=0;
     bool check(int a,int b){
        for(int x : dir[a]){
           if(x==b)
               return true;
        }
        return false;
    }
    void dfs(int node){
        vis[node]=1;
        for(int child : ad[node]){
            if(vis[child]==0){
                if(check(node,child)==true) ans++;
                dfs(child);
            }
        }
        return ;
    }
    int minReorder(int n, vector<vector<int>>& v) {
       for(int i=0;i<v.size();i++){
           int x=v[i][0],y=v[i][1];
           ad[x].push_back(y);
           ad[y].push_back(x);
           dir[x].push_back(y);
       } 
        
        dfs(0);
        return ans;
    }
};