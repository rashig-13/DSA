You are given a network of n nodes, labeled from 1 to n. 
You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
We will send a signal from a given node k. 
Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Logic: Use Dijkstra's algo and calculated dist from node 'k'.
 
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> ad[n+1];
        vector<int> dist(n+1,INT_MAX);
        for(int i=0;i<times.size();i++){
            int x=times[i][0],y=times[i][1],w=times[i][2];
            ad[x].push_back({y,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            int cur=pq.top().second;
            int x=pq.top().first;
            pq.pop();
            for(auto ch : ad[cur]){
                if(dist[ch.first] > (x+ch.second)){
                    dist[ch.first]=x+ch.second;
                pq.push({dist[ch.first],ch.first});
                }
            }
        }
      
        int ans=0;
        for(int i=1;i<=n;i++){
             ans=max(ans,dist[i]);
         }
        if(ans==INT_MAX)
            return -1;
        else
            return ans;
    }
};