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
        while(n--)
        ahead=ahead->next;
        while(ahead->next!=NULL)
        {
            ahead=ahead->next;
            prev=prev->next;
        }
        prev->next=prev->next->next;
        return dummy->next;
    }
};