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
    TreeNode* invertTree(TreeNode* root) {
        
        if(!root)
        {
            return root;
        }

        turn(root);
        return root;

       
        
        
        
    }
    void turn(TreeNode* r)
    {
        //we recursively call this function for all nodes of the tree
        if(r==NULL)
        {
            return;
        }
        swap(r->left,r->right);
        turn(r->left);
        turn(r->right);
    }  
};

