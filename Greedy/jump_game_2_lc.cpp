Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.


class Solution {
public:
    int jump(vector<int>& v) {
       int n=v.size();
        int cur_end=0,farthest=0;
        int ans=0;
        for(int i=0;i<n-1;i++){
            farthest=max(farthest,i+v[i]);
            if(i==cur_end){
                ans++;
                cur_end=farthest;
            }
        }
        return ans;
    }
};