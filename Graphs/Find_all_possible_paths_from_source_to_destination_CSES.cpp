Que: Game Routes (CSES)

Given a Directed Acyclic Graph with n vertices and m edges. 
The task is to find the number of different paths that exist from a source vertex to destination vertex. 
//Concept GFG:
First find Topological Sort of given graph and store in an array.
Then from this array, start from last element to first, start filling dp array
 st. each node adds all possible paths from its child nodes. (and that will be ofc right because they are corretly ordered region)

void solve(){
   int n,m;
   cin>>n>>m;
   vector<int> ad[n+1];
   vector<int> indegree(n+1,0);
   for(int i=0;i<m;i++){
     int x,y;
     cin>>x>>y;
     ad[x].push_back(y);
   }
 
   for(int i=0;i<n;i++){
     for(auto x : ad[i]){
       indegree[x]++;
     }
   }
   queue<int> q;
   for(int i=1;i<=n;i++){
    if(indegree[i]==0)
      q.push(i);
   }
   vector<int> s;
   while(!q.empty()){
    int cur=q.front();
    q.pop();
    s.push_back(cur);
    for(int ch : ad[cur]){
      indegree[ch]--;
      if(indegree[ch]==0){
        q.push(ch);
      }
    }
   }
   
   int dp[n+1]={0};
   dp[n]=1;
   for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = 0; j < (int)ad[s[i]].size(); j++) {
            dp[s[i]] =(dp[s[i]] + dp[ad[s[i]][j]])  ;
        }
    }
    cout<<dp[1];
}

Alternate: Using DFS
Ulta Topological Sort-> value start filling in dp from last node first. Then for any node
we will add paths of its child nodes.

Code:
#include<bits/stdc++.h>
 using namespace std;
 #define ll    long long
inline ll add(ll a, ll b) { return ((a % mod) + (b % mod)) % mod; }
 
ll dfs(ll node, vector<vector<ll>> &adj, vector<bool> &visited, vector<ll> &nodeVal, ll N) {
    if (node == N - 1) {
        visited[node] = true;
        nodeVal[node] = 1;
        return 1;
    }
 
    visited[node] = true;
    ll curNodeVal = 0;
 
    for (int i = 0; i < adj[node].size(); i++) {
        ll child = adj[node][i];
        if (visited[child] == false) {
            ll childVal = dfs(child, adj, visited, nodeVal, N);
            curNodeVal = add(curNodeVal, childVal);
        } else {
            ll childVal = nodeVal[child];
            curNodeVal = add(curNodeVal, childVal);
        }
    }
 
    return nodeVal[node] = curNodeVal;
}
 
void solve() {
 
    ll N, M;
    cin >> N >> M;
 
    vector<vector<ll>> adj(N);
 
    vector<ll> nodeVal(N, 0);
 
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
    }
 
    vector<bool> visited(N, false);
 
    dfs(0, adj, visited, nodeVal, N);
 
    cout << nodeVal[0] << endl;
 
 
}
 
int main() {
    
        solve();
    return 0;
}