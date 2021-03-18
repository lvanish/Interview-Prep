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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> stk;
        vector<int> v;
        
        if(root == NULL){
            return v;
        }
        
        stk.push(root);
        // root left right
        while(!stk.empty())
        {
            TreeNode *temp = stk.top();
            v.push_back(temp->val);
            stk.pop();
            if(temp->right)
                stk.push(temp->right);
            if(temp->left)
                stk.push(temp->left);
        }
        return v;
    }
};
