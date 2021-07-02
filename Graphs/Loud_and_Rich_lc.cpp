In a group of N people (labelled 0, 1, 2, ..., N-1), each person has different amounts of money, and different levels of quietness.

For convenience, we'll call the person with label x, simply "person x".

We'll say that richer[i] = [x, y] if person x definitely has more money than person y.  Note that richer may only be a subset of valid observations.

Also, we'll say quiet[x] = q if person x has quietness q.

Now, return answer, where answer[x] = y if y is the least quiet person (that is, the person y with the smallest value of quiet[y]), among all people who definitely have equal to or more money than person x.

class Solution {
public:
    vector<int> ad[505];
    void dfs(int node,int *vis){
        vis[node]=1;
        for(int ch:ad[node]){
            if(vis[ch]==0)
                dfs(ch,vis);
        }
        return ;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        
        vector<int> ans(n,0);
        for(int i=0;i<richer.size();i++){
            int x=richer[i][0],y=richer[i][1];
            ad[y].push_back(x);
        }
        int vis[n];
        for(int i=0;i<n;i++){
            memset(vis,0,sizeof(vis));
            dfs(i,vis);
            int cur=quiet[i],an=i;
            for(int j=0;j<n;j++){
                if(vis[j]==1){
                    if(quiet[j]<cur){
                        cur=quiet[j];
                        an=j;
                    }
                }
            }
            ans[i]=an;
            
        }
        return ans;
    }
};