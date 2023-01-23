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
    int result = INT_MIN;

    int helper(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int ansreturn = root->val;
        int ansnow = root->val;
        int lefty = helper(root->left);
        int righty = helper(root->right);
        ansreturn= max(ansreturn, max(ansreturn+lefty, ansreturn+righty));
        ansnow= max(ansreturn, ansnow+lefty+righty);

        if(ansnow > result){
            result = ansnow;
        }
        return ansreturn;
    }

    int maxPathSum(TreeNode* root) {
        helper(root);
        return result;
    }
};