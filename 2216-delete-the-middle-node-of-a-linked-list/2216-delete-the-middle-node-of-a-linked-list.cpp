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
    ListNode* deleteMiddle(ListNode* head) {
        
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* preslow=new ListNode(0);
        if(!head || !head->next) return nullptr;
        while(fast && fast->next){
            preslow=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        preslow->next=slow->next;
        return head;

    }
};