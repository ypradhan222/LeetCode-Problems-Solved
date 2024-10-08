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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){
            return list2;
        }
        if(list2==nullptr){
            return list1;
        }
        ListNode* temp=list1;
        if(list1->val >list2 ->val){
            temp=list2;list2=list2->next;
        }
        else{
            list1=list1->next;
        }
        ListNode* temp2=temp;
        while(list1 && list2){
            if(list1->val <list2->val){
                temp2->next=list1;
                list1=list1->next;
            }
            else{
                temp2->next=list2;
                list2=list2->next;
            }
            temp2=temp2->next;
        }
        if(!list1){
            temp2->next=list2;
        }
        else{
            temp2->next=list1;
        }
        return temp;

    }
};