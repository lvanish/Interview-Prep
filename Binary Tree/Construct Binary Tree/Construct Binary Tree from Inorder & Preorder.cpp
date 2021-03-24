/*
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
int search(int in[], int k, int n){
    for(int i = 0; i<n; i++){
        if(in[i] == k){
            return i;
        }
    }
}

Node* buildTree(int in[],int pre[], int n)
{
    if(n == 0) return NULL;
    
    Node *temp = new Node(pre[0]);
    int mid = search(in, pre[0], n);
    
    temp->left = buildTree(in, pre+1, mid);
    temp->right = buildTree(in+mid+1, pre+mid+1, n-mid-1);
    
    return temp;
    
}
