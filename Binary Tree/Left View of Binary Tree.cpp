/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

vector<int> leftView(Node *root)
{
    vector<int> v;
    if (root == nullptr)
	    return v;
    queue<Node *> q;
    int count = 0;
    q.push(root);
    
    while(!q.empty())
    {
        count = q.size();
        int queueCount = q.size();
        while(count > 0)
        {
            Node *temp = q.front();
            q.pop();
            if(count == queueCount){
                v.push_back(temp->data);
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
