Find Topological sort:
Using stack, find min distances od node from source nodes.

Given souce node = src

void topo (int node,vector<int> ad[],vector<bool> &vis,stack<int> &st){
    vis[node]=1;
    for(int ch : ad[node]){
        if(vis[ch]==0){
            topo(ch,ad,vis,st);
        }
    }
    st.push(node);
}

vector<int> Solution::solve(int n, vector<vector<int> > &v,int src) {
   vector<pair<int,int>> ad[n+1];
   vector<bool> vis(n+1,0);
   stack<int> st;
   for(int i=0;i<v.size();i++){
     int x=v[i][0],y=v[i][1],w=v[i][2];
     ad[x].push_back({y,w});
     
   }
  for(int i=1;i<=n;i++){
      if(!vis[i]){
          topo(i,ad,vis,st);
      }
  }
    vector<int> dist(n+1,INT_MAX);
    dist[src]=0;
    while(!st.empty){
        int node=st.top();
        st.pop();

        if(dist[node]!=INT_MAX){
            for(auto x : ad[node]){
                if(dist[node] + x.second < dist[x.first]){
                    dist[x.first] = dist[node] + x.second ;
                }
            }
        }
    }
    return dist;
}