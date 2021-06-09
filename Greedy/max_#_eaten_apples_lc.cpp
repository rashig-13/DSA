1705
There is a special kind of apple tree that grows apples every day for n days. On the ith day, the tree grows apples[i] apples that will rot after days[i] days, that is on day i + days[i] the apples will be rotten and cannot be eaten. On some days, the apple tree does not grow any apples, which are denoted by apples[i] == 0 and days[i] == 0.

You decided to eat at most one apple a day (to keep the doctors away). Note that you can keep eating after the first n days.

Given two integer arrays days and apples of length n, return the maximum number of apples you can eat.
 
 //IMP
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
       int n=apples.size();
       priority_queue< pair<int,int>, vector< pair<int,int>>, greater< pair<int,int>> > pq;
        int ans=0,i=0;
        while(i<n || pq.size()>0){
            if(i<n && apples[i]>0) pq.push({i+days[i]-1,apples[i]});
            
            while(!pq.empty() && pq.top().first<i){
                pq.pop();
            }
            if(!pq.empty()){
                auto tmp=pq.top();
                pq.pop();
                ans++;
                if(tmp.second>1) pq.push({tmp.first,tmp.second-1});
            }
            i++;
        }
        
        return ans;
        
        
        
    }
};