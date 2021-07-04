We start at some node in a directed graph, and every turn, we walk along a directed edge of the graph. If we reach a terminal node (that is, it has no outgoing directed edges), we stop.

We define a starting node to be safe if we must eventually walk to a terminal node. More specifically, there is a natural number k, so that we must have stopped at a terminal node in less than k steps for any choice of where to walk.

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

The directed graph has n nodes with labels from 0 to n - 1, where n is the length of graph. The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph, going from node i to node j

Logic: Find all nodes which is not involved in any cycle gambling
class Solution {
public:
   
    vector<int> eventualSafeNodes(vector<vector<int>>& v) {
        int n=v.size();
        vector<int> ans;
         vector<set<int>> graph(100005);
         vector<set<int>> rgraph(10005);
         queue<int> q;
        for(int i=0;i<n;i++){
            if(v[i].size()==0){
                q.push(i);
            }
            for(int j : v[i]){
                graph[i].insert(j);
                rgraph[j].insert(i);
            }
            
        }
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            ans.push_back(cur);
            for(int ch : rgraph[cur]){
                if(graph[ch].find(cur)!=graph[ch].end()){
                    graph[ch].erase(cur);
                }
                if(graph[ch].size()==0)
                    q.push(ch);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;                
    }
};
