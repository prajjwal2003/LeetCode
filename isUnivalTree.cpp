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
    bool helper(TreeNode* root, int value){
        if(root==NULL){
            return true;
        }
        bool lefty = helper(root->left, value);
        bool righty = helper(root->right, value);
        if(lefty && righty && root->val == value){
            return true;
        }
        else{
            return false;
        }
    }
    bool isUnivalTree(TreeNode* root) {
        int value = root->val;
        return helper(root, value);
    }
};