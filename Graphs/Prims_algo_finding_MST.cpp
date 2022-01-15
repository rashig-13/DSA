Undirected weighted graph.
// node indexes from 0 to n-1.

Brute force => TC : > O(> N^2)
vector<int> Solution::solve(int n, vector<vector<int> > &v){
    vector<pair<int,int>> ad[n];
    for(int i=0;i<v.size();i++){
        int x=v[i][0],y=v[i][1],w=v[i][2];
        ad[x].push_back({y,w});
        ad[y].push_back({x,w});
    }

    vector<int> key(n,INT_MAX);
    vector<bool> mst(n,false);
    vector<int> parent(n,-1);

    key[0]=0; // inialise mst with node 1 and mark its key as 0.
    
   for(int i=0;i<n-1;i++){
        int mn=INT_MAX,node;
       //search for lowest value in key[] with mst set as false
       for(int j=0;j<n;j++){
          if(mst[j]==false && mn > key[j]){
              node=j,mn=key[j];
          }
       }
       //incluse in mst
       mst[node] = true;
       //visit all adj nodes of "node" and if mst is set to false
       //then update the min value in key[] and update parent[]
        for(int ch : ad[node]){
            int x=ch.first, w=ch.second;
            if(mst[x]==false && key[x]>w){
                key[x]=w;
                parent[x]=node;
            }
        }
   }

   return parent;
}

Efficient 
//just use min heap to find min form key[]
vector<int> Solution::solve(int n, vector<vector<int> > &v){
    vector<pair<int,int>> ad[n];
    for(int i=0;i<v.size();i++){
        int x=v[i][0],y=v[i][1],w=v[i][2];
        ad[x].push_back({y,w});
        ad[y].push_back({x,w});
    }

    vector<int> key(n,INT_MAX);
    vector<bool> mst(n,false);
    vector<int> parent(n,-1);

    key[0]=0; // inialise mst with node 1 and mark its key as 0.
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0,0}); // first value in key[] and then node value

   while(!pq.empty()){
        
        int node=pq.top().second;
        pq.pop();
       
       //incluse in mst
       mst[node] = true;
       //visit all adj nodes of "node" and if mst is set to false
       //then update the min value in key[] and update parent[]
        for(int ch : ad[node]){
            int x=ch.first, w=ch.second;
            if(mst[x]==false && key[x]>w){
                key[x]=w;
                parent[x]=node;
                pq.push({w,x});
            }
        }
   }

   return parent;
}
