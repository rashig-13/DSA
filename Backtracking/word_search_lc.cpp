class Solution {
public:
    bool dfs(int i,int j,int cnt,string s,vector<vector<char>>& v){
        if(cnt==s.length())
            return true;
        if(i<0 || i>=v.size() || j<0 || j>=v[0].size() || v[i][j]!=s[cnt]){
            return false;
        }
        char tmp=v[i][j];
        v[i][j]=' ';
        bool find = dfs(i+1,j,cnt+1,s,v) || dfs(i,j+1,cnt+1,s,v) || dfs(i,j-1,cnt+1,s,v) 
            || dfs(i-1,j,cnt+1,s,v);
        
        v[i][j]=tmp;
        return find;
        
    }
    bool exist(vector<vector<char>>& v, string s) {
        int n=v.size(),m=v[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==s[0] && dfs(i,j,0,s,v))
                    return true;
            }
        }
        return false;
        
    }
};