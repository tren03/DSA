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
    int goodNodes(TreeNode* r) {
        int ans = dfs(r,r->val);
        return ans;
    }
    int dfs(TreeNode* root,int v)
    {
        if(!root)
        {
            return 0;
        }
        int count = root->val >= v ? 1 : 0; 
        v = max(v,root->val);
        int l = dfs(root->left,v);
        int r = dfs(root->right,v);

        return l+r+count;

    }
};