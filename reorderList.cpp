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
    ListNode* reverse(ListNode* head){
        if(head->next == NULL){
            return head;
        }
        ListNode* temp = reverse(head->next);
        head->next->next = head;
        return temp;
    }
    void reorderList(ListNode* head) {
        if(head->next == NULL || head->next->next == NULL){
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head1 = head;
        ListNode* head2 = reverse(slow->next);
        slow->next->next = NULL;
        slow->next = NULL;
        while(head1 != NULL && head2 != NULL){
            ListNode* temp1 = head1->next;
            head1->next = head2;
            ListNode* temp2 = head2->next;
            head2->next = temp1;
            head1 = temp1;
            head2 = temp2;
        }
        return;
    }
};
