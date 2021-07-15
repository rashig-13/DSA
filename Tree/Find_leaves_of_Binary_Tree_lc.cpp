Given the root of a binary tree, collect a tree's nodes as if you were doing this:

Collect all the leaf nodes.
Remove all the leaf nodes.
Repeat until the tree is empty.
//
Input: root = [1,2,3,4,5]
Output: [[4,5,3],[2],[1]]
Explanation:
[[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers since per each level it does not
 matter the order on which elements are returned.

//Sol based on using concept of height.
TC: O(N) //using postorder traversal.
class Solution {
public:
    int solve(TreeNode* root,vector<vector<int>> &ans){
        if(root==NULL)
            return -1;
        int left=solve(root->left,ans);
        int right=solve(root->right,ans);
        int cur_height=1+max(left,right);
        
        if(ans.size()==cur_height){
            ans.push_back(vector<int>());
        }
            ans[cur_height].push_back(root->val);
        return cur_height;
        
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root,ans);
        return ans;

    }
};