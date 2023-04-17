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
    int deep = 1;
    void find(TreeNode* root, int depth){
        if(root==NULL){
            return;
        }
        if(depth > deep){
            deep = depth;
        }
        find(root->left, depth+1);
        find(root->right, depth+1);
    }
    void helper(vector<int>& ans, TreeNode* root, int depth){
        if(root==NULL){
            return;
        }
        if(root->val > ans[depth]){
            ans[depth] = root->val;
        }
        helper(ans, root->left, depth+1);
        helper(ans, root->right, depth+1);
    }
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL){
            vector<int> ans;
            return ans;
        }
        find(root, 1);
        vector<int> ans(deep, INT_MIN);
        helper(ans, root, 0);
        return ans;
    }
};