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
    void inorder_traversal(TreeNode* root, int &k, int &i){
        if(!root) return;
        if(k == 0) return;
        inorder_traversal(root->right, k, i);
        k--;
        if(k == 0){
            i = root->val;
            return;
        }
        inorder_traversal(root->left, k, i);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        inorder_traversal(root, k, i);
        return i;
    }
};
