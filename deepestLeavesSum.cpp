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
    int maxi = INT_MIN;
    int sum = 0;
    void helper(TreeNode* root, int depth){
        if(root == NULL){
            return;
        }
        maxi = max(maxi, depth);
        helper(root->left, depth+1);
        helper(root->right, depth+1);
    }
    void helper2(TreeNode* root, int depth){
        if(root==NULL){
            return;
        }
        if(depth == maxi){
            sum+= root->val;
        }
        helper2(root->left, depth+1);
        helper2(root->right, depth+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        helper(root, 0);
        helper2(root, 0);
        return sum;
    }
};
