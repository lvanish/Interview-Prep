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
    bool ans = false;
    
    int check_balanced(TreeNode* root){
        if(!root) return 0;
        if(!ans) return 0;
        
        int leftSubtree = check_balanced(root->left);
        int rightSubtree = check_balanced(root->right);
        
        if(abs(leftSubtree - rightSubtree)>1){
            ans = false;
        }
        return 1 + max(leftSubtree, rightSubtree);
    }
    
    bool isBalanced(TreeNode* root) {
        ans = true;
        int temp = check_balanced(root);
        return ans;
    }
};
