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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr=dummy ;
        ListNode* prev=dummy;
        // if(head==nullptr || head->next == nullptr){
        //     return nullptr;
        // }
       for(int i=0;i<=n;i++){
        curr=curr->next;
       }
       while(curr!=nullptr){
        curr= curr->next;
        prev=prev->next;
       }
       prev->next=prev->next->next;
        return dummy->next;
    }
};