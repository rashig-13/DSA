// #Heap's Algorithm
class Solution {
public:
    void solve(vector<int>& v,vector<vector<int>> &ans,int ind){
       if(ind==v.size()){
           ans.push_back(v);
           return ;
       }        
        for(int i=ind;i<v.size();i++){
            swap(v[i],v[ind]);
            solve(v,ans,ind+1);
            swap(v[i],v[ind]);
        }
        return ;
    }
    vector<vector<int>> permute(vector<int>& v) {
        vector<vector<int>> ans;
        solve(v,ans,0);
        return ans;
    }
};