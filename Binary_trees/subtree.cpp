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


// my first logic - we know how to check if 2 trees are equal using recursive dfs, so we iterate over one tree and check for every node if its left and right subtree are equal to the subtree we need to check it with
// this is brute force
// TC - O(S*T) 
class Solution {
public:
    bool flag = false;
    bool isSubtree(TreeNode* r, TreeNode* s) {
        dfs(r,s);
        return flag;



        
        

        
    }
    bool issame(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot)
        {
            return true;
        }
        if(!root || !subRoot)
        {
            return false;
        }
        if(root->val != subRoot->val)
        {
            return false;
        }
        
        bool left = issame(root->left,subRoot->left);
        bool right = issame(root->right,subRoot->right);

        if(left == true && right == true)
        {
            return true;
        }
        else
        {
            return false;
            
        }



        
        

        
    }
    void dfs(TreeNode* p1,TreeNode* q1)
    {
        if(issame(p1,q1))
        {
            flag = true;
        }
        if(!p1)
        {
            return;
        }
        dfs(p1->left,q1);
        dfs(p1->right,q1);
    }

    
};

//diff approach with only 2 functions
class Solution {
public:
  
    bool isSubtree(TreeNode* r, TreeNode* s) {
        if(!s)
        {
            return true;
        }
        if(!r)
        {
            return false;
        }

        if(issame(r,s))
        {
            return true;
        }
        
        bool l1 = isSubtree(r->left,s);
        bool r1 = isSubtree(r->right,s);

        return(l1 || r1);
        
    }
    bool issame(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot)
        {
            return true;
        }
        if(!root || !subRoot)
        {
            return false;
        }
        if(root->val != subRoot->val)
        {
            return false;
        }
        
        bool left = issame(root->left,subRoot->left);
        bool right = issame(root->right,subRoot->right);

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