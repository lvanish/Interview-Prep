/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* binary_search(vector<int> &nums, int low, int high){
        if(low > high) return NULL;
        int mid = (low + high)/2;
        TreeNode *temp = new TreeNode(nums[mid]);
        temp->left = binary_search(nums, low, mid-1);
        temp->right = binary_search(nums, mid+1, high);
    
        return temp;    
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return binary_search(nums, 0, nums.size()-1);
    }
};
