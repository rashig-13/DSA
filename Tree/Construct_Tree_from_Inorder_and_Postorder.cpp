
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int root_index;
    TreeNode* solve(vector<int> &in,vector<int> &post,int inStart,int inEnd,unordered_map<int,int> &mp){
        if(inStart>inEnd){
            return NULL;
        }
        TreeNode* root=new TreeNode(post[root_index--]);
        if(inStart==inEnd)
            return root;
        int index=mp[root->val];
        root->right=solve(in,post,index+1,inEnd,mp);
        root->left=solve(in,post,inStart,index-1,mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        root_index=post.size()-1;
        unordered_map<int,int> mp;
        for(int i=0;i<in.size();i++){
            mp.insert({in[i],i});
        }
       return solve(in,post,0,in.size()-1,mp);
    }
};
