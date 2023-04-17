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
    void finddepth(TreeNode* root, int depth){
        if(root == NULL){
            return;
        }
        if(depth == depthsum.size()){
            depthsum.push_back(root->val);
        }
        else{
            depthsum[depth]+= root->val;
        }
        finddepth(root->left, depth+1);
        finddepth(root->right, depth+1);
    }

    void fillvalues(TreeNode* root, int depth){
        if(root==NULL){
            return;
        }
        int temp = 0;
        if(root->left){
            temp+= root->left->val;
        }
        if(root->right){
            temp+= root->right->val;
        }
        if(root->left){
            root->left->val = depthsum[depth+1] - temp;
        }
        if(root->right){
            root->right->val = depthsum[depth+1] - temp;
        }
        fillvalues(root->left, depth+1);
        fillvalues(root->right, depth+1);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        root->val = 0;
        finddepth(root, 0);
        fillvalues(root, 0);
        return root;
    }
};