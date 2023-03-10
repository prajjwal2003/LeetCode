/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* nodehead;
    int len;
public:
    Solution(ListNode* head) {
        nodehead = head;
        len = 0;
        ListNode* temp = nodehead;
        while(temp){
            len++;
            temp = temp->next;
        }
    }
    
    int getRandom() {
        int index = rand()%len;
        ListNode* temp = nodehead;
        for(int i=0; i<index; i++){
            temp = temp->next;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */