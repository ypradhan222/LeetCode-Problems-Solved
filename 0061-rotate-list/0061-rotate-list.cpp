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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curr= head;
        ListNode* curr2= head;
        if(head==nullptr){
            return nullptr;
        }
        if(k==0) return head;
        int length=1;
        while(curr->next!=nullptr){
            length++;
            curr=curr->next;
        }
        k=k%length;
        int toSkip= length-k-1;
        while(toSkip>0){
            curr2=curr2->next;
            toSkip--;
        }
        curr->next= head;
        head= curr2->next;
        curr2->next=nullptr;
        return head;


    }
};