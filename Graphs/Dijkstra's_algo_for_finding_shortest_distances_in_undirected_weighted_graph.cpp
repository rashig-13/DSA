Just use priority_queue and rest is same.
Can be used for both directed and undirected graph.

vector<int> Solution::solve(int n, vector<vector<int> > &v,int src){
    vector<pair<int,int>> ad[n+1];
    vector<int> dist(n+1,INT_MAX);
    for(int i=0;i<v.size();i++){
        int x=v[i][0],y=v[i][1],w=v[i][2];
        ad[x].push_back({y,w});
        ad[y].push_back({x,w});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,src});//first push distance then node in pq.
    dist[src]=0;
    while(!pq.empty()){
        int node=pq.top().second;
        int x=pq.top().first;
        pq.pop();
        for(auto ch : ad[node]){
            if(x+ ch.second < dist[ch.first]){
                dist[ch.first] = x+ch.second;
                pq.push({dist[ch.first],ch.first});
            }
        }
    }
    return dist;
}