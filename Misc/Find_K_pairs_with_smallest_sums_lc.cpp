You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
// sorted but not same size 

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        int f=a.size()*b.size();
        k=min(k,f);
    
        vector<vector<int>> ans;
        priority_queue< pair<int,pair<int,int>>, vector< pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        int i=0,j=0;
        for(int i=0;i<a.size();i++){
            pq.push({a[i]+b[0],{i,0}});
        }
        while(ans.size()<k){
            pair<int,pair<int,int>> tmp=pq.top();
            int i=tmp.second.first;
            int j=tmp.second.second;
            pq.pop();
            ans.push_back({a[i],b[j]});
            if(j+1<b.size())
            pq.push({a[i]+b[j+1],{i,j+1}});
        }
            
        return ans;
        
    }
};