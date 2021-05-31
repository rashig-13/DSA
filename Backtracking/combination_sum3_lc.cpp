// given n & k , find all subsets of size k which sum to n and subset can have nos. from 1 to 9
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