/* A binary tree Node
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

class Solution
{
    public:
    vector<int> levelOrder(Node* node)
    {
        vector<int> v;
        queue<Node *> q;
        q.push(node);
        
        while(!q.empty()){
            Node *temp =  q.front();
            v.push_back(temp->data);
            q.pop();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        
        return v;
    }
};
