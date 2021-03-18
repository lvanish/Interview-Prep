/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

// Method that returns the bottom view.
vector <int> bottomView(Node *root)
{
    vector<int> ans;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root,0));
    map<int, int> m;
    
    while(!q.empty()){
        
        pair<Node*, int> p = q.front();
        q.pop();
        Node *temp = p.first;
        int hd = p.second;
        
        
        m[hd] = temp->data;
            
        if(temp->left){
            q.push(make_pair(temp->left, hd-1));
        }
        if(temp->right){
            q.push(make_pair(temp->right, hd+1));
        }
        
    }
    for(auto x: m){
        ans.push_back(x.second);
    }
    
    return ans;
}
