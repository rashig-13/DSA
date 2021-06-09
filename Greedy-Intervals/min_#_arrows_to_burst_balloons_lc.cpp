452

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& v) {
        int n=v.size();
        sort(v.begin(),v.end());
        int ans=0,start=v[0][1];
        for(int i=1;i<n;i++){
           if(st>=v[i][0]) {
               start=min(st,v[i][1]);
           }
            else{
                ans++;
                start=v[i][1];
            }
        }
        return ans+1;
        
    }
};