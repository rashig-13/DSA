You have n  tiles, where each tile has one letter tiles[i] printed on it.

Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

 Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

refer ; https://www.youtube.com/watch?v=nYFd7VHKyWQ

class Solution {
public:
    void dfs(vector<int> &a,int &ans){
        for(int i=0;i<26;i++){
            if(a[i]){
                a[i]--;
                ans++;
                dfs(a,ans);
                a[i]++;
            }
        }
    }
    int numTilePossibilities(string s) {
        int ans=0;
        vector<int> a(26,0);
        for(int i=0;i<s.length();i++) a[s[i]-'A']++;
        dfs(a,ans);
        return ans;
    }
};