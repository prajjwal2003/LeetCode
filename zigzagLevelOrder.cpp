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
#include <stack>
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL){
            return res;
        }
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        q.push(root);
        q.push(NULL);
        int level = 0;
        while(!q.empty()){
            vector<int> temp;
            while(q.front() != NULL){
                TreeNode* qfirst = q.front();
                if(level % 2 == 0){
                    temp.push_back(qfirst->val);
                    if(qfirst->left != NULL){
                        q.push(qfirst->left);
                        s.push(qfirst->left);
                    }
                    if(qfirst->right != NULL){
                        q.push(qfirst->right);
                        s.push(qfirst->right);
                    }
                    q.pop();
                }
                else{
                    TreeNode* sfirst = s.top();
                    temp.push_back(sfirst->val);
                    if(qfirst->left != NULL){
                        q.push(qfirst->left);
                    }
                    if(qfirst->right != NULL){
                        q.push(qfirst->right);
                    }
                    q.pop();
                    s.pop();
                }
            }
            res.push_back(temp);
            q.pop();
            if(q.empty()){
                break;
            }
            q.push(NULL);
            level++;
        }
        return res;
    }
};