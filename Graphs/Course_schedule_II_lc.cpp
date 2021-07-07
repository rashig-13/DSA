There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

Logic: This problem is equivalent to finding the topological order in a directed graph. 
If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& v) {
         vector<int> ad[n];
        vector<int> indegree(n,0);
        for(int i=0;i<v.size();i++){
            int x=v[i][0],y=v[i][1];
            ad[y].push_back(x);
            
        }
        for(int i=0;i<n;i++){
            for(int x : ad[i]){
                indegree[x]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> topo;
        
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            topo.push_back(cur);
            for(int x : ad[cur]){
                indegree[x]--;
                if(indegree[x]==0)
                    q.push(x);
            }
        }
        if(topo.size()==n)
        return topo;
        else
            return {};
    }
};