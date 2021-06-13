//Iterative Approach
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            TreeNode *temp = curr->left;
            curr->left = fr->right;
            curr->right = temp;
            
            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr) q.push(curr->right);
        }
        return root;
    }
};


//Recursive Approach
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return 0;
    
        TreeNode* temp;
        invertTree(root->left);
        invertTree(root->right);
        temp=root->left;
        root->left=root->right;
        root->right=temp;
    
        return root;
    }
};
