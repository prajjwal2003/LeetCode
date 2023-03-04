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
 #include <unordered_map>
class Solution {
public:
    unordered_map<string, int> box;
    string helper(TreeNode* root, vector<TreeNode*>& res){
        if(root==NULL){
            return "#";
        }
        string s = to_string(root->val) + ',' + helper(root->left, res) + ',' + helper(root->right, res);
        box[s]++;
        if(box[s] == 2){
            res.push_back(root);
        }
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        helper(root, res);
        return res;
    }
};