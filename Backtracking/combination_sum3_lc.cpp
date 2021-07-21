Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations.
 The list must not contain the same combination twice, and the combinations may be returned in any order.
class Solution {
public:
    void solve(int k,int n,vector<vector<int>> &ans,vector<int> &tmp,int cur){
        if(n==0 && tmp.size()==k){
            ans.push_back(tmp);
            return ;
        }
        for(int i=cur;i<=9;i++){
            tmp.push_back(i);
            solve(k,n-i,ans,tmp,i+1);
            tmp.pop_back();
        }
        return ;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(k,n,ans,tmp,1);
        return ans;
    }
};