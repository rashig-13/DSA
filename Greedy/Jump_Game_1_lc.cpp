Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

class Solution {
public:
    bool canJump(vector<int>& v) {
       int n=v.size();
        int last=n-1;
        for(int i=n-1;i>=0;i--){
            if((i+v[i])>=last)
                last=i;
        }
        return last==0;
        
    }
};