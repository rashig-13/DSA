class Solution {
public:
   void solve(vector<int>& v,set<vector<int>> &s,vector<int> &tmp,int i){
       if(i==v.size()){
           s.insert(tmp);
           return;
       }
       vector<int> op1=tmp;
       vector<int> op2=tmp;
       op1.push_back(v[i]);
       solve(v,s,op1,i+1);
       solve(v,s,op2,i+1);
       return ;
       
   }
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        set<vector<int>> s;
        vector<int> tmp;
        sort(v.begin(),v.end());
        solve(v,s,tmp,0);
        vector<vector<int>> ans;
        for(auto x : s){
            ans.push_back(x);
        }
        return ans;
    }
};