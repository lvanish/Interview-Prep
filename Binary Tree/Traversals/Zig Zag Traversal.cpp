/*Structure of the node of the binary tree is as
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

// return a vector containing the zig zag level order traversal of the given tree
vector <int> zigZagTraversal(Node* root)
{
	// Code here
	 
	 vector<int> ans;
	 stack<Node *>s1;
	 stack<Node *>s2;
	 s1.push(root);
	 
	 while(!s1.empty() or !s2.empty()){
	     
	     while(!s1.empty()){
	         
	         Node *temp = s1.top();
	         s1.pop();
	         ans.push_back(temp->data);
	         
	         if(temp->left){
	             s2.push(temp->left);
	         }
	         
	         if(temp->right){
	             s2.push(temp->right);
	         }
	         
	     }
	     
	     while(!s2.empty()){
	         
	         Node *temp = s2.top();
	         s2.pop();
	         ans.push_back(temp->data);
	         
	         if(temp->right){
	             s1.push(temp->right);
	         }
	         
	         if(temp->left){
	             s1.push(temp->left);
	         }
	        
	     }
	     
	 }
	 
	 return ans;
	 
}
