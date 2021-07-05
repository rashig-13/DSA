souce node=src

vector<int> Solution::solve(int n, vector<vector<int> > &v,int src) {
   vector<int> ad[n+1];
   vector<int> dist(n+1,INT_MAX);
   for(int i=0;i<v.size();i++){
     int x=v[i][0],y=v[i][1];
     ad[x].push_back(y);
     ad[y].push_back(x);
   }

   queue<int> q;
   dist[src]=0;
   q.push(src);
   while(!q.empty()){
    int cur=q.front();
    q.pop();
    for(int ch : ad[cur]){
      if(dist[cur]+1 < dist[ch]){
        dist[ch] = dist[cur] + 1;
        q.push(ch);
      }
   }
  }
   return dist;
}