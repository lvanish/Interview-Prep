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
    int height(TreeNode* root, int &ans){
        if(!root) return 0;
        
        int lh = height(root->left, ans);
        int rh = height(root->right, ans); 
        // ans = max(ans,lh+rh);
        if(lh+rh > ans){
            ans = lh+rh;
        }
        
        return 1+max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        height(root, ans);
        return ans;
    }
};


///////////////////////////////////////////////

According to GFG 
small change in line 20 and 21
  
if(1+lh+rh > ans){
  ans = 1+lh+rh;
}

