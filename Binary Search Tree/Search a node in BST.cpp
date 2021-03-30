/* Node structure 

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

/*You are required to complete this method*/
bool search(Node* root, int x)
{
    if(!root) return false;
    if(root->data == x) return true;
    
    if(x < root->data) return search(root->left, x);
    if(x > root->data) return search(root->right, x);
}



// ******************************************************//
//         ITERATIVE

TreeNode* searchBST(TreeNode* root, int val) {
    while (root != nullptr && root->val != val) {
      root = (root->val > val) ? root->left : root->right;
    }
    return root;
}
