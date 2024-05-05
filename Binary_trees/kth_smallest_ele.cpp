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
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int count = 0;
        dfs(root,k,count,ans);
        return ans;


    }
    void dfs(TreeNode *r, int k,int &count, int &ans)
    {
        if(!r)
        {
            return;
        }
        dfs(r->left,k,count,ans);
        count++;
        if(count == k)
        {
            ans = r->val;
        }
        dfs(r->right,k,count,ans);
        

    }
};