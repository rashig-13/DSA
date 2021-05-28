// you can take any no. from given vector unlimited # times.
class Solution {
public :
    
    void solve(vector<int>& v,vector<int> &tmp,vector<vector<int>> &ans,int k,int cur){
        if(k<0){
            return ;
        }
        if(k==0){
            ans.push_back(tmp);
            return ;
        }
        for(int i=cur;i<v.size();i++){
            tmp.push_back(v[i]);
            solve(v,tmp,ans,k-v[i],i);
            tmp.pop_back();
            
        }
        return ;
    }
    
    vector<vector<int>> combinationSum(vector<int>& v, int k) {
     vector<vector<int>> ans;
    vector<int> tmp;
    solve(v,tmp,ans,k,0);
    return ans;
       
    }
};