/* The structure of a BST Node is as follows:

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Return the root of the modified BST after deleting the node with value X

Node *Util(Node *root){
    Node *temp = root->left;
    if(temp->right){
        while(temp->right){
            temp = temp->right;
        }
    }
    return temp;
}

Node *deleteNode(Node *root,  int X)
{
    if(!root) return NULL;
    if(root->data == X){
        //0 child
        if(!root->left and !root->right){
            return NULL;
        }
        //2 childs
        if(root->left and root->right){
            Node *temp = Util(root);
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
            return root;
        }
        //1 child
        if(root->left){
            return root->left;
        }
        if(root->right){
            return root->right;
        }
    }
    if(X < root->data){
        root->left = deleteNode(root->left, X);
    }
    if(X > root->data){
        root->right = deleteNode(root->right, X);
    }
    return root;
}
