Given a binary tree root. Split the binary tree into two subtrees by removing 1 edge such that the product of the sums of the subtrees are maximized.

Since the answer may be too large, return it modulo 10^9 + 7.
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
    int solve(TreeNode* root,vector<int> &v){
        if(root==NULL)
            return 0;
        int left=solve(root->left,v);
        int right=solve(root->right,v);
        int total_sum=left+right+root->val;
        v.push_back(total_sum);
        return total_sum;
    }
    int maxProduct(TreeNode* root) {
        vector<int> v;
        long total=solve(root,v);
        long ans=0;
        for(int x : v){
            ans=max(ans,x*(total-x));
        }
        return (int)(ans%1000000007);
        
        
    }
};