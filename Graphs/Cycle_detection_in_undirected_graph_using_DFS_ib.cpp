Method used: making parent nodes.


bool hascycle(int node,int parent,vector<int> ad[],vector<bool> &vis,int n){
    vis[node]=1;
    for(int ch : ad[node]){
        if(vis[ch]==0){
            if(hascycle(ch,node,ad,vis,n)) return true;
        }
        else if(ch!=parent){
            return true;
        }
    }
    return false;
}

int Solution::solve(int n, vector<vector<int> > &v) {
    int m=v.size();
    vector<int> ad[n+1];
    vector<bool> vis(n+1,0);
    for(int i=0;i<m;i++){
      int x=v[i][0],y=v[i][1];
      ad[x].push_back(y);
      ad[y].push_back(x);
    }
   
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            if(hascycle(i,-1,ad,vis,n)==true)
            return 1;
        }
    }
    return 0;
}
Applications: 
Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs. 
In computer science, applications of this type arise in instruction scheduling, ordering of formula cell evaluation
when recomputing formula values in  spreadsheets, logic synthesis, determining the order of compilation tasks to 
perform in make files,  data serialization, and resolving symbol dependencies in linkers.