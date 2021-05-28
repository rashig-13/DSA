// It contains duplicates nos in the given vector so we need to sort and take a set.
class Solution {
public:
   void solve(set<vector<int>> &s,vector<int>& v,vector<int>& tmp,int cur,int k){
       if(k<0)
           return ;
       if(k==0){
           s.insert(tmp);
           return ;
       }
       for(int i=cur;i<v.size();i++){
           tmp.push_back(v[i]);
           solve(s,v,tmp,i+1,k-v[i]);
           tmp.pop_back();
       }
       return ;
   }
    vector<vector<int>> combinationSum2(vector<int>& v, int k) {
        vector<vector<int>> ans;
         set<vector<int>> s;
        sort(v.begin(),v.end());
        vector<int> tmp;
        solve(s,v,tmp,0,k);
        for(auto x : s){
            ans.push_back(x);
        }
        return ans;
        
    }
};