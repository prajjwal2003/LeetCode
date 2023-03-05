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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> line;
        priority_queue<long long> box;
        line.push(root);
        line.push(NULL);
        while(!line.empty()){
            long long levelsum = 0;
            while(line.front() != NULL){
                TreeNode* first = line.front();
                levelsum+= first->val;
                if(first->left != NULL){
                    line.push(first->left);
                }
                if(first->right != NULL){
                    line.push(first->right);
                }
                line.pop();
            }
            box.push(levelsum);
            line.pop();
            if(line.empty()){
                break;
            }
            line.push(NULL);
        }
        long long ans = 0;
        if(k>box.size()){
            return -1;
        }
        while(k>1){
            box.pop();
            k--;
        }
        ans = box.top();
        return ans;
    }
};