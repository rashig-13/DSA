class Solution {
public:
    void solve(int open,int close,vector<string> &ans,string op){
        if(open==0 && close==0){
            ans.push_back(op);
            return ;
        }
        if(open!=0){
             string op1=op;
            op1+='(';
            solve(open-1,close,ans,op1);
        }
         if(close>open){
             string op2=op;
            op2+=')';
            solve(open,close-1,ans,op2);
        }
       
    }
    vector<string> generateParenthesis(int n) {
       vector<string> ans;
        string op="";
        int open=n,close=n;
        solve(open,close,ans,op);
        return ans;
    }
};