class Solution {
public:
    
    void solve(string s,string op,vector<string> &ans){
        if(s.length()==0){
            ans.push_back(op);
            return ;
        }
        string op1=op,op2=op;
        if(isalpha(s[0])){
            string op1=op,op2=op;
            op1.push_back(tolower(s[0]));
            op2.push_back(toupper(s[0]));
            s.erase(s.begin());
            solve(s,op1,ans);
            solve(s,op2,ans);
            
        }
        else{
             string op1=op;
            op1+=s[0];
            s.erase(s.begin());
            solve(s,op1,ans);
        }
    }
    vector<string> letterCasePermutation(string s) {
        string op="";
        vector<string> ans;
        solve(s,op,ans);
        return ans;
    }
};