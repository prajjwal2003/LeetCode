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
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = new ListNode();
        ListNode* p1 = temp;
        ListNode* p2 = temp;
        temp->next = head;
        while(k>0){
            p1 = p1->next;
            k--;
        }
        ListNode* first = p1;
        while(p1 != NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode* second = p2;
        int var = first->val;
        first->val = second->val;
        second->val = var;
        return temp->next;
    }
};