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
    int maxPathSum_Util(TreeNode* root, int &ans){
        if(!root) return 0;
        
        int l = maxPathSum_Util(root->left, ans);
        int r = maxPathSum_Util(root->right, ans);
        
        int max_straight = max(max(l, r) + root->val, root->val);
        int max_caseVal = max(max_straight, root->val + l + r);
        ans = max(ans, max_caseVal);
        
        return max_straight; 
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPathSum_Util(root, ans);
        
        return ans;
    }
};
