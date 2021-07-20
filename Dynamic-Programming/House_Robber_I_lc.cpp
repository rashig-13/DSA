You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
// calculate the max sum st no two elements are adjacent.
class Solution {
public:
    int dp[105];
    int solve(vector<int> &v,int i){
        if(i>=v.size())
            return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]= max(solve(v,i+1),solve(v,i+2)+v[i]);
       
    }
    int rob(vector<int>& v) {
        memset(dp,-1,sizeof(dp));
       return  solve(v,0);
         
    }
};