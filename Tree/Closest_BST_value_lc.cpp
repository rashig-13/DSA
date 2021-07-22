Given the root of a binary search tree, a target value, and an integer k, return the k values in the BST that are closest to the target. You may return the answer in any order.

You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
//version of BST for finding k min elements in array
class Solution {
public:
    void solve(TreeNode* root,vector<int> &v){
    if(root==NULL) return;
        solve(root->left,v);
        v.push_back(root->val);
        solve(root->right,v);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> v,ans;
        solve(root,v);
        
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<v.size();i++){
            double tmp=(double)v[i]-target;
            pq.push({abs(tmp),v[i]});
            if(pq.size()>k) pq.pop();
        }
        while(k--) {
            int x = pq.top().second;
            pq.pop();
            ans.push_back(x);
            }
        return ans;
    }
};
//no need to find inorder traversal, just iterate in the tree and use max heap to store
// k min closest values.