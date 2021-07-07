Given a set of n people (numbered 1, 2, ..., n), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.
class Solution {
public:
    bool bipartite(vector<int> ad[],int node,vector<int> &col){
       if(col[node]==-1) col[node]=1;
        for(auto x : ad[node]){
            if(col[x]==-1){
                col[x]=col[node]^1;
                if(!bipartite(ad,x,col))
                    return false;
            }
            else if(col[node]==col[x])
                return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& v) {
        vector<int> ad[n+1];
        for(int i=0;i<v.size();i++){
            int x=v[i][0],y=v[i][1];
            ad[x].push_back(y);
            ad[y].push_back(x);
        }
        vector<int> col(n+1,-1);
        for(int i=1;i<=n;i++){
            if(col[i]==-1){
                if(bipartite(ad,i,col)==false)
                 return false;
            }
        }
        return true;
    }
};