// Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.

//Return the maximum possible length of s.
// USING DFS
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