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
    int carry=0;
    // ListNode* result = new ListNode(0);
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=carry;
        if(l1==nullptr && l2== nullptr && carry==0) return nullptr;
        if(l1!=nullptr) sum+=l1->val;
        if(l2!=nullptr) sum+=l2->val;
       
        carry = sum/10;
        ListNode* result= new ListNode(sum%10);
        ListNode* nextL1 = nullptr;
        ListNode* nextL2 = nullptr;
        if (l1 != nullptr) {
            nextL1 = l1->next;
        }
        if (l2 != nullptr) {
            nextL2 = l2->next;
        }
        result->next = addTwoNumbers(nextL1, nextL2);
        return result;
    }
    
};