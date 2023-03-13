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
 #include <queue>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(auto i : lists){
            if(i != NULL){
                pq.push({i->val, i});
            }
        }
        ListNode* temp = new ListNode(0);
        ListNode* head = temp;
        while(!pq.empty()){
            pair topper = pq.top();
            pq.pop();
            ListNode* newNode = new ListNode(topper.first);
            temp->next = newNode;
            temp = temp->next;
            if(topper.second->next != NULL){
                ListNode* nextNode = topper.second->next;
                pq.push({nextNode->val, nextNode});
            }
        }
        return head->next;
    }
};