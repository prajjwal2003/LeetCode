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
    TreeNode* temp= new TreeNode(0);
public:
    
    void helper(TreeNode* root){
        if(root==NULL){
            return;
        }
        helper(root->left);
        root->left= NULL;
        temp->right= root;
        temp= root;
        helper(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ans= temp;
        helper(root);
        return ans->right;
    }
};