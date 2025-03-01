/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        if(!head1 && !head2) return nullptr;
	unordered_map<ListNode*,int> mp; //key-node,value-val
	ListNode* temp=head1;
	while(temp){
		mp[temp]=temp->val;
		temp=temp->next;
	}
	temp=head2;
	while(temp){
		if(mp.find(temp)!=mp.end()){
			return temp;
		}
		temp=temp->next;
	}
	return nullptr;
    }
};