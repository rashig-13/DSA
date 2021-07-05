Use Kahn's Algo (only possiblein DAG): 
If able to perform Kahn's algo - no cycle else cycle. 
//count iterations inside queue nd compare it with n.

bool Solution::solve(int n, vector<vector<int> > &v) {
   vector<int> ad[n+1];
   vector<int> indegree(n+1,0);
   for(int i=0;i<v.size();i++){
     int x=v[i][0],y=v[i][1];
     ad[x].push_back(y);
   }

   for(int i=1;i<=n;i++){
     for(auto x : ad[i]){
       indegree[x]++;
     }
   }
   queue<int> q;
   for(int i=1;i<=n;i++){
    if(indegree[i]==0)
      q.push(i);
   }
   int cnt=0;
   while(!q.empty()){
    int cur=q.front();
    q.pop();
    cnt++;
    for(int ch : ad[cur]){
      indegree[ch]--;
      if(indegree[ch]==0){
        q.push(ch);
      }
    }
   }
   if(cnt==n) return false;
   else
   return true;
}