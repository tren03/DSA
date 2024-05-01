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

//LOGIC : traverse every node recursively and check if abs(left - right) sub tree height > 1, if yes make flag false and return flag in the first function 
class Solution {
public:
    bool flag = true;
    bool isBalanced(TreeNode* root) {
        if(!root)
        {
            return true;
        }
        dfs(root);
        return flag;
        
    }
    int depth(TreeNode *r)
    {
        if(!r)
        {
            return 0;
        }
        return 1+max(depth(r->left),depth(r->right));
    }
    void dfs(TreeNode *r)
    {
        if(!r)
        {
            return;
        }
        int left = depth(r->left);
        int right = depth(r->right);
        if(abs(left-right)>1)
        {
            flag = false;
            return;
        }
        dfs(r->left);
        dfs(r->right);
    }
};


//NEED TO UNDERSTAND O(N)
