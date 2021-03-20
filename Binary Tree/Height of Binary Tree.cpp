/*
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

// Recursive way 

class Solution{
    public:
    int height(struct Node* node){
        if(!node) return 0;
      
        return 1+max(height(node->left), height(node->right));
    }
};

// Iterative way 

class Solution{
    public:
    int height(struct Node* node){
        if(!node) return 0;
        int h = 0;
        queue<Node *> q;
        q.push(node);
        
        while(!q.empty()){
            
            int k = q.size();
            
            while(k--){
                Node *temp = q.front();
                q.pop();
                
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            h++;
        }
        
        return h;
    }
};
