Topological Sort
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        int n=recipes.size();
        set<string> s;
        for(auto st : supplies){ //store all supplies in set
            s.insert(st);
        }
        unordered_map<string,vector<string>> graph; //for ordering of nodes
        unordered_map<string,int> indegree; //storing indegree of all nodes
        for(auto x : recipes) indegree[x]=0; //first mark eac recipes[i]'s indegree as 0
        
        for(int i=0;i<n;i++){
            for(auto ing : ingredients[i]){
                if(s.find(ing)==s.end()){ ///if the ingredient required to make a recipe is                                               not in supplies then directly make them
                    graph[ing].push_back(recipes[i]); //we need to make a directed edge from 
                    indegree[recipes[i]]++;            //that ingredient to recipe
                }
                
            }
        }
        //Kahn's algo
        queue<string> q;
        for(auto x : indegree){
            if(x.second==0) q.push(x.first);
        }
        
        vector<string> ans;
        
        while(!q.empty()){
            string cur=q.front();
            q.pop();
            ans.push_back(cur);
            for(auto it:graph[cur]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return ans;
        
    }
};