Design a data structure to store the string count with the ability to return the strings with minimum and maximum counts.

Implement the AllOne class:

AllOne() Initializes the object of the data structure.
inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".

LOGIC SIMILAR TO MAX_FREQ_STACK (895).

class AllOne {
public:
    /** Initialize your data structure here. */
    unordered_map<string,int> mp;
    map<int,set<string>> freq;
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(mp.find(key)!=mp.end()){
            int i=mp[key];
            mp[key]++;
            freq[i].erase(key);
             if(freq[i].size()==0) freq.erase(i);
            freq[mp[key]].insert(key);
             
        }
        else{
            mp[key]++;
            freq[1].insert(key);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(mp.find(key)!=mp.end()){
            int i=mp[key];
            mp[key]--;
            
            if(mp[key]==0){
                mp.erase(key);
                freq[1].erase(key);
                if(freq[1].size()==0) freq.erase(1);
            }
            else{
                
               freq[i].erase(key);
                if(freq[i].size()==0) freq.erase(i);
                freq[mp[key]].insert(key);
                
            }
        }
        else{
            return ;        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {

        string ans="";
        if(mp.size()==0)
            return ans;
        else
        {
            auto it=freq.rbegin();
            ans=*(freq[it->first].begin());
            return ans;
        }
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        string ans="";
        if(mp.size()==0)
            return ans;
        else
        {
            auto it=freq.begin();
            return *(freq[it->first].begin());
        }
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */