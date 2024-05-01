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


//RECURSIVE DFS
class Solution {
public:
    vector<int> ans;
    int maxDepth(TreeNode* root) {

        if(!root)
        {
            return 0;
        }
        return 1+max(maxDepth(root->left),maxDepth(root->right));


        
        
    }

};


//LEVEL ORDER BFS
class Solution {
public:
    vector<int> ans;
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root)
        {
            return 0;
        }
        q.push(root);
        int level = 0;
        
        while(q.size()>0)
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* temp = q.front();
                if(temp->left!=NULL)
                {
                    q.push(temp->left);

                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);

                }
                q.pop();
                
            }      
            level+=1;  
            
        }
        return level;


        
        
    }

};

//ITERATIVE DFS (PREORDER USED HERE AS IT IS THE EASIEST TO IMPLEMENT) -> POP STACK AND PUSH RIGHT AND LEFT CHILD OF ELEMENT
class Solution {
public:
    vector<int> ans;
    int maxDepth(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        stack<pair<TreeNode*, int>> st;
        int max_level = 1;
        st.push({root,1});
        while(st.size()>0)
        {
            pair<TreeNode*,int> temp = st.top();
            st.pop();
            if(temp.first->right != NULL)
            {
                st.push({temp.first->right,temp.second+1});
                max_level = max(max_level,temp.second+1);
            }
            if(temp.first->left != NULL)
            {
                st.push({temp.first->left,temp.second+1});
                max_level = max(max_level,temp.second+1);
            }

        }
        return max_level;        
        
    }

};