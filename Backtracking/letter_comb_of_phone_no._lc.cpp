// gud DFS
class Solution {
public:
   void solve(vector<string> &v,vector<string> &ans,string op,string s,int cur){
       if(cur==s.length()){
           ans.push_back(op);
           return ;
       }
      int d=s[cur]-'0';
      for(int i=0;i<v[d].length();i++){
                  solve(v,ans,op+v[d][i],s,cur+1);
         }
   }
  
    vector<string> letterCombinations(string s) {
       vector<string> ans;
        if(s.length()==0) return ans;
        string op="";
        vector<string> v={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"} ;
        solve(v,ans,op,s,0);
        return ans;
        
    }
};
