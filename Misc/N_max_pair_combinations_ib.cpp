Given two arrays A & B of size N each.
Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6
and maximum 2 elements are 6, 5

// not sorted and same size of both arrays
vector<int> Solution::solve(vector<int> &a, vector<int> &b) {
    int n=a.size();
    priority_queue<pair<int,pair<int,int>>> pq;
    vector<int> ans;
    for(int i=0;i<n;i++){
        pq.push({a[i]+b[0],{i,0}});
    }
    while(ans.size()<n){
        pair<int,pair<int,int>> temp=pq.top();
        pq.pop();
        int i=pq.second.first;
        int j=pq.second.second;
        ans.push_back(temp.first);
        pq.push({a[i]+b[j+1],{i,j+1}});
    }
    return ans;
}
