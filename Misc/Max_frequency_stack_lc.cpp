Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the FreqStack class:

FreqStack() constructs an empty frequency stack.
void push(int val) pushes an integer val onto the top of the stack.
int pop() removes and returns the most frequent element in the stack.
If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.

class FreqStack {
public:

    map<int,vector<int>> mp;
    unordered_map<int,int> values;
    FreqStack() {
      
    }
    
    void push(int x) {
        if(values.find(x)!=values.end()){
            int freq=values[x];
            freq++;
            values[x]++;
            mp[freq].push_back(x);
        }
        else{
            values[x]++;
            mp[1].push_back(x);
        }
        return ;
    }
    
    int pop() {
        auto it=mp.rbegin();
        int ans=mp[it->first].back();
        values[ans]--;
        if(values[ans]==0) values.erase(ans);
        mp[it->first].pop_back();
        if(mp[it->first].size()==0) mp.erase(it->first);
      
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */