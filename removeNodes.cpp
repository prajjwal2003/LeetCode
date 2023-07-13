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
    ListNode* reverse(stack<ListNode*>& s, ListNode* head){
        if(s.empty()){
            return head;
        }
        ListNode* a = s.top();
        s.pop();
        ListNode* b = reverse(s, head);
        b->next = a;
        return a;
    }
    ListNode* removeNodes(ListNode* head) {
        if(head->next == NULL){
            return head;
        }
        stack<ListNode*> s;
        ListNode* temp = head;
        while(temp!=NULL){
            if(s.empty() || temp->val < s.top()->val){
                s.push(temp);
                temp = temp -> next;
                continue;
            }
            while(!s.empty() && temp->val > s.top()->val){
                s.pop();
            }
            s.push(temp);
            temp = temp->next;
        }
        ListNode* newhead = new ListNode();
        ListNode* last = reverse(s, newhead);
        last->next = NULL;
        return newhead->next;
    }
};
