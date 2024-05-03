Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */


// Logic = do bfs and append the right most node
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // level order bfs - remoove element from que and add its children to the que

        queue<TreeNode*> q;
        vector<int> ans;
        
        if (!root) {
            return ans;
        }
        ans.push_back(root->val);
        q.push(root);
        while (q.size() > 0) {
            vector<TreeNode*> temp; // stores the nodes in 1 level, so we can iterate and add their children to the que
            while (q.size() > 0) { // add all que elements to temp vector
                temp.push_back(q.front());
                q.pop();
            }
            
            for (auto i : temp) { // for every element in temp, add children to the que if they exist
                if (i->left) {
                    q.push(i->left);
                }
                if (i->right) {
                    q.push(i->right);
                }
            
            }
            temp.clear();
            ans.push_back(q.back()->val);
        }
        ans.erase(ans.end()-1); // we do this since last element gets added twice because of the logic

        return ans;
    }
};