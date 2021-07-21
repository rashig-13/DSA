Design a data structure that will be initialized with a string array, and then it should answer queries of the shortest distance between two different strings from the array.

Implement the WordDistance class:

WordDistance(String[] wordsDict) initializes the object with the strings array wordsDict.
int shortest(String word1, String word2) returns the shortest distance between word1 and word2 in the array wordsDict.

//using two pointers
class WordDistance {
public:
    unordered_map<string,vector<int>> mp;
   
    WordDistance(vector<string>& v) {
        for(int i=0;i<v.size();i++){
            mp[v[i]].push_back(i);
        }
    }
    
    int shortest(string s1, string s2) {
        vector<int> a=mp[s1];
        vector<int> b=mp[s2];
         int ans=INT_MAX;
        int i=0,j=0;
        while(i<a.size() && j<b.size()){
            ans=min(ans,abs(a[i]-b[j]));
            if(a[i]<=b[j]){
                i++;
            }
            else
                j++;
        }
        return ans;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */