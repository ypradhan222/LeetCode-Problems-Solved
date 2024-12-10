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
    ListNode* mergeTwo(ListNode* l1,ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val <= l2->val){
            l1->next = mergeTwo(l1->next,l2);
            return l1;
        }
        else{
            l2->next=mergeTwo(l1,l2->next);
            return l2;
        }
        return nullptr;
    }
    ListNode* partition(int start,int end,vector<ListNode*>& lists){
        if(start>end) return nullptr;
        if(start==end){
            return lists[start];
        }
        int mid=start+(end-start)/2;
        ListNode* L1=partition(start,mid,lists);
        ListNode* L2=partition(mid+1,end,lists);
        return mergeTwo(L1,L2);


    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return nullptr;
        }
        return partition(0,lists.size()-1,lists);
    }
};