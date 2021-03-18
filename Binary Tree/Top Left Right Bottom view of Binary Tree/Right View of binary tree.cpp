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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if (root == nullptr)
		    return v;
        queue<TreeNode *> q;
        int count = 0;
        q.push(root);
        
        while(!q.empty())
        {
            count = q.size();
            while(count > 0)
            {
                TreeNode *temp = q.front();
                q.pop();
                if(count == 1){
                    v.push_back(temp->val);
                }
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                count--;
            }
        }
        
        return v;
    }
};
