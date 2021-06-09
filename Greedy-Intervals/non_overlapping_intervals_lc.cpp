Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        int n=v.size();
        sort(v.begin(),v.end());
        int ans=0,start=v[0][1];
        for(int i=1;i<n;i++){
            if(start>v[i][0]){
                ans++;
                start=min(start,v[i][1]);
                
            }
            else{
             start=v[i][1];
            }
        }
        return ans;
    }
};