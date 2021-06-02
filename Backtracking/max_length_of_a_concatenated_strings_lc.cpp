// 1239 -lc
class Solution {
public:
    int ans=0;
    bool isunique(string s){
        int n=s.length();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end())
                return false;
            else
                mp[s[i]]++;
        }
        return true;
    }
    void solve(vector<string> &v,string tmp,int cur){
        if(isunique(tmp)){
            ans=max(ans,(int)tmp.length());
        }
        if(cur==v.size() || !isunique(tmp)){
            return ;
        }
        for(int i=cur;i<v.size();i++){
            string a=tmp+v[i];
            solve(v,a,i+1);
            
        }
    }
    int maxLength(vector<string>& v) {
        string tmp="";
        solve(v,tmp,0);
        return ans;
    }
};