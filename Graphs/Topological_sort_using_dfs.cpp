Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for
every directed edge u v, vertex u comes before v in the ordering.

* ONLY POSSIBLE IN => DAG(DIRECTED ACYCLIC GRAPH)

void topo (int node,vector<int> ad[],vector<bool> &vis,stack<int> &st){
    vis[node]=1;
    for(int ch : ad[node]){
        if(vis[ch]==0){
            topo(ch,ad,vis,st);
        }
    }
    st.push(node);
    
}

vector<int> Solution::solve(int n, vector<vector<int> > &v) {
    int m=v.size();
    vector<int> ad[n+1];
    vector<bool> vis(n+1,0);
    stack<int> st;
    for(int i=0;i<m;i++){
      int x=v[i][0],y=v[i][1];
      ad[x].push_back(y); //directed graph
    }
   
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
           (topo(i,ad,vis,st)
          
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

Applications: 
Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs. 
In computer science, applications of this type arise in instruction scheduling, ordering of formula cell evaluation
when recomputing formula values in  spreadsheets, logic synthesis, determining the order of compilation tasks to 
perform in make files,  data serialization, and resolving symbol dependencies in linkers.