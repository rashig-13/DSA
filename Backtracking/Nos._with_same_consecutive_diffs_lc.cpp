//Return all non-negative integers of length n such that the absolute difference between every two consecutive digits is k.

//Note that every number in the answer must not have leading zeros. For example, 01 has one leading zero and is invalid.

//You may return the answer in any order. 
 // (IMP)
class Solution {
public:
    void solve(int num,vector<int> &ans,int n,int k){
        if(n==0){
            ans.push_back(num);
            return ;
        }
        int last_digit=num%10;
        vector<int> tmp;
        tmp.push_back(last_digit+k);
        if(k!=0) tmp.push_back(last_digit-k);
        for(int x : tmp){
            if(x>=0 && x<=9){
                int new_num=num*10+x; //have to assign to a new variable
                solve(new_num,ans,n-1,k);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
           solve(i,ans,n-1,k);
        }
        return ans;
    }
};