There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1. 

//Logic: As long as there are at least (n - 1) connections, there is definitely a way to connect all computers.
else find # connected components - 1 

class Solution {
public:
    vector<int> ad[100005];
    bool vis[100005];
    void dfs(int node){
        vis[node]=1;
        for(int child : ad[node]){
            if(vis[child]==0){
                dfs(child);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& v) {
        int edges=v.size();
        // not possible case
        if(edges<n-1){
            return -1;
        }
        for(int i=0;i<edges;i++){
            int x=v[i][0],y=v[i][1];
            ad[x].push_back(y);
            ad[y].push_back(x);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                dfs(i);
            }
        }
        return ans-1;
    }
};