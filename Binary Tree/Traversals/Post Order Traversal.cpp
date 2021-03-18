/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */
vector <int> postOrder(Node* root)
{
    vector<int> v;
    stack<Node *> s1;
    // stack<Node *> s2;
    // left right root
    s1.push(root);
    
    while(!s1.empty())
    {
        struct Node *temp = s1.top();
        s1.pop();
        v.push_back(temp->data);
        if(temp->left){
            s1.push(temp->left);
        }
        if(temp->right){
            s1.push(temp->right);
        }
    }
    reverse(v.begin(), v.end());
    
    return v;
    
}
