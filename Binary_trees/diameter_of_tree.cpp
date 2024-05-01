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


//LOGIC = max diameter for a node would be height of left sub-tree + height of right sub-tree
// so we recursively travel every node and caluclate height of left and right subtree and keep a variable to hold the maximum value
class Solution {
public:
    int res=0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        dfs(root);
        return res;




    }
    int max_depth(TreeNode*r)
    {
        if(!r)
        {
            return 0;
        }
        return 1+max(max_depth(r->left),max_depth(r->right));
        
    }
    void dfs(TreeNode *r)
    {
        if(!r)
        {
            return;
        }
        int left = max_depth(r->left);
        int right = max_depth(r->right);
        res = max(res,left+right);
        dfs(r->left);
        dfs(r->right);

        
    }

};

