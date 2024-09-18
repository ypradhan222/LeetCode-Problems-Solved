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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* mid = middleOfList(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next=nullptr;
        left = sortList(left);
        right = sortList(right);
        ListNode* mergedList = merge(left,right);
        return mergedList;
    }
    ListNode* middleOfList(ListNode* head){
        ListNode* slow= head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right){
        if(left==nullptr) return right;
        if(right==nullptr) return left;
        ListNode* result = new ListNode(-1);
        ListNode* ptr = result;
        while(left && right){
            if(left->val <= right->val){
                ptr->next = left;
                ptr = left;
                left=left->next;
            }
            else{
                ptr->next = right;
                ptr = right;
                right= right->next;
            }
        }
        if(left){
            ptr->next = left;
        }
        if(right){
            ptr->next = right;
        }
        return result->next;
    }
};