First create a indegree array and mark all the indegrees.
Then push all nodes with indegree=0.
Iterate the queue and decrement the indegress of adj node of current node, and as soon as we get indegree=0, 
push it in queue.

vector<int> Solution::solve(int n, vector<vector<int> > &v) {
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
   vector<int> ans;
   while(!q.empty()){
    int cur=q.front();
    q.pop();
    ans.push_back(cur);
    for(int ch : ad[cur]){
      indegree[ch]--;
      if(indegree[ch]==0){
        q.push(ch);
      }
    }
   }
   return ans;
}