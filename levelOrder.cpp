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
#include <queue>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            vector<int> temp;
            while(q.front() != NULL){
                TreeNode* first = q.front();
                temp.push_back(first->val);
                if(first->left != NULL){
                    q.push(first->left);
                }
                if(first->right != NULL){
                    q.push(first->right);
                }
                q.pop();
            }
            res.push_back(temp);
            q.pop();
            if(q.empty()){
                break;
            }
            q.push(NULL);
        }
        return res;
    }
};