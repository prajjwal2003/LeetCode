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
    vector<int> depthsum;
    void helper(TreeNode* root, int depth){
        if(root==NULL){
            return;
        }
        if(depth == depthsum.size()){
            depthsum.push_back(root->val);
        }
        else{
            depthsum[depth]+= root->val;
        }
        helper(root->left, depth+1);
        helper(root->right, depth+1);
    }
    int maxLevelSum(TreeNode* root) {
        helper(root, 0);
        int ans = INT_MIN;
        int res = -1;
        for(int i=0; i<depthsum.size(); i++){
            if(depthsum[i] > ans){
                ans = depthsum[i];
                res = i+1;
            }
        }
        return res;
    }
};