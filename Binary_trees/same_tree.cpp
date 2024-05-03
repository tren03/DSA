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

// recursively traverse along both the trees and check if they are equal
class Solution {
public:
    bool flag = true;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
        {
            return true;
        }
        if(!p || !q)
        {
            return false;
        }
        if(p->val != q-> val)
        {
            return false;
        }

        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);

        if(left == true && right == true)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    
    
    
};