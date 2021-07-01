There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.

The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.

The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.

Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.

Logic: use brute force to check b/w every pair.

class Solution {
public:
     vector<int> ad[105];
     // function to check whether x and y nodes lie in same component or not.
    bool find(int x,int y){
        for(int c : ad[x]){
            if(c==y)
                return true;
        }
        return false;
    }
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans=0;
       
        for(int i=0;i<roads.size();i++){
            int x=roads[i][0],y=roads[i][1];
            ad[x].push_back(y);
            ad[y].push_back(x);
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(find(i,j)){
                    int tmp=ad[i].size()+ad[j].size();
                    ans=max(ans,tmp-1);
                }
                else{
                     int tmp=ad[i].size()+ad[j].size();
                    ans=max(ans,tmp);
                }
            }
        }
        return ans;
    }
};