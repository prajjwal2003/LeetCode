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
    void helper(TreeNode* root, set<int>& s){
        if(root==NULL){
            return;
        }
        s.insert(root->val);
        helper(root->left, s);
        helper(root->right, s);
    }
    bool findTarget(TreeNode* root, int k) {
        set<int> s;
        helper(root, s);
        bool ans = false;
        for(auto it : s){
            s.erase(it);
            if(s.find(k-it) != s.end()){
                ans = true;
                break;
            }
        }
        return ans;
    }
};
