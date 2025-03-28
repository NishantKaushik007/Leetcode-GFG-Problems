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
        ListNode* dummy=new ListNode(),*ahead=dummy,*prev=dummy;
        dummy->next=head;
        for(int i=0;i<n;i++)
        ahead=ahead->next;
        while(ahead!=NULL&&ahead->next!=NULL){
            prev=prev->next;
            ahead=ahead->next;
        }
        prev->next=prev->next->next;
        return dummy->next;
    }
};