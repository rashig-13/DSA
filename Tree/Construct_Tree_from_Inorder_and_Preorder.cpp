Time Complexity: O(n^2) 
Worst case: When the tree is left skewed
class Solution {
public:
   int root_index=0;
 int find(int l,int h,vector<int> &in,int x){
     int ind;
     for(int i=l;i<=h;i++){
         if(in[i]==x){
         ind=i;
         break;
         }
     }
     return s;
 }
 TreeNode* solve(vector<int> &pre,vector<int> &in,int inStart,int inEnd){
     
     if(inStart > inEnd)
     return NULL;
     
     TreeNode* root=new TreeNode(pre[root_index++]);
     if(inStart==inEnd)
     return root;
     int index=find(inStart,inEnd,in,root->val);
     
     root->left=solve(pre,in,inStart,index-1);
     root->right=solve(pre,in,index+1,inEnd);
     return root;
 }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
         return solve(pre,in,0,in.size()-1);
    }
};

Efficient=> Time Complexity: O(n)
Use hashmap to store index so search will take O(1)
class Solution {
public:
int root_index=0;
unordered_map<int,int> mp;
 TreeNode* solve(vector<int> &pre,vector<int> &in,int inStart,int inEnd){
     
     if(inStart > inEnd)
     return NULL;
     
     TreeNode* root=new TreeNode(pre[root_index++]);
     if(inStart==inEnd)
     return root;
     int index=mp[root->val];
     
     root->left=solve(pre,in,inStart,index-1);
     root->right=solve(pre,in,index+1,inEnd);
     return root;
 }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        
        for(int i=0;i<in.size();i++) mp[in[i]]=i;
         return solve(pre,in,0,in.size()-1);
    }
};




