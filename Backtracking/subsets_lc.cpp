// Solution 1
class Solution {
public:
     
    void solve(vector<int>& v,vector<int> &tmp, vector<vector<int>> &ans,int i){
        if(v.size()==i){
            ans.push_back(tmp);
            return ;
        }
        vector<int> op1=tmp;
        vector<int> op2=tmp;
        op1.push_back(v[i]);
        solve(v,op1,ans,i+1);
        solve(v,op2,ans,i+1);
    }
    
    vector<vector<int>> subsets(vector<int>& v) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int i=0;
       solve(v,tmp,ans,i);
        return ans;
    }
};

// Solution 2
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> a;
    vector<vector<int>> solve(vector<int> &v,vector<vector<int>> &ans,vector<int> &a,int ind){
        ans.push_back(a);
        for(int i=ind;i<v.size();i++){
           a.push_back(v[i]);
            solve(v,ans,a,i+1);
            a.pop_back();
        }
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& v) {
        vector<vector<int>> res;
         res = solve(v,ans,a,0);
        
        return res;
    }
};