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
 # include<queue>
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        bool ans = true;
        bool found = false;
        queue<TreeNode*> box;
        box.push(root);
        box.push(NULL);
        while(!box.empty()){
            TreeNode* topper = box.front();
            box.pop();
            if(topper != NULL && topper->left == NULL && found == false){
                found = true;
            }
            else if(topper!=NULL && topper->left != NULL){
                if(found == false){
                    box.push(topper->left);
                }
                else{
                    ans = false;
                    break;
                }
            }
            if(topper!=NULL && topper->right == NULL && found == false){
                found = true;
            }
            else if(topper!=NULL && topper->right != NULL){
                if(found == false){
                    box.push(topper->right);
                }
                else{
                    ans = false;
                    break;
                }
            }
            if(box.front() == NULL){
                box.pop();
            }
            if(box.empty()){
                break;
            }
            box.push(NULL);
        }
        return ans;
    }
};