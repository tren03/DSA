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

// logic - keep boundary for every node, update that boundry and check for every node
// dry run wiht [5,1,4,null,null,3,6] to understand how right and left conditions update
class Solution {
public:

    bool isValidBST(TreeNode* root) {
        return dfs(root,LLONG_MIN,LLONG_MAX);
        
        
    }
    bool dfs(TreeNode*r , long long int left, long long int right)
    {
        if(!r)
        {
            return true;
        }
        if(!(left< r->val && right> r->val))
        {
            return false;
        }
        bool ri = dfs(r->right,r->val,right); // on the right subtreee we update the left value
        bool le = dfs(r->left,left,r->val);  // on the left subtree we update right value

        return (ri&&le);

    }

};