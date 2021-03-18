/* A binary tree node has data, pointer to left child
   and a pointer to right child 
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

// root: root node of the tree
vector<int> verticalOrder(Node *root)
{
    vector<int> ans;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    map<int, vector<int> > m;
    
    while(!q.empty()){
        
        pair<Node *, int> p = q.front();
        q.pop();
        Node *temp = p.first;
        int hd = p.second;
        m[hd].push_back(temp->data);
        
        if(temp->left){
            q.push(make_pair(temp->left, hd-1));
        }
        if(temp->right){
            q.push(make_pair(temp->right, hd+1));
        }
        
    }
    for(auto x: m)
    {
        for(auto i: x.second){
            ans.push_back(i);
        }
    }
    
    return ans;
}
