Need to carry an additonal visited array (vis_2) as compared to detecting cycle in undirected graph.
whenever dfs calls returns true or both vis_1 and vis_2 happens to be visited( ie 1) it tells that cycle is present and returns true.


bool dfs(int node,vector<int> ad[],vector<bool> &vis_1,vector<bool> &vis_2){
    vis_1[node]=1;
    vis_2[node]=1;
    for(int ch : ad[node]){
        if(vis_1[ch]==0){
            if(dfs(ch,ad,vis_1,vis_2)==true)
            return true;
        }
        else if(vis_2[ch]==1) return true;
    }
    vis_2[node]=0;
    return false;
}
int Solution::solve(int n, vector<vector<int> > &v) {
    vector<int> ad[n+1];
    vector<bool> vis_1(n+1,0);
    vector<bool> vis_2(n+1,0);
    for(int i=0;i<v.size();i++){
        int x=v[i][0],y=v[i][1];
        ad[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(vis_1[i]==0){
            if(dfs(i,ad,vis_1,vis_2)==true)
            return  1;
        }
    }
    return 0;
}
