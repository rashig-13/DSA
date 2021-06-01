// Using backtracking
class Solution {
public:
    void solve(vector<string> &v,vector<string> &ans,string s,int n,int cur){
        if(s.length()==n){
            ans.push_back(s);
            return ;
        }
        if(s.length()>n){
            return ;
        }
        for(int i=cur;i<v.size();i++){
           string tmp=s+v[i];
            solve(v,ans,tmp,n,i);
            
        }
        return ;
    }
    int countVowelStrings(int n) {
        vector<string> v;
        v.push_back("a");
        v.push_back("e");
        v.push_back("i");
        v.push_back("o");
        v.push_back("u");
        vector<string> ans;
        string tmp="";
        solve(v,ans,tmp,n,0);
        return ans.size();
       
    }
};
//using dp
class Solution {
public:
    
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1,vector<int>(6));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=5;j++){
                if(i==1)
                dp[i][j]=dp[i][j-1] + 1;
                else
                    dp[i][j]=dp[i][j-1] + dp[i-1][j]; 
            }
        }
       return dp[n][5];
    }
};