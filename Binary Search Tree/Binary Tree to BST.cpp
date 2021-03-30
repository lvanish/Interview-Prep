/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

class Solution{
  public:
    // Return the root of the generated BST
    
    //using INORDER traversal to get data and modify
    void getData(Node *root, vector<int> &v){
        if(!root) return;
        
        getData(root->left, v);
        
        v.push_back(root->data);
        
        getData(root->right, v);
        
    }
    
    void change(Node *root, vector<int> &v, int &i){
        if(!root) return;
        
        change(root->left, v, i);
        
        root->data = v[i++];
        
        change(root->right, v, i);
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> v;
        int i = 0;
        getData(root, v);
        sort(v.begin(), v.end());
        change(root, v, i);
        
        return root;
    }
};
