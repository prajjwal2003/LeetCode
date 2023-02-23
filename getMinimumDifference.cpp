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
    TreeNode* prev = NULL;
    int ans = INT_MAX;
    void helper(TreeNode* root){
        if(root==NULL){
            return;
        }
        helper(root->left);
        if(prev!=NULL){
            ans = min(ans, abs(root->val - prev->val));
        }
        prev = root;
        helper(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        helper(root);
        return ans;
    }
};