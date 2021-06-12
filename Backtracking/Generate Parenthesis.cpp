class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans,"", 0, 0, n);
        return ans;
    }
    void helper(vector<string> &ans, string s, int open, int end, int n){
        if(s.length() == 2*n){
            ans.push_back(s);
            return;
        }
        if(open < n){
            helper(ans, s+"(", open+1, end, n);
        }
        if(end < open){
            helper(ans, s+")", open, end+1, n);
        }
        
    }
};
